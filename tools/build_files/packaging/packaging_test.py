#!/usr/bin/env python3

import argparse
import subprocess
from pathlib import Path
import string
import re
import os
from datetime import datetime, timezone
import shutil
import pwd
import platform

_containers = {
    "debian": "docker.io/debian:sid",
    "gentoo": "docker.io/gentoo/stage3:latest",
    "fedora": "docker.io/fedora:latest",
    "arch": "docker.io/archlinux:latest"
}

# debian

_debian_control = \
    """\
Source: robotraconteur-companion
Section: contrib/misc
Priority: optional
Maintainer: John Wason <wason@wasontech.com>
Build-Depends: cmake (>=3.5.1),
               debhelper (>=9),
               libboost-all-dev (>=1.58.0),
               libssl-dev (>=1),
               librobotraconteur-dev,
               libgtest-dev,
               libyaml-cpp-dev,
               libeigen3-dev,
               libopencv-dev
Standards-Version: 4.7.0
Homepage: https://github.com/robotraconteur/robotraconteur_companion

Package: librobotraconteur-companion0.4
Architecture: any
Multi-Arch: same
Section: contrib/libs
Depends: ${misc:Depends}, ${shlibs:Depends}
Pre-Depends: ${misc:Pre-Depends}
Description: Companion C++ library for Robot Raconteur
 .
 This package provides run-time library of robotraconteur-companion.

Package: librobotraconteur-companion-dev
Architecture: any
Section: contrib/libdevel
Depends: librobotraconteur-companion0.4, librobotraconteur-dev,
  ${misc:Depends}, ${shlibs:Depends}, libboost-all-dev (>=1.58.0),
  libyaml-cpp-dev, libeigen3-dev, libopencv-dev
Description: Companion C++ library for Robot Raconteur
 .
 This package provides development files of robotraconteur-companion.
"""

_debian_copyright = \
    """\
Format: https://www.debian.org/doc/packaging-manuals/copyright-format/1.0/
Upstream-Name: robotraconteur
Source: http://github.com/robotraconteur/robotraconteur

Files: *
Copyright: 2018 John Wason (wason@wasontech.com)
License: Apache
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

Files: debian/*
Copyright: 2018 John Wason <wason@wasontech.com>
License: GPL-2+
 This package is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 .
 This package is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 .
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <https://www.gnu.org/licenses/>
 .
 On Debian systems, the complete text of the GNU General
 Public License version 2 can be found in "/usr/share/common-licenses/GPL-2".
"""

_debian_librobotraconteur_companion_dev_install = \
    """\
/usr/include/RobotRaconteurCompanion/*
/usr/lib/*/*.so
/usr/lib/*/cmake/
/usr/share/robotraconteur/*
"""

_debian_librobotraconteur_companion0_4_install = \
    """\
/usr/lib/*/*.so.*
"""

_debian_changelog = \
    """
robotraconteur-companion (${TEMPLATE_VERSION}-${TEMPLATE_PACKAGE_VERSION}${TEMPLATE_DEBIAN_VERSION_SUFFIX}) ${TEMPLATE_DEBIAN_DIST}; urgency=medium

  * Test Build

 -- John Wason <wason@wasontech.com>  ${TEMPLATE_TIMESTAMP}
"""

_debian_rules = \
    """\
#!/usr/bin/make -f
# See debhelper(7) (uncomment to enable)
# output every command that modifies files on the build system.
#export DH_VERBOSE = 1

export DH_OPTIONS

include /usr/share/dpkg/architecture.mk

CPPFLAGS :=$(shell dpkg-buildflags --get CPPFLAGS)
CFLAGS   :=$(shell dpkg-buildflags --get CFLAGS)
CXXFLAGS :=$(shell dpkg-buildflags --get CXXFLAGS)
LDFLAGS  :=$(shell dpkg-buildflags --get LDFLAGS)

export DEB_HOST_MULTIARCH CPPFLAGS CFLAGS CXXFLAGS LDFLAGS

COMMON_CMAKE_FLAGS = \\
    -DCMAKE_INSTALL_PREFIX=/usr \\
	-DLIB_INSTALL_DIR=/usr/lib/$(DEB_HOST_MULTIARCH) \\
    -DCMAKE_LIBRARY_ARCHITECTURE="$(DEB_HOST_MULTIARCH)" \\
    -DBUILD_TESTING=$(if $(filter nocheck,$(DEB_BUILD_OPTIONS)),OFF,ON) \\
    -DBUILD_DOCUMENTATION=OFF \\
    -DBUILD_SHARED_LIBS=ON \\
    -DROBOTRACONTEUR_COMPANION_SOVERSION_MAJOR_ONLY=ON \\
    -DCMAKE_SKIP_RPATH=ON \\
    -DCMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST

%:
	dh $@ --parallel

override_dh_auto_configure:
	dh_auto_configure -- $(COMMON_CMAKE_FLAGS)

override_dh_auto_test:
	LD_LIBRARY_PATH=$(CURDIR)/obj-$(DEB_HOST_GNU_TYPE):$$LD_LIBRARY_PATH dh_auto_test --no-parallel

"""


# gentoo

_gentoo_ebuild = \
    """
EAPI=8

inherit cmake

DESCRIPTION="Robot Raconteur C++ Companion Library"
HOMEPAGE="https://github.com/robotraconteur/robotraconteur_companion"
SRC_URI="${TEMPLATE_SRC_URI}"

LICENSE="Apache-2.0"
SLOT="0"
KEYWORDS="amd64 ~x86 ~arm arm64"
IUSE="python"

DEPEND="dev-libs/boost
    dev-libs/openssl
    dev-build/cmake
    dev-cpp/yaml-cpp
    dev-cpp/eigen
    dev-cpp/robotraconteur
"
RDEPEND="$${DEPEND}"

S="$${WORKDIR}/RobotRaconteurCompanion-$${PV}-Source"

src_configure() {
local mycmakeargs=(
        -DCMAKE_SKIP_RPATH=ON
        -DBUILD_TESTING=OFF
        -DBUILD_DOCUMENTATION=OFF
        -DROBOTRACONTEUR_COMPANION_SOVERSION_MAJOR_ONLY=ON
    )
    cmake_src_configure
}

src_compile() {
    cmake_src_compile
}

src_install() {
    cmake_src_install
}

${TEMPLATE_LOCAL_EXTRAS}

"""

_gentoo_github_src_uri = "https://github.com/robotraconteur/robotraconteur_companion/releases/download/v${PV}/RobotRaconteurCompanion-${PV}-Source.tar.gz"

_gentoo_local_src = \
    """
# Remove for real use
src_unpack() {
    cp -r ${TEMPLATE_LOCAL_SRC_DIR} $${S} || die

}
"""

_gentoo_metadata = \
    """
<?xml version="1.0"?>
<pkgmetadata>
  <maintainer type="person">
    <name>John Wason</name>
    <email>wason@wasontech.com</email>
  </maintainer>
  <upstream>
    <remote-id type="github">robotraconteur/robotraconteur_companion</remote-id>
    <bugs-to>https://github.com/robotraconteur/robotraconteur_companion/issues</bugs-to>
    <doc>http://robotraconteur.com</doc>
  </upstream>
  <longdescription lang="en">
    Robot Raconteur C++ companion library. See http://robotraconteur.com for documentation.
  </longdescription>
</pkgmetadata>

"""

# rpm
_rpm_spec = \
    """\
Name:           robotraconteur-companion
Version:        ${TEMPLATE_VERSION}
Release:        ${TEMPLATE_PACKAGE_VERSION}%{?dist}
Summary:        Robot Raconteur C++ Companion Library

License:        Apache-2.0
URL:            https://github.com/robotraconteur/robotraconteur_companion
Source0:        RobotRaconteurCompanion-%{version}-Source.tar.gz

BuildRequires:  cmake >= 3.5.1
BuildRequires:  boost-devel >= 1.58.0
BuildRequires:  openssl-devel
BuildRequires:  zlib-devel
BuildRequires:  gtest-devel
BuildRequires:  g++
BuildRequires:  gcc
BuildRequires:  make
BuildRequires:  yaml-cpp-devel
BuildRequires:  eigen3-devel
BuildRequires:  librobotraconteur-devel

%description
Robot Raconteur C++ companion library.

%package -n librobotraconteur-companion0.4
Summary:        Robot Raconteur C++ companion runtime library.

%description -n librobotraconteur-companion0.4
Robot Raconteur C++ companion runtime library. This package provides the run-time library of robotraconteur-companion.

%package -n librobotraconteur-companion-devel
Summary:        Robot Raconteur C++ companion development files
Requires:       librobotraconteur-companion0.4, librobotraconteur-devel, boost-devel >= 1.58.0, cmake, g++, gcc, make, openssl-devel, yaml-cpp-devel, eigen3-devel, opencv-devel

%description -n librobotraconteur-companion-devel
Robot Raconteur C++ companion development files. This package provides the development files of robotraconteur-companion.

%prep
%autosetup -n RobotRaconteurCompanion-%{version}-Source

%build
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=%{_prefix} \\
         -DBUILD_DOCUMENTATION=OFF \\
         -DBUILD_SHARED_LIBS=ON \\
         -DROBOTRACONTEUR_COMPANION_SOVERSION_MAJOR_ONLY=ON \\
         -DCMAKE_SKIP_RPATH=ON \\
         -DBUILD_TESTING=OFF

make %{?_smp_mflags}

%install
cd build
make install DESTDIR=%{buildroot}

# Move files to match Fedora packaging guidelines if needed

%files -n librobotraconteur-companion0.4
%license LICENSE.txt
%{_libdir}/libRobotRaconteurCompanion.so.*

%files -n librobotraconteur-companion-devel
%license LICENSE.txt
%{_includedir}/RobotRaconteurCompanion/
%{_libdir}/libRobotRaconteurCompanion.so
%{_libdir}/cmake/
%{_datadir}/robotraconteur/

%changelog
* ${TIMESTAMP} John Wason <wason@wasontech.com> - ${TEMPLATE_VERSION}-${TEMPLATE_PACKAGE_VERSION}
- Test RPM Build
"""

# pacman
_pacman_srcinfo = \
    """\
pkgbase = robotraconteur-companion
	pkgdesc = Robot Raconteur C++ Companion Library
	pkgver = %{TEMPLATE_VERSION}
	pkgrel = %{TEMPLATE_PACKAGE_VERSION}
	url = https://github.com/robotraconteur/robotraconteur_companion
	arch = x86_64
    arch = aarch64
	license = Apache-2.0
	makedepends = cmake>=3.5.1
	makedepends = boost>=1.58.0
	makedepends = openssl
	makedepends = zlib
	makedepends = gtest
	makedepends = base-devel
    makedepends = yaml-cpp
    makedepends = eigen
	source = RobotRaconteurCompanion-${pkgver}-Source.tar.gz
	sha256sums = SKIP

pkgname = librobotraconteur-companion0.4
	pkgdesc = Robot Raconteur C++ companion runtime library

pkgname = librobotraconteur-companion-devel
	pkgdesc = Robot Raconteur development files
	depends = librobotraconteur-companion0.4
    depends = librobotraconteur-devel
	depends = boost>=1.58.0
	depends = cmake
	depends = base-devel
	depends = openssl
    depengs = yaml-cpp
    depends = eigen
    depends = opencv
"""

_pacman_pkgbuild =\
    """\
# Maintainer: John Wason <wason@wasontech.com>
pkgbase=robotraconteur-companion
pkgname=(librobotraconteur-companion0.4 librobotraconteur-companion-devel)
pkgver=%{TEMPLATE_VERSION}
pkgrel=%{TEMPLATE_PACKAGE_VERSION}
pkgdesc="Robot Raconteur C++ Companion Library"
arch=('x86_64' 'aarch64')
url="https://github.com/robotraconteur/robotraconteur_companion"
license=('Apache-2.0')
source=("RobotRaconteurCompanion-${pkgver}-Source.tar.gz")
sha256sums=('SKIP') # Replace with actual sha256sum for release
makedepends=(
  'cmake>=3.5.1'
  'boost>=1.58.0'
  'openssl'
  'zlib'
  'gtest'
  'base-devel'
  'yaml-cpp'
  'eigen'
  'librobotraconteur-devel'
  'robotraconteurgen'
)
_libdepends=()

prepare() {
  cd "RobotRaconteurCompanion-${pkgver}-Source"
  rm -rf build
  mkdir build
}

build() {
  cd "RobotRaconteurCompanion-${pkgver}-Source/build"
  cmake .. \\
    -DCMAKE_INSTALL_PREFIX=/usr \\
    -DCMAKE_BUILD_TYPE=Release \\
    -DBUILD_DOCUMENTATION=OFF \\
    -DBUILD_SHARED_LIBS=ON \\
    -DROBOTRACONTEUR_COMPANION_SOVERSION_MAJOR_ONLY=ON \\
    -DCMAKE_SKIP_RPATH=ON \\
    -DBUILD_TESTING=OFF
  cmake --build . -- -j$(nproc)
}

package_librobotraconteur-companion0.4() {
  pkgdesc="Robot Raconteur C++ companion runtime library"
  depends=("${_libdepends[@]}")
  cd "$srcdir/RobotRaconteurCompanion-${pkgver}-Source/build"
  DESTDIR="$pkgdir" cmake --install .
  # Prune unrelated files
  rm -rf "$pkgdir/usr/include" "$pkgdir/usr/lib/cmake" "$pkgdir/usr/bin" "$pkgdir/usr/share" "$pkgdir/usr/lib/pkgconfig"
  find "$pkgdir/usr/lib" -type f,l ! -name 'libRobotRaconteurCompanion.so.*' -delete
  install -Dm644 ../LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_librobotraconteur-companion-devel() {
  pkgdesc="Robot Raconteur C++ companion development files"
  depends=('librobotraconteur-companion0.4' 'boost>=1.58.0' 'cmake' 'base-devel' 'openssl' 'yaml-cpp' 'eigen' 'librobotraconteur-devel' 'robotraconteurgen')
  cd "$srcdir/RobotRaconteurCompanion-${pkgver}-Source/build"
  DESTDIR="$pkgdir" cmake --install .
  # Keep only headers, development symlinks, and cmake files
  find "$pkgdir/usr/lib" -type f,l ! -name 'libRobotRaconteurCompanion.so' ! -name '*.cmake' -delete
  rm -rf "$pkgdir/usr/bin" "$pkgdir/usr/lib/pkgconfig"
  # Keep only /usr/share/robotraconteur directory
  find "$pkgdir/usr/share" -mindepth 1 -maxdepth 1 ! -name 'robotraconteur' -exec rm -rf {} +
  find "$pkgdir/usr/lib" -type f,l -name 'libRobotRaconteurCompanion.so.*' -delete
  install -Dm644 ../LICENSE.txt "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}
"""


def get_src_dir(src_dir_arg):
    if src_dir_arg is not None:
        if not Path(src_dir_arg).is_dir():
            raise Exception("Provided src dir is not valid")
        return Path(src_dir_arg).absolute()

    repo_src_dir = (Path(__file__).parent.parent.parent.parent).absolute()
    return repo_src_dir


def get_out_dir(out_dir_arg, out_dir_default_override=None):
    if out_dir_arg is not None:
        if not Path(out_dir_arg).is_dir():
            raise Exception("Provided out dir is not valid")
        return Path(out_dir_arg).absolute()

    if out_dir_default_override is not None:
        return Path(out_dir_default_override)

    repo_out_dir = (Path(__file__).parent.parent.parent.parent).absolute()
    return repo_out_dir


def get_version(src_dir, args_version):
    if args_version is not None:
        return args_version
    package_xml_path = src_dir / "package.xml"
    with open(package_xml_path, "r") as f:
        package_xml = f.read()

    # Extract version from package.xml
    package_xml_ver_m = re.search("<version>(\\d+\\.\\d+\\.\\d+)</version>", package_xml)

    package_xml_ver_str = package_xml_ver_m.group(1)

    package_xml_ver_regex = r"^((?:0|[1-9]\d*)\.(?:0|[1-9]\d*)\.(?:0|[1-9]\d*))?"
    if not re.match(package_xml_ver_regex, package_xml_ver_str):
        raise Exception(f"Invalid config package.xml file version {package_xml_ver_str}")

    return package_xml_ver_str


def do_gen_debian(args):
    src_dir = get_src_dir(args.src_dir)
    ver = get_version(src_dir, args.version)
    print(f"src_dir: {src_dir}")
    print(f"ver: {ver}")
    out_dir = get_out_dir(args.out_dir, src_dir)
    print(f"out_dir: {out_dir}")

    debian_dir = out_dir / "debian"
    debian_dir.mkdir(parents=True, exist_ok=True)
    (debian_dir / "source").mkdir(parents=True, exist_ok=True)

    data = {
        "TEMPLATE_TIMESTAMP": datetime.now(timezone.utc).strftime("%a, %d %b %Y %H:%M:%S +0000"),
        "TEMPLATE_VERSION": ver,
        "TEMPLATE_PACKAGE_VERSION": args.package_version or "1",
        "TEMPLATE_DEBIAN_VERSION_SUFFIX": args.debian_version_suffix,
        "TEMPLATE_DEBIAN_DIST": args.debian_dist
    }
    deb_changelog_filled = string.Template(_debian_changelog).substitute(data)

    deb_files_to_write = {
        "control": _debian_control,
        "librobotraconteur-companion-dev.install": _debian_librobotraconteur_companion_dev_install,
        "librobotraconteur-companion0.4.install": _debian_librobotraconteur_companion0_4_install,
        "changelog": deb_changelog_filled.strip(' \t\n\r') + "\n\n",
        "rules": _debian_rules,
        "source/format": "3.0 (quilt)\n",
        "compat": "10\n",
        "copyright": _debian_copyright
    }

    if args.stdout:
        for k, v in deb_files_to_write.items():
            print(f"=== debian/{k} ===")
            print(v)
            print("")
    else:
        for k, v in deb_files_to_write.items():
            print(f"writing file {str(debian_dir / k)}")
            with open(debian_dir / k, "w") as f:
                f.write(v)

            rules_path = debian_dir / "rules"
            if rules_path.exists():
                rules_path.chmod(0o755)


def do_gen_gentoo(args):
    src_dir = get_src_dir(args.src_dir)
    ver = get_version(src_dir, args.version)
    print(f"src_dir: {src_dir}")
    print(f"ver: {ver}")
    out_dir = get_out_dir(args.out_dir, "/var/db/repos/local")
    print(f"out_dir: {out_dir}")

    gentoo_metadata = _gentoo_metadata

    gentoo_ebuild_template = string.Template(_gentoo_ebuild)
    print(f"args.gentoo_local_src: {args.gentoo_local_src}")
    if not args.gentoo_local_src:
        data = {
            "TEMPLATE_SRC_URI": _gentoo_github_src_uri,
            "TEMPLATE_LOCAL_EXTRAS": ""
        }
    else:
        data = {
            "TEMPLATE_SRC_URI": "",
            "TEMPLATE_LOCAL_EXTRAS": string.Template(_gentoo_local_src).substitute({"TEMPLATE_LOCAL_SRC_DIR": str(args.gentoo_local_src)})
        }

    gentoo_ebuild = gentoo_ebuild_template.substitute(data)

    gentoo_ebuild_fname = f"robotraconteur-companion-{ver}.ebuild"

    if args.stdout:
        print(f"=== {gentoo_ebuild_fname} ===")
        print(gentoo_ebuild)
        print("")

        print("=== metadata.xml ===")
        print(gentoo_metadata)
        print("")
    else:
        pkg_dir = out_dir / "dev-cpp/robotraconteur-companion"

        pkg_dir.mkdir(parents=True, exist_ok=True)

        with open(pkg_dir / gentoo_ebuild_fname, "w") as f:
            f.write(gentoo_ebuild)

        with open(pkg_dir / "metadata.xml", "w") as f:
            f.write(gentoo_metadata)


def do_gen_fedora(args):
    src_dir = get_src_dir(args.src_dir)
    ver = get_version(src_dir, args.version)
    print(f"src_dir: {src_dir}")
    print(f"ver: {ver}")
    out_dir = get_out_dir(args.out_dir, Path.home() / "rpmbuild")
    print(f"out_dir: {out_dir}")

    rpm_spec_template = string.Template(_rpm_spec)
    timestamp = datetime.now().strftime("%a %b %d %Y")

    data = {
        "TEMPLATE_VERSION": ver,
        "TEMPLATE_PACKAGE_VERSION": args.package_version or "1",
        "TIMESTAMP": timestamp
    }

    rpm_spec = rpm_spec_template.substitute(data)

    if args.stdout:
        print(f"=== robotraconteur-companion.spec ===")
        print(rpm_spec)
        print("")

    else:
        spec_dir = out_dir / "SPECS/"

        spec_dir.mkdir(parents=True, exist_ok=True)

        with open(spec_dir / "robotraconteur-companion.spec", "w") as f:
            f.write(rpm_spec)


class PercentTemplate(string.Template):
    delimiter = "%"

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)


def do_gen_arch(args):
    src_dir = get_src_dir(args.src_dir)
    ver = get_version(src_dir, args.version)
    print(f"src_dir: {src_dir}")
    print(f"ver: {ver}")
    out_dir = get_out_dir(args.out_dir, "/testbuild")
    print(f"out_dir: {out_dir}")

    data = {
        "TEMPLATE_TIMESTAMP": datetime.now(timezone.utc).strftime("%a, %d %b %Y %H:%M:%S +0000"),
        "TEMPLATE_VERSION": ver,
        "TEMPLATE_PACKAGE_VERSION": args.package_version or "1",
    }

    deb_files_to_write = {
        ".SRCINFO": PercentTemplate(_pacman_srcinfo).substitute(data),
        "PKGBUILD": PercentTemplate(_pacman_pkgbuild).substitute(data)
    }

    if args.stdout:
        for k, v in deb_files_to_write.items():
            print(f"=== debian/{k} ===")
            print(v)
            print("")
    else:
        out_dir.mkdir(parents=True, exist_ok=True)
        for k, v in deb_files_to_write.items():
            print(f"writing file {str(out_dir / k)}")
            with open(out_dir / k, "w") as f:
                f.write(v)


def do_gen(args):

    if args.dist == "gentoo":
        do_gen_gentoo(args)
    elif args.dist == "debian":
        do_gen_debian(args)
    elif args.dist == "fedora":
        do_gen_fedora(args)
    elif args.dist == "arch":
        do_gen_arch(args)
    else:
        raise Exception(f"Unknown dist {args.dist}")


def do_podman_build(args):
    src_dir = get_src_dir(args.src_dir)
    if (args.container):
        container = args.container
    else:
        container = _containers[args.dist]

    passthrough_args = [
        "--src-dir=/src",
        f"--dist={args.dist}"
    ]

    podman_args = []

    if args.debian_dist and len(args.debian_dist) > 0:
        passthrough_args.append(f"--debian-dist={args.debian_dist}")

    if args.debian_version_suffix and len(args.debian_version_suffix) > 0:
        passthrough_args.append(f"--debian-version-suffix={args.debian_version_suffix}")

    if args.package_version:
        passthrough_args.append(f"--package-version={args.package_version}")

    if args.gentoo_local_src:
        passthrough_args.append(f"--gentoo-local-src")

    if args.version:
        passthrough_args.append(f"--version={args.version}")

    if args.pkg_out_dir:
        podman_args.append(f"-v {str(Path(args.pkg_out_dir).absolute())}:/out")
        Path(args.pkg_out_dir).absolute().mkdir(parents=True, exist_ok=True)

    podman_args.append(f"-v {args.rr_pkgs_dir}:/rr_pkgs")

    rm_str = ""
    if not args.no_rm:
        rm_str = "--rm"

    if not args.shell:
        subprocess.check_call(
            f"podman run {rm_str} {' '.join(podman_args)} -v {src_dir}:/src -v {__file__}:/packaging_test.py -v {str(Path(__file__).parent / 'packaging_test_entry.sh')}:/packaging_test_entry.sh {container} /packaging_test_entry.sh podman-build-impl {' '.join(passthrough_args)}", shell=True)
    else:
        print(f"Command to run first: /packaging_test_entry.sh podman-build-impl {' '.join(passthrough_args)}")
        print(f"Command to run: python3 packaging_test.py podman-build-impl {' '.join(passthrough_args)}")
        subprocess.check_call(
            f"podman run {rm_str} -it {' '.join(podman_args)} -v {src_dir}:/src -v {__file__}:/packaging_test.py -v {str(Path(__file__).parent / 'packaging_test_entry.sh')}:/packaging_test_entry.sh {container}", shell=True)


def podman_build_copy_src():
    Path("/c_src2/robdef").mkdir(exist_ok=True, parents=True)
    subprocess.check_call("git ls-files -z '[^robdef]*' | xargs -0 -I{} cp --parents {} /c_src2/", shell=True, cwd="/src")
    subprocess.check_call("git ls-files -z | xargs -0 -I{} cp --parents {} /c_src2/robdef", shell=True, cwd="/src/robdef")


def do_podman_build_impl_gentoo(args):
    if args.steps is None or args.steps == "all":
        steps = ["setup", "gen", "build", "setup-test", "test"]
    else:
        steps = args.steps.split(",")

    if "setup" in steps:
        subprocess.check_call("gpg --no-tty --batch --import /usr/share/openpgp-keys/gentoo-release.asc", shell=True)
        subprocess.check_call("getuto")
        print("Begin emerge sync", flush=True)
        subprocess.check_call("emerge-webrsync --quiet", shell=True)
        subprocess.check_call("mkdir -p /etc/portage/repos.conf", shell=True)
        subprocess.check_call("cp /usr/share/portage/config/repos.conf /etc/portage/repos.conf/gentoo.conf", shell=True)
        subprocess.check_call(
            "emerge --getbinpkg app-eselect/eselect-repository dev-util/pkgdev dev-vcs/git", shell=True)
        subprocess.check_call("eselect repository create local", shell=True)
    if "gen" in steps:
        podman_build_copy_src()

        if not args.gentoo_local_src:
            subprocess.check_call("python3 /packaging_test.py gen --dist=gentoo --src-dir=/c_src2", shell=True)
        else:
            subprocess.check_call(
                "python3 /packaging_test.py gen --dist=gentoo --src-dir=/c_src2 --gentoo-local-src=/c_src2", shell=True)

        # copy robotraconteur ebuild from rr_pkgs
        rr_ebuild_source_dir = Path("/rr_pkgs/out-linux-packaging-gentoo-amd64/dev-cpp/robotraconteur")
        if platform.machine() == "aarch64":
            rr_ebuild_source_dir = Path("/rr_pkgs/out-linux-packaging-gentoo-arm64/dev-cpp/robotraconteur")

        rr_ebuild_dest_dir = Path("/var/db/repos/local/dev-cpp/robotraconteur")
        rr_ebuild_dest_dir.mkdir(parents=True, exist_ok=True)

        subprocess.check_call(f"cp {str(rr_ebuild_source_dir)}/*.ebuild {str(rr_ebuild_dest_dir)}/", shell=True)
        subprocess.check_call(f"cp {str(rr_ebuild_source_dir)}/metadata.xml {str(rr_ebuild_dest_dir)}/", shell=True)

        if not Path("/src2").is_dir():
            subprocess.check_call("git clone --depth 1 https://github.com/robotraconteur/robotraconteur.git /src2", shell=True)

    if "build" in steps:
        subprocess.check_call("ls /var/db/repos/local/dev-cpp/robotraconteur-companion", shell=True)
        subprocess.check_call("emerge --onlydeps --getbinpkg dev-cpp/robotraconteur-companion", shell=True)
        subprocess.check_call("emerge dev-cpp/robotraconteur-companion", shell=True)

        if Path("/out").is_dir():
            Path("/out/dev-cpp/robotraconteur-companion").mkdir(parents=True, exist_ok=True)
            subprocess.check_call("cp /var/db/repos/local/dev-cpp/robotraconteur-companion/*.ebuild /out/dev-cpp/robotraconteur-companion/", shell=True)
            subprocess.check_call("cp /var/db/repos/local/dev-cpp/robotraconteur-companion/metadata.xml /out/dev-cpp/robotraconteur-companion/", shell=True)

    if "setup-test" in steps:
        subprocess.check_call("emerge --getbinpkg dev-cpp/gtest", shell=True)
        subprocess.check_call("USE=\"jpeg png\" emerge media-libs/opencv", shell=True)
    if "test" in steps:
        subprocess.check_call(
            "cmake -S /c_src2/test -B /build_test -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=RelWithDebInfo -DROBOTRACONTEUR_COMPANION_DIST_TEST_BUILD=ON", shell=True)
        subprocess.check_call(f"cmake --build /build_test --config RelWithDebInfo -- -j{os.cpu_count()}", shell=True)
        subprocess.check_call("ctest . -C RelWithDebInfo --output-on-failure", cwd="build_test", shell=True)


def _save_installed_apt_packages():
    with open("/installed_packages.txt", "w") as f:
        subprocess.run(
            ["dpkg-query", "-f", "${binary:Package}\n", "-W"],
            stdout=f,
            check=True
        )


def _revert_to_saved_packages():
    if not Path("/installed_packages.txt").exists():
        print("No saved packages to revert to.")
        return
    with open("/installed_packages.txt") as f:
        keep = set(line.strip() for line in f)

    result = subprocess.run(
        ["dpkg-query", "-f", "${binary:Package}\n", "-W"],
        capture_output=True, text=True, check=True
    )
    current = set(result.stdout.strip().splitlines())

    to_remove = current - keep

    if to_remove:
        print("Packages to remove:", " ".join(to_remove))
        subprocess.run(["apt-get remove --purge -y"] + list(to_remove), shell=True)
    else:
        print("No extra packages to remove.")


def do_podman_build_impl_debian(args):
    if args.steps is None or args.steps == "all":
        steps = ["setup", "gen", "build", "setup-test", "test"]
    else:
        steps = args.steps.split(",")

    if "setup" in steps:
        _save_installed_apt_packages()
        subprocess.check_call("apt-get update", shell=True)
        # install debian build tools
        subprocess.check_call(
            "apt-get install -y devscripts equivs git tree git-buildpackage debian-keyring dpkg-dev debian-archive-keyring dh-make", shell=True)
        if Path("/rr_repo").is_dir():
            subprocess.check_call("rm -rf /rr_repo", shell=True)
        Path("/rr_repo").mkdir(parents=True, exist_ok=True)
        rr_deb_source_dir = Path("/rr_pkgs/out-linux-packaging-debian-amd64")
        if platform.machine() == "aarch64":
            rr_deb_source_dir = Path("/rr_pkgs/out-linux-packaging-debian-arm64")
        for p in rr_deb_source_dir.rglob("*.deb"):

            subprocess.check_call(f"cp {p} /rr_repo", shell=True)

        subprocess.check_call("dpkg-scanpackages . /dev/null | gzip -9c > /rr_repo/Packages.gz", shell=True, cwd="/rr_repo")
        with open("/etc/apt/sources.list.d/robotraconteur.list", "w") as f:
            f.write("deb [trusted=yes] file:/rr_repo ./\n")
        subprocess.check_call("apt-get update", shell=True)
    if "gen" in steps:
        podman_build_copy_src()
        subprocess.check_call("python3 /packaging_test.py gen --dist=debian --src-dir=/c_src2", shell=True)

    if "build" in steps:
        subprocess.check_call("mk-build-deps -i -r -t \"apt-get -y\" /c_src2/debian/control", shell=True, cwd="/c_src2")
        subprocess.check_call(
            "mk-build-deps --install --tool='apt-get -o Debug::pkgProblemResolver=yes --no-install-recommends --yes' /c_src2/debian/control", shell=True, cwd="/c_src2")
        subprocess.check_call("debuild -us -uc -b", shell=True, cwd="/c_src2")

        if Path("/out").is_dir():
            Path("/out/debian").mkdir(parents=True, exist_ok=True)
            subprocess.check_call("cp /*.deb /out/debian/", shell=True)

    if "setup-test" in steps:
        _revert_to_saved_packages()
        subprocess.check_call("apt-get install -y libgtest-dev", shell=True)
        subprocess.call("dpkg -i /*.deb", shell=True)
        subprocess.check_call("apt-get install -f -y", shell=True)
    if "test" in steps:
        subprocess.check_call(
            "cmake -S /c_src2/test -B /build_test -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=RelWithDebInfo -DROBOTRACONTEUR_COMPANION_DIST_TEST_BUILD=ON", shell=True)
        subprocess.check_call(f"cmake --build /build_test --config RelWithDebInfo -- -j{os.cpu_count()}", shell=True)
        subprocess.check_call("ctest . -C RelWithDebInfo --output-on-failure", cwd="build_test", shell=True)


def _save_installed_rpm_packages():
    with open("/installed_packages.txt", "w") as f:
        subprocess.run(
            ["rpm", "-qa", "--qf", "%{NAME}\n"],
            stdout=f,
            check=True
        )


def _revert_to_saved_rpm_packages():
    if not Path("/installed_packages.txt").exists():
        print("No saved packages to revert to.")
        return
    with open("/installed_packages.txt") as f:
        keep = set(line.strip() for line in f)

    result = subprocess.run(
        ["rpm", "-qa", "--qf", "%{NAME}\n"],
        capture_output=True, text=True, check=True
    )
    current = set(result.stdout.strip().splitlines())

    to_remove = current - keep

    if to_remove:
        print("Packages to remove:", " ".join(to_remove))
        subprocess.run(["dnf", "remove", "-y"] + list(to_remove), check=True)
    else:
        print("No extra packages to remove.")


def do_podman_build_impl_fedora(args):
    if args.steps is None or args.steps == "all":
        steps = ["setup", "gen", "build", "setup-test", "test"]
    else:
        steps = args.steps.split(",")

    src_dir = get_src_dir(args.src_dir)
    ver = get_version(src_dir, None)

    if "setup" in steps:
        _save_installed_rpm_packages()
        subprocess.check_call("yum install rpmbuild git -y", shell=True)
        subprocess.check_call("dnf install dnf-plugins-core createrepo -y", shell=True)
        if Path("/rr_repo_rpm").is_dir():
            subprocess.check_call("rm -rf /rr_repo_rpm", shell=True)

        Path("/rr_repo_rpm").mkdir(parents=True, exist_ok=True)
        rr_deb_source_dir = Path("/rr_pkgs/out-linux-packaging-fedora-amd64")
        if platform.machine() == "aarch64":
            rr_deb_source_dir = Path("/rr_pkgs/out-linux-packaging-fedora-arm64")
        for p in rr_deb_source_dir.rglob("*.rpm"):
            subprocess.check_call(f"cp {p} /rr_repo_rpm", shell=True)

        subprocess.check_call("createrepo_c /rr_repo_rpm", shell=True)
        with open("/etc/yum.repos.d/robotraconteur.repo", "w") as f:
            f.write(f"[robotraconteur]\n")
            f.write(f"name=Robot Raconteur Repository\n")
            f.write(f"baseurl=file:///rr_repo_rpm/\n")
            f.write(f"enabled=1\n")
            f.write(f"gpgcheck=0\n")
        subprocess.check_call("dnf makecache", shell=True)

    if "gen" in steps:
        podman_build_copy_src()
        subprocess.check_call(
            f"tar czvf RobotRaconteurCompanion-{ver}-Source.tar.gz --transform 's,^,RobotRaconteurCompanion-{ver}-Source/,' *", shell=True, cwd="/c_src2")
        sources_path = Path("/root/rpmbuild/SOURCES")
        sources_path.mkdir(parents=True, exist_ok=True)
        shutil.move(f"/c_src2/RobotRaconteurCompanion-{ver}-Source.tar.gz",
                    str(sources_path / f"RobotRaconteurCompanion-{ver}-Source.tar.gz"))
        subprocess.check_call("python3 /packaging_test.py gen --dist=fedora --src-dir=/c_src2", shell=True)

    if "build" in steps:
        subprocess.check_call("dnf builddep robotraconteur-companion.spec -y", shell=True, cwd="/root/rpmbuild/SPECS")
        subprocess.check_call("rpmbuild -ba robotraconteur-companion.spec", shell=True, cwd="/root/rpmbuild/SPECS")

        if Path("/out").is_dir():
            Path("/out/fedora").mkdir(parents=True, exist_ok=True)
            subprocess.check_call("cp /root/rpmbuild/RPMS/*/*.rpm /out/fedora/", shell=True)

    if "setup-test" in steps:
        _revert_to_saved_rpm_packages()
        subprocess.check_call("dnf install -y gtest-devel cmake g++ make", shell=True)
        rpm_fnames = []
        for p in Path("/root/rpmbuild/RPMS").rglob("*.rpm"):
            if "debug" in str(p):
                continue
            rpm_fnames.append(str(p))
        print(f"dnf install -y {' '.join(rpm_fnames)}")
        subprocess.check_call(f"dnf install -y {' '.join(rpm_fnames)}", shell=True, cwd="/root")
    if "test" in steps:
        subprocess.check_call(
            "cmake -S /c_src2/test -B /build_test -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=RelWithDebInfo -DROBOTRACONTEUR_COMPANION_DIST_TEST_BUILD=ON", shell=True)
        subprocess.check_call(f"cmake --build /build_test --config RelWithDebInfo -- -j{os.cpu_count()}", shell=True)
        subprocess.check_call("ctest . -C RelWithDebInfo --output-on-failure", cwd="build_test", shell=True)


def _user_exists(username):
    try:
        pwd.getpwnam(username)
        return True
    except KeyError:
        return False


def _add_user(username):
    subprocess.run(["useradd", "-m", username], check=True)
    subprocess.run(["passwd", "-d", username], check=True)
    subprocess.run(["usermod", "-aG", "wheel", username], check=True)


def _ensure_wheel_nopasswd():
    sudoers_line = "%wheel ALL=(ALL) NOPASSWD: ALL"
    with open("/etc/sudoers", "r") as f:
        if sudoers_line in f.read():
            return
    with open("/etc/sudoers", "a") as f:
        f.write(sudoers_line + "\n")


def _save_installed_pacman_packages():
    with open("/installed_packages.txt", "w") as f:
        subprocess.run(
            ["pacman", "-Qq"],
            stdout=f,
            check=True
        )


def _revert_to_saved_pacman_packages():
    if not Path("/installed_packages.txt").exists():
        print("No saved packages to revert to.")
        return
    with open("/installed_packages.txt") as f:
        keep = set(line.strip() for line in f)

    result = subprocess.run(
        ["pacman", "-Qq"],
        capture_output=True, text=True, check=True
    )
    current = set(result.stdout.strip().splitlines())

    to_remove = current - keep

    if to_remove:
        print("Packages to remove:", " ".join(to_remove))
        subprocess.run(["pacman", "-Rns", "--noconfirm"] + list(to_remove), check=True)
    else:
        print("No extra packages to remove.")


def do_podman_build_impl_arch(args):
    username = "testuser"
    if args.steps is None or args.steps == "all":
        steps = ["setup", "gen", "build", "setup-test", "test"]
    else:
        steps = args.steps.split(",")

    src_dir = get_src_dir(args.src_dir)
    ver = get_version(src_dir, None)
    out_dir = Path("/testbuild")
    out_dir.mkdir(parents=True, exist_ok=True)

    if "setup" in steps:
        subprocess.check_call("pacman -S --needed --noconfirm base-devel sudo git", shell=True)
        if not _user_exists(username):
            _add_user(username)
        _ensure_wheel_nopasswd()
        _save_installed_pacman_packages()

        if Path("/rr_repo_pacman").is_dir():
            subprocess.check_call("rm -rf /rr_repo_pacman", shell=True)

        Path("/rr_repo_pacman").mkdir(parents=True, exist_ok=True)
        rr_arch_source_dir = Path("/rr_pkgs/out-linux-packaging-arch-amd64")
        if platform.machine() == "aarch64":
            rr_arch_source_dir = Path("/rr_pkgs/out-linux-packaging-arch-arm64")

        for p in rr_arch_source_dir.rglob("*.pkg.tar.zst"):
            subprocess.check_call(f"cp {p} /rr_repo_pacman", shell=True)
        subprocess.check_call("repo-add /rr_repo_pacman/robotraconteur.db.tar.gz /rr_repo_pacman/*.pkg.tar.zst", shell=True)
        with open("/etc/pacman.conf", "a") as f:
            f.write("\n[robotraconteur]\n")
            f.write("SigLevel = Optional TrustAll\n")
            f.write("Server = file:///rr_repo_pacman/\n")
        subprocess.check_call("pacman -Sy", shell=True)

    if "gen" in steps:
        podman_build_copy_src()
        subprocess.check_call(
            f"tar czvf RobotRaconteurCompanion-{ver}-Source.tar.gz --transform 's,^,RobotRaconteurCompanion-{ver}-Source/,' *", shell=True, cwd="/c_src2")

        shutil.move(f"/c_src2/RobotRaconteurCompanion-{ver}-Source.tar.gz",
                    str(out_dir / f"RobotRaconteurCompanion-{ver}-Source.tar.gz"))
        subprocess.check_call("python3 /packaging_test.py gen --dist=arch --src-dir=/c_src2", shell=True)

    if "build" in steps:
        subprocess.check_call(f"chown {username} /testbuild", shell=True)
        subprocess.check_call(
            f"su - {username} -c \"export MAKEFLAGS='-j$(nproc)'; cd {str(out_dir)} && makepkg -s --noconfirm\"", shell=True, cwd=out_dir)

        if Path("/out").is_dir():
            Path("/out/arch").mkdir(parents=True, exist_ok=True)
            subprocess.check_call("cp /testbuild/*.pkg.tar.zst /out/arch/", shell=True)

    if "setup-test" in steps:
        _revert_to_saved_pacman_packages()
        subprocess.check_call("pacman -S --noconfirm gtest opencv", shell=True)
        rpm_fnames = []
        for p in Path(out_dir).rglob("*.pkg.tar.zst"):
            if "debug" in str(p):
                continue
            rpm_fnames.append(str(p))
        print(f"pacman -U --noconfigm {' '.join(rpm_fnames)}")
        subprocess.check_call(f"pacman -U --noconfirm {' '.join(rpm_fnames)}", shell=True, cwd=out_dir)
    if "test" in steps:
        subprocess.check_call(
            "cmake -S /c_src2/test -B /build_test -DBUILD_TESTING=ON -DCMAKE_BUILD_TYPE=RelWithDebInfo -DROBOTRACONTEUR_COMPANION_DIST_TEST_BUILD=ON", shell=True)
        subprocess.check_call(f"cmake --build /build_test --config RelWithDebInfo -- -j{os.cpu_count()}", shell=True)
        subprocess.check_call("ctest . -C RelWithDebInfo --output-on-failure", cwd="build_test", shell=True)


def do_podman_build_impl(args):
    if args.dist == "gentoo":
        do_podman_build_impl_gentoo(args)
    elif args.dist == "debian":
        do_podman_build_impl_debian(args)
    elif args.dist == "fedora":
        do_podman_build_impl_fedora(args)
    elif args.dist == "arch":
        do_podman_build_impl_arch(args)
    else:
        raise Exception(f"Unknown dist {args.dist}")


def main():
    parser = argparse.ArgumentParser(prog="packaging_test.py")

    subparsers = parser.add_subparsers(help='subcommand help', dest="command")

    parser_gen = subparsers.add_parser("gen", help="generate packaging files")
    parser_gen.add_argument("--dist", type=str, default="debian", help="Linux target dist")
    parser_gen.add_argument("--src-dir", type=str, default=None, help="Directory of source")
    parser_gen.add_argument("--out-dir", type=str, default=None, help="Output directory")
    parser_gen.add_argument("--version", type=str, default=None, help="Package version")
    parser_gen.add_argument("--package-version", type=str, default=None, help="Package version")
    parser_gen.add_argument("--stdout", action="store_true", help="Send generated files to stdout")
    parser_gen.add_argument("--debian-dist", type=str, default="unstable", help="Debian target distribution")
    parser_gen.add_argument("--debian-version-suffix", type=str, default="", help="Debian package version suffix")
    parser_gen.add_argument("--gentoo-local-src", type=str, default=None, help="Use local src with gentoo")

    parser_gen = subparsers.add_parser("podman-build")
    parser_gen.add_argument("--dist", type=str, default="debian", help="Linux target dist")
    parser_gen.add_argument("--container", type=str, default=None, help="podman container name")
    parser_gen.add_argument("--src-dir", type=str, default=None, help="Directory of source")
    parser_gen.add_argument("--version", type=str, default=None, help="Package version")
    parser_gen.add_argument("--package-version", type=str, default=None, help="Package version")
    parser_gen.add_argument("--debian-dist", type=str, default="unstable", help="Debian target distribution")
    parser_gen.add_argument("--debian-version-suffix", type=str, default="", help="Debian package version suffix")
    parser_gen.add_argument("--gentoo-local-src", action="store_true", help="Use local src with gentoo")
    parser_gen.add_argument("--no-rm", action="store_true", help="Don't add --rm to podman command")
    parser_gen.add_argument("--shell", action="store_true", help="Start an interactive shell")
    parser_gen.add_argument("--pkg-out-dir", type=str, default=None, help="Output directory for packages")
    parser_gen.add_argument("--rr-pkgs-dir", type=str, required=True, help="Directory containing Robot Raconteur Core packages")

    parser_gen = subparsers.add_parser("podman-build-impl")
    parser_gen.add_argument("--dist", type=str, default="debian", help="Linux target dist")
    parser_gen.add_argument("--src-dir", type=str, default=None, help="Directory of source")
    parser_gen.add_argument("--package-version", type=str, default=None, help="Package version")
    parser_gen.add_argument("--debian-dist", type=str, default="unstable", help="Debian target distribution")
    parser_gen.add_argument("--debian-version-suffix", type=str, default="", help="Debian package version suffix")
    parser_gen.add_argument("--gentoo-local-src", action="store_true", help="Use local src with gentoo")
    parser_gen.add_argument("--steps", type=str, default="all", help="Steps to run. Defaults to \"all\"")

    args = parser.parse_args()

    if args.command == "gen":
        do_gen(args)
    elif args.command == "podman-build":
        do_podman_build(args)
    elif args.command == "podman-build-impl":
        do_podman_build_impl(args)
    else:
        parser.print_help()


if __name__ == "__main__":
    main()
