#include <RobotRaconteurCompanion/Util/ImageUtil.h>

#include <gtest/gtest.h>

namespace RRC_Util = RobotRaconteur::Companion::Util;

void compare_mat(const cv::Mat& img1, const cv::Mat& img2)
{
    ASSERT_EQ(img1.cols, img2.cols);
    ASSERT_EQ(img1.rows, img2.rows);
    ASSERT_EQ(img1.step[0], img2.step[0]);
    ASSERT_EQ(img1.type(), img2.type());
    ASSERT_EQ(memcmp(img1.data, img2.data, img1.total() * img1.elemSize()), 0);
}

void compare_image_info(const com::robotraconteur::image::ImageInfoPtr& info1, const cv::Mat& mat2,
                        com::robotraconteur::image::ImageEncoding::ImageEncoding expected_encoding)
{
    ASSERT_EQ(info1->width, mat2.cols);
    ASSERT_EQ(info1->height, mat2.rows);
    ASSERT_EQ(info1->step, mat2.step[0]);
    ASSERT_EQ(info1->encoding, expected_encoding);
}

void compare_image_bytes(const com::robotraconteur::image::ImagePtr& img1, const cv::Mat& img2)
{
    ASSERT_EQ(img1->data->size(), img2.total() * img2.elemSize());
    ASSERT_EQ(memcmp(img1->data->data(), img2.data, img2.total() * img2.elemSize()), 0);
}

void compare_image_bytes_cvt_color(const com::robotraconteur::image::ImagePtr& img1, const cv::Mat& img2, int cvt_color)
{
    cv::Mat img2_cvt;
    cv::cvtColor(img2, img2_cvt, cvt_color);
    ASSERT_EQ(img1->data->size(), img2_cvt.total() * img2_cvt.elemSize());
    ASSERT_EQ(memcmp(img1->data->data(), img2_cvt.data, img2_cvt.total() * img2_cvt.elemSize()), 0);
}

void run_image_test(const cv::Mat& img, com::robotraconteur::image::ImageEncoding::ImageEncoding encoding,
                    int cvt_color = -1)
{
    // Convert to ImagePtr
    auto img_ptr = RRC_Util::MatToImage(img, encoding);

    // Check image_info
    compare_image_info(img_ptr->image_info, img, encoding);

    if (cvt_color != -1)
    {
        // Compare bytes
        compare_image_bytes_cvt_color(img_ptr, img, cvt_color);
    }
    else
    {
        // Compare bytes
        compare_image_bytes(img_ptr, img);
    }

    // Convert back
    auto img2 = RRC_Util::ImageToMat(img_ptr);

    // Compare images
    compare_mat(img, img2);
}

TEST(ImageUtil, TestImageUtil_BGR)
{
    // Populate random image
    cv::Mat img(100, 110, CV_8UC3);
    cv::randu(img, cv::Scalar(0, 0, 0), cv::Scalar(255, 255, 255));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::bgr888);
}

TEST(ImageUtil, TestImageUtil_RGB)
{
    // Populate random image
    cv::Mat img(100, 110, CV_8UC3);
    cv::randu(img, cv::Scalar(0, 0, 0), cv::Scalar(255, 255, 255));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::rgb888, cv::COLOR_BGR2RGB);
}

TEST(ImageUtil, TestImageUtil_RGBA)
{
    // Populate random image
    cv::Mat img(100, 110, CV_8UC4);
    cv::randu(img, cv::Scalar(0, 0, 0, 0), cv::Scalar(255, 255, 255, 255));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::rgba8888, cv::COLOR_BGRA2RGBA);
}

TEST(ImageUtil, TestImageUtil_BGRA)
{
    // Populate random image
    cv::Mat img(100, 110, CV_8UC4);
    cv::randu(img, cv::Scalar(0, 0, 0, 0), cv::Scalar(255, 255, 255, 255));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::bgra8888);
}

TEST(ImageUtil, TestImageUtil_Mono8)
{
    // Populate random image
    cv::Mat img(100, 110, CV_8UC1);
    cv::randu(img, cv::Scalar(0), cv::Scalar(255));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::mono8);
}

TEST(ImageUtil, TestImageUtil_Mono16)
{
    // Populate random image
    cv::Mat img(100, 110, CV_16UC1);
    cv::randu(img, cv::Scalar(0), cv::Scalar(65535));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::mono16);
    run_image_test(img, com::robotraconteur::image::ImageEncoding::depth_u16);
}

TEST(ImageUtil, TestImageUtil_Mono32)
{
    // Populate random image
    cv::Mat img(100, 110, CV_32SC1);
    cv::randu(img, cv::Scalar(INT_MIN), cv::Scalar(INT_MAX));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::mono32);
    run_image_test(img, com::robotraconteur::image::ImageEncoding::depth_u32);
}

#if CV_VERSION_MAJOR >= 4
TEST(ImageUtil, TestImageUtil_MonoF16)
{
    // Populate random image
    cv::Mat img(100, 110, CV_16FC1);
    cv::randu(img, cv::Scalar(-1.0), cv::Scalar(1.0));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::mono_f16);
}
#endif

TEST(ImageUtil, TestImageUtil_MonoF32)
{
    // Populate random image
    cv::Mat img(100, 110, CV_32FC1);
    cv::randu(img, cv::Scalar(-1.0), cv::Scalar(1.0));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::mono_f32);
    run_image_test(img, com::robotraconteur::image::ImageEncoding::depth_f32);
}

TEST(ImageUtil, TestImageUtil_MonoF64)
{
    // Populate random image
    cv::Mat img(100, 110, CV_64FC1);
    cv::randu(img, cv::Scalar(-1.0), cv::Scalar(1.0));

    run_image_test(img, com::robotraconteur::image::ImageEncoding::mono_f64);
    run_image_test(img, com::robotraconteur::image::ImageEncoding::depth_f64);
}

int main(int argc, char** argv) // NOLINT
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
