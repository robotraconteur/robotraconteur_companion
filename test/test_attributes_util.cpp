#include <RobotRaconteur.h>
#include <RobotRaconteurCompanion/StdRobDef/StdRobDefAll.h>
#include <RobotRaconteurCompanion/Util/AttributesUtil.h>
#include <RobotRaconteurCompanion/Util/IdentifierUtil.h>

#include <gtest/gtest.h>

namespace RR = RobotRaconteur;
namespace RRCUtil = RobotRaconteur::Companion::Util;

// Regression test: GetDefaultServiceAttributesFromDeviceInfo used `extended->at("tags")`,
// which throws std::out_of_range when `extended` is populated but has no "tags" key.
// It should instead simply omit the tags attribute.
TEST(AttributesUtil, ExtendedWithoutTagsDoesNotThrow)
{
    com::robotraconteur::device::DeviceInfoPtr info(new com::robotraconteur::device::DeviceInfo());
    info->device = RRCUtil::CreateIdentifierFromName("my_device");

    // extended map present but with an unrelated key and NO "tags" entry.
    info->extended = RR::AllocateEmptyRRMap<std::string, RR::RRValue>();
    info->extended->insert(std::make_pair("other_attr", RR::stringToRRArray("some_value")));

    std::map<std::string, RR::RRValuePtr> attrs;
    ASSERT_NO_THROW(attrs = RRCUtil::GetDefaultServiceAttributesFromDeviceInfo(info));

    // device should be present, tags should be absent (no "tags" key was provided).
    EXPECT_EQ(attrs.count("device"), 1U);
    EXPECT_EQ(attrs.count("tags"), 0U);
}

// Sanity: when "tags" IS present it is still added.
TEST(AttributesUtil, ExtendedWithTagsAddsTags)
{
    com::robotraconteur::device::DeviceInfoPtr info(new com::robotraconteur::device::DeviceInfo());
    info->device = RRCUtil::CreateIdentifierFromName("my_device");

    RR::RRListPtr<RR::RRValue> tags = RR::AllocateEmptyRRList<RR::RRValue>();
    tags->push_back(RR::rr_cast<RR::RRValue>(RRCUtil::CreateIdentifierFromName("tag_a")));

    info->extended = RR::AllocateEmptyRRMap<std::string, RR::RRValue>();
    info->extended->insert(std::make_pair("tags", tags));

    std::map<std::string, RR::RRValuePtr> attrs;
    ASSERT_NO_THROW(attrs = RRCUtil::GetDefaultServiceAttributesFromDeviceInfo(info));
    EXPECT_EQ(attrs.count("tags"), 1U);
}

int main(int argc, char** argv) // NOLINT
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
