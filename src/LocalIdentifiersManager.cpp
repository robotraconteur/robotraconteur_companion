#include "RobotRaconteurCompanion/Util/LocalIdentifiersManager.h"
#include <boost/filesystem.hpp>
#include "RobotRaconteurCompanion/Util/IdentifierUtil.h"

#ifdef ROBOTRACONTEUR_WINDOWS
#include <Shlobj.h>
#else

#endif

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{

namespace detail
{
    
    class LocalIdentifierFD
    {
    public:
        
        boost::mutex this_lock;

        std::map<std::string, std::string> info;
        
#ifdef ROBOTRACONTEUR_WINDOWS
        HANDLE fd;
#else
        int fd;
#endif
        
        LocalIdentifierFD()
        {
#ifdef ROBOTRACONTEUR_WINDOWS
		fd = NULL;
#else
		fd = -1;
#endif
        }

        ~LocalIdentifierFD()
        {
#ifdef ROBOTRACONTEUR_WINDOWS
		CloseHandle(fd);
#else
		close(fd);
#endif
        }

        void open_read(const boost::filesystem::path& path, boost::system::error_code& err)
        {
#ifdef BOOST_WINDOWS
		HANDLE h = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (h == INVALID_HANDLE_VALUE)
		{
			err = boost::system::error_code(GetLastError(), boost::system::system_category());
			return;
		}

		fd = h;
#else
		int fd1 = open(path.c_str(), O_CLOEXEC | O_RDONLY);
		if (fd1 < 0)
		{
			err = boost::system::error_code(errno, boost::system::system_category());
			return;
		}
		fd = fd1;
#endif
        }

        void open_lock_write(const boost::filesystem::path& path, bool delete_on_close, boost::system::error_code& err)
        {
#ifdef BOOST_WINDOWS
		DWORD flags = FILE_ATTRIBUTE_NORMAL;
		if (delete_on_close)
		{
			flags |= FILE_FLAG_DELETE_ON_CLOSE;
		}
		HANDLE h = CreateFileW(path.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, flags, NULL);
		if (h == INVALID_HANDLE_VALUE)
		{
			err = boost::system::error_code(GetLastError(), boost::system::system_category());
			return;
		}

		fd = h;
#else
		int fd1 = open(path.c_str(), O_CLOEXEC | O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
		if (fd1 < 0)
		{
			err = boost::system::error_code(errno, boost::system::system_category());
			return;
		}

		struct ::flock lock;
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = 0;
		lock.l_len = 0;
		if (::fcntl(fd1, F_SETLK, &lock) < 0)
		{
			close(fd1);
			err = boost::system::error_code(boost::system::errc::no_lock_available, boost::system::system_category());
			return;
		}

		fd = fd1;
#endif
        }
        //void reopen_lock_write(bool delete_on_close, boost::system::error_code& err);

        bool read(std::string& data)
        {
#ifdef ROBOTRACONTEUR_WINDOWS
		if (::SetFilePointer(fd, 0, 0, FILE_BEGIN) == INVALID_SET_FILE_POINTER) return false;
		DWORD len = GetFileSize(fd, NULL);
		if (len == INVALID_FILE_SIZE) return false;
		if (len > 16 * 1024) return false;
		std::string ret;
		ret.resize(len);
		DWORD bytes_read;
		if (!::ReadFile(fd, &ret[0], len, &bytes_read, NULL))
		{
			return false;
		}

		if (bytes_read != len) return false;
		data = ret;
		return true;
#else
		if (lseek(fd, 0, SEEK_END) < 0) return false;
		int len = lseek(fd, 0, SEEK_CUR);
		if (len < 0) return false;
		if (lseek(fd, 0, SEEK_SET) < 0) return false;

		std::string ret;
		ret.resize(len);
		
		int retval = ::read(fd, &ret[0], len);
		if (retval < 0)
		{
			return false;
		}

		if (retval != len) return false;
		data = ret;
		return true;
#endif
        }

        bool read_info()
        {
            std::string in;
            if (!read(in)) return false;

            std::vector<std::string> lines;
            boost::split(lines, in, boost::is_any_of("\n"), boost::algorithm::token_compress_on);
            info.clear();
            BOOST_FOREACH(std::string& l, lines)
            {
                boost::regex r("^\\s*([\\w+\\.\\-]+)\\s*\\:\\s*(.*)\\s*$");
                boost::smatch r_match;
                if (!boost::regex_match(l, r_match, r))
                {
                    continue;
                }			
                info.insert(std::make_pair(boost::trim_copy(r_match[1].str()), boost::trim_copy(r_match[2].str())));
            }
            return true;
        }

        bool write(const std::string& data)
        {
#ifdef ROBOTRACONTEUR_WINDOWS
		DWORD bytes_written = 0;
		if (!::WriteFile(fd, &data[0], data.size(), &bytes_written, NULL)) return false;
		if (bytes_written != data.size()) return false;
		if(!FlushFileBuffers(fd)) return false;
#else		
		int ret = ::write(fd, &data[0], data.size());
		if (ret != data.size()) return false;
		if (fsync(fd) < 0) return false;
#endif
		return true;
        }
        
        bool write_info()
        {
            std::string data;
            for (std::map<std::string, std::string>::iterator e = info.begin(); e != info.end(); e++)
            {
                data += e->first + ": " + e->second + "\n";
            }

            return write(data);
        }
                        
        bool reset()
        {
#ifdef ROBOTRACONTEUR_WINDOWS
		if(::SetFilePointer(fd, 0, 0, FILE_BEGIN)== INVALID_SET_FILE_POINTER) return false;
		if(!::SetEndOfFile(fd)) return false;
#else
		if (lseek(fd, 0, SEEK_SET) < 0) return false;
		if (ftruncate(fd, 0) < 0) return false;
#endif
        }
        
        size_t file_len()
        {
#ifdef ROBOTRACONTEUR_WINDOWS
		return ::GetFileSize(fd, NULL);
#else
		int init_pos = lseek(fd, 0, SEEK_CUR);
		if (init_pos < 0) return -1;
		if (lseek(fd, 0, SEEK_END) < 0) return -1;
		int len = lseek(fd, 0, SEEK_CUR);
		if (len < 0) return -1;
		if (lseek(fd, init_pos, SEEK_SET) < 0) return -1;
		return len;
#endif
        }
        

    };

    

    boost::filesystem::path GetUserDataPath()
    {
#ifdef ROBOTRACONTEUR_WINDOWS
        boost::scoped_array<char> sysdata_path1(new char[MAX_PATH]);
        if (FAILED(SHGetFolderPath(NULL,CSIDL_LOCAL_APPDATA | CSIDL_FLAG_CREATE,NULL,0,sysdata_path1.get())))
        {
            throw SystemResourceException("Could not get system information");
        }

        boost::filesystem::path sysdata_path(sysdata_path1.get());
                    
        boost::filesystem::path path = sysdata_path / "RobotRaconteur";
#else
        char* path1=std::getenv("HOME");
        if (!path1) throw SystemResourceException("Home directory not set");
        boost::filesystem::path path = boost::filesystem::path(path1) / ".config" / "RobotRaconteur";
#endif
        boost::system::error_code ec1;
        boost::filesystem::create_directories(path, ec1);
        if (ec1) throw SystemResourceException("Could not activate system for local identifiers");

        return path;
    }

    boost::filesystem::path GetUserRunPath()
    {
#ifdef ROBOTRACONTEUR_WINDOWS
        boost::scoped_array<char> sysdata_path1(new char[MAX_PATH]);
        if (FAILED(SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA | CSIDL_FLAG_CREATE, NULL, 0, sysdata_path1.get())))
        {
            throw SystemResourceException("Could not get system information");
        }

        boost::filesystem::path sysdata_path(sysdata_path1.get());

        boost::filesystem::path path = sysdata_path / "RobotRaconteur" / "run";
        boost::system::error_code ec1;
        boost::filesystem::create_directories(path, ec1);
        if (ec1) throw SystemResourceException("Could not activate system for local identifiers");
        
#elif defined(ROBOTRACONTEUR_APPLE)
        
        int u= getuid();
        
        boost::filesystem::path path;
        if (u==0)
        {
            path="/var/run/robotraconteur/root/";
            boost::filesystem::create_directories(path);
            chmod(path.c_str(),  S_IRUSR |  S_IWUSR |  S_IXUSR);
            //path /= "robotraconteur";
            boost::system::error_code ec1;
            boost::filesystem::create_directories(path, ec1);
            if (ec1) throw SystemResourceException("Could not activate system for local identifiers");
            
        }
        else
        {
            char* path1 = std::getenv("TMPDIR");
            if (!path1) throw SystemResourceException("Could not activate system for local identifiers");
            
            path = path1;
            path = path.remove_trailing_separator().parent_path();
            path /= "C";
            if (!boost::filesystem::is_directory(path)) throw SystemResourceException("Could not activate system for local identifiers");
            path /= "robotraconteur";
            boost::system::error_code ec1;
            boost::filesystem::create_directories(path, ec1);
            if (ec1) throw SystemResourceException("Could not activate system for local identifiers");
        }

#else
        int u= getuid();

        //TODO: fix mac version
        boost::filesystem::path path;
        if (u==0)
        {
            path="/var/run/robotraconteur/root/";
            boost::filesystem::create_directories(path);
            chmod(path.c_str(),  S_IRUSR |  S_IWUSR |  S_IXUSR);
            //path /= "robotraconteur";
            boost::system::error_code ec1;
            boost::filesystem::create_directories(path, ec1);
            if (ec1) throw SystemResourceException("Could not activate system for local identifiers");

        }
        else
        {
            char* path1 = std::getenv("XDG_RUNTIME_DIR");
            if (path1!=NULL)
            {
                path = path1;
                path /= "robotraconteur";
                boost::system::error_code ec1;
                boost::filesystem::create_directories(path, ec1);
                if (ec1) throw SystemResourceException("Could not activate system for local identifiers");
            }
            else
            {

                //path = boost::filesystem::path("/tmp/.robotraconteur-user-" + boost::lexical_cast<std::string>(u));

                path = boost::filesystem::path("/var/run/user") / boost::lexical_cast<std::string>(u) / "robotraconteur";
                boost::system::error_code ec1;
                boost::filesystem::create_directories(path, ec1);
                if (ec1) throw SystemResourceException("Could not activate system for local identifiers: $XDG_RUNTIME_DIR not set");
                /*chmod(path.c_str(),  S_IRUSR |  S_IWUSR |  S_IXUSR);
                struct stat s;
                if (stat(path.c_str(), &s) < 0)
                {
                    throw SystemResourceException("Could not activate system for local identifiers: permission error");
                }

                if (s.st_uid != u)
                {
                    throw SystemResourceException("Could not activate system for local identifiers");
                }*/
            }


        }
#endif
        return path;
    }

    boost::filesystem::path GetUserIdentifierPath()
    {
        boost::filesystem::path path = GetUserDataPath() / "identifiers";
        boost::system::error_code ec1;
        boost::filesystem::create_directories(path, ec1);
        if (ec1) throw SystemResourceException("Could not activate system for local identifiers");

        return path;
	}

}

LocalIdentifierLock::LocalIdentifierLock(const com::robotraconteur::identifier::IdentifierPtr& id, boost::shared_ptr<detail::LocalIdentifierFD> fd)
{
    this->id = id;
    this->fd = fd;
}

com::robotraconteur::identifier::IdentifierPtr LocalIdentifierLock::GetIdentifier()
{
    return id;
}

LocalIdentifierLockPtr GetIdentifierForNameAndLock(const std::string& category, const std::string& name)
{		
    boost::uuids::uuid ret_uuid;

    if (!boost::regex_match(name.begin(), name.end(), boost::regex("^[a-zA-Z][a-zA-Z0-9_\\.\\-]*$")))
    {
        throw InvalidArgumentException("\"" + name + "\" is an invalid identifier name");
    }

    std::string category2 = boost::to_lower_copy(category);
    boost::filesystem::path p1 = detail::GetUserIdentifierPath() / category;
    boost::filesystem::create_directories(p1);
    boost::filesystem::path p = p1 / name;

#ifdef ROBOTRACONTEUR_WINDOWS

    RR_SHARED_PTR<detail::LocalIdentifierFD> fd = RR_MAKE_SHARED<detail::LocalIdentifierFD>();

    boost::system::error_code open_err;
    fd->open_lock_write(p, false, open_err);
    if (open_err)
    {
        if (open_err.value() == ERROR_SHARING_VIOLATION)
        {
            throw InvalidOperationException("Identifier name in use");
        }

        throw SystemResourceException("Could not initialize local identifier");
    }


#else
    boost::filesystem::path p_lock1 = detail::GetUserRunPath() / "identifiers" / category;
    boost::filesystem::create_directories(p_lock1);
    boost::filesystem::path p_lock = p_lock1 / name;
    p_lock /= name + ".pid";

    RR_SHARED_PTR<detail::LocalIdentifierFD> fd_run = RR_MAKE_SHARED<detail::LocalIdentifierFD>();

    boost::system::error_code open_run_err;
    fd_run->open_lock_write(p_lock, false, open_run_err);
    if (open_run_err)
    {
        if (open_run_err.value() == boost::system::errc::no_lock_available)
        {
            throw InvalidOperationException("Identifier name in use");
        }
        throw SystemResourceException("Could not initialize local identifiers");
    }

    std::string pid_str = boost::lexical_cast<std::string>(getpid());
    if (!fd_run->write(pid_str)) throw SystemResourceException("Could not initialize local identifiers");

    RR_SHARED_PTR<detail::LocalIdentifierFD> fd = RR_MAKE_SHARED<detail::LocalIdentifierFD>();

    boost::system::error_code open_err;
    fd->open_lock_write(p, false, open_err);
    if (open_err)
    {
        if (open_err.value() == boost::system::errc::read_only_file_system)
        {
            open_err = boost::system::error_code();
            fd->open_read(p, open_err);
            if (open_err)
            {
                throw InvalidOperationException("Local identifiers not set on read only filesystem");
            }
        }
        else
        {
            throw SystemResourceException("Could not initialize local identifiers");
        }
    }			

    
#endif
    size_t len = fd->file_len();
    
    if (len == 0 || len == -1 || len > 16*1024)
    {
        NodeID random_nodeid = NodeID::NewUniqueID();
        ret_uuid = random_nodeid.ToUuid();
        std::string dat = random_nodeid.ToString();
        fd->write(dat);
    }
    else
    {				
        std::string nodeid_str;
        fd->read(nodeid_str);
        try
        {
            boost::trim(nodeid_str);
            boost::trim_if(nodeid_str,boost::is_any_of("{}"));
            ret_uuid = boost::lexical_cast<boost::uuids::uuid>(nodeid_str);
        }
        catch (std::exception&)
        {
            throw IOException("Error in local identifier settings file");
        }
    }

    com::robotraconteur::identifier::IdentifierPtr ret_id = CreateIdentifier(name,ret_uuid);

#ifdef ROBOTRACONTEUR_WINDOWS
    return boost::make_shared<LocalIdentifierLock>(ret_id,fd);
#else
    return boost::make_shared<LocalIdentifierLock>(ret_id,fd_run);
#endif
    }

}
}
}