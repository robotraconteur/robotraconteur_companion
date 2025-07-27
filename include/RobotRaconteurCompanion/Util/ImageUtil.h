/**
 * @file ImageUtil.h
 *
 * @author John Wason, PhD
 *
 * @copyright Copyright 2024 Wason Technology, LLC
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * @par
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "com__robotraconteur__image.h"

#include <opencv2/core/version.hpp>

#if !defined(CV_VERSION_EPOCH) && CV_VERSION_MAJOR >= 3
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#else
#include <opencv2/opencv.hpp>
#endif

#pragma once

#include <boost/predef/other/endian.h>

#if !defined(BOOST_ENDIAN_LITTLE_BYTE_AVAILABLE)
BOOST_STATIC_ASSERT(false);
#endif

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{
/**
 * @brief Convert a Robot Raconteur standard image to an OpenCV Mat
 *
 * Converts a com.robotraconteur.image.Image to an OpenCV Mat
 *
 * Currently supported Robot Raconteur encodings:
 * - rgb888
 * - rgba8888
 * - bgr888
 * - bgra8888
 * - mono8
 * - mono16, depth_u16
 * - mono32, depth_u32
 * - mono_f16
 * - mono_f32, depth_f32
 * - mono_f64, depth_f64
 *
 * @param image The com.robotraconteur.imaging.Image to convert
 * @return cv::Mat The OpenCV Mat
 */
static cv::Mat ImageToMat(const com::robotraconteur::image::ImagePtr& image)
{
    if (!image)
    {
        throw InvalidArgumentException("Image is null");
    }

    if (!image->image_info)
    {
        throw InvalidArgumentException("ImageInfo is null");
    }

    if (image->data->size() == 0)
    {
        throw InvalidArgumentException("Image data is empty");
    }

    size_t width = image->image_info->width;
    size_t height = image->image_info->height;
    size_t step = image->image_info->step;

    if (width <= 0 || height <= 0)
    {
        throw InvalidArgumentException("Invalid image dimensions");
    }

    int32_t mat_type = -1;
    switch (image->image_info->encoding)
    {
    case com::robotraconteur::image::ImageEncoding::rgb888: {
        if (step <= 0)
        {
            step = width * 3;
        }
        mat_type = CV_8UC3;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::rgba8888: {
        if (step <= 0)
        {
            step = width * 4;
        }
        mat_type = CV_8UC4;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::bgr888: {
        if (step <= 0)
        {
            step = width * 3;
        }
        mat_type = CV_8UC3;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::bgra8888: {
        if (step <= 0)
        {
            step = width * 4;
        }
        mat_type = CV_8UC4;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::mono8: {
        if (step <= 0)
        {
            step = width;
        }
        mat_type = CV_8UC1;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::mono16:
    case com::robotraconteur::image::ImageEncoding::depth_u16: {
        if (step <= 0)
        {
            step = width * 2;
        }
        mat_type = CV_16UC1;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::mono32:
    case com::robotraconteur::image::ImageEncoding::depth_u32: {
        if (step <= 0)
        {
            step = width * 4;
        }
        mat_type = CV_32SC1;
        break;
    }
#if !defined(CV_VERSION_EPOCH) && CV_VERSION_MAJOR >= 4
    case com::robotraconteur::image::ImageEncoding::mono_f16: {
        if (step <= 0)
        {
            step = width * 2;
        }
        mat_type = CV_16FC1;
        break;
    }
#endif
    case com::robotraconteur::image::ImageEncoding::depth_f32:
    case com::robotraconteur::image::ImageEncoding::mono_f32: {
        if (step <= 0)
        {
            step = width * 4;
        }
        mat_type = CV_32FC1;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::mono_f64:
    case com::robotraconteur::image::ImageEncoding::depth_f64: {
        if (step <= 0)
        {
            step = width * 8;
        }
        mat_type = CV_64FC1;
        break;
    }
    default:
        throw InvalidArgumentException("Unsupported image encoding");
    }

    size_t expected_bytes = step * height;
    if (expected_bytes != image->data->size())
    {
        throw InvalidArgumentException("Image data size does not match expected size");
    }

    cv::Mat mat(boost::numeric_cast<int>(height), boost::numeric_cast<int>(width), mat_type, image->data->data(), step);

    switch (image->image_info->encoding)
    {
    case com::robotraconteur::image::ImageEncoding::rgb888:
        cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
        break;
    case com::robotraconteur::image::ImageEncoding::rgba8888:
        cv::cvtColor(mat, mat, cv::COLOR_RGBA2BGRA);
        break;
    default:
        break;
    }

    return mat.clone();
}

/**
 * @brief Convert an OpenCV Mat to a Robot Raconteur standard image
 *
 * Converts an OpenCV Mat to a com.robotraconteur.image.Image
 *
 * Currently supported Robot Raconteur encodings:
 * - rgb888
 * - rgba8888
 * - bgr888
 * - bgra8888
 * - mono8
 * - mono16, depth_u16
 * - mono32, depth_u32
 * - mono_f16
 * - mono_f32, depth_f32
 * - mono_f64, depth_f64
 *
 * The format of the input Mat must match the specified encoding
 *
 * @param mat The OpenCV Mat to convert
 * @param encoding The desired Robot Raconteur image encoding
 * @return com::robotraconteur::image::ImagePtr The Robot Raconteur image
 */

static com::robotraconteur::image::ImagePtr MatToImage(
    const cv::Mat& mat, com::robotraconteur::image::ImageEncoding::ImageEncoding encoding)
{
    if (mat.empty())
    {
        throw InvalidArgumentException("Mat is empty");
    }

    if (mat.channels() <= 0)
    {
        throw InvalidArgumentException("Invalid number of channels");
    }

    if (mat.step[0] <= 0)
    {
        throw InvalidArgumentException("Invalid step");
    }

    com::robotraconteur::image::ImagePtr image(new com::robotraconteur::image::Image());
    com::robotraconteur::image::ImageInfoPtr image_info(new com::robotraconteur::image::ImageInfo());
    image->image_info = image_info;

    image_info->width = mat.cols;
    image_info->height = mat.rows;
    image_info->step = boost::numeric_cast<uint32_t>((size_t)mat.step[0]);
    image_info->encoding = encoding;

    int32_t mat_type = -1;
    size_t element_size = 0;

    switch (encoding)
    {
    case com::robotraconteur::image::ImageEncoding::rgb888: {
        mat_type = CV_8UC3;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::rgba8888: {
        mat_type = CV_8UC4;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::bgr888: {
        mat_type = CV_8UC3;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::bgra8888: {
        mat_type = CV_8UC4;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::mono8: {
        mat_type = CV_8UC1;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::mono16:
    case com::robotraconteur::image::ImageEncoding::depth_u16: {
        mat_type = CV_16UC1;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::mono32:
    case com::robotraconteur::image::ImageEncoding::depth_u32: {
        mat_type = CV_32SC1;
        break;
    }
#if !defined(CV_VERSION_EPOCH) && CV_VERSION_MAJOR >= 4
    case com::robotraconteur::image::ImageEncoding::mono_f16: {
        mat_type = CV_16FC1;
        break;
    }
#endif
    case com::robotraconteur::image::ImageEncoding::mono_f32:
    case com::robotraconteur::image::ImageEncoding::depth_f32: {
        mat_type = CV_32FC1;
        break;
    }
    case com::robotraconteur::image::ImageEncoding::mono_f64:
    case com::robotraconteur::image::ImageEncoding::depth_f64: {
        mat_type = CV_64FC1;
        break;
    }
    default:
        throw InvalidArgumentException("Unsupported image encoding");
    }

    if (mat.type() != mat_type)
    {
        throw InvalidArgumentException("Invalid image type passed for specified encoding");
    }
    RobotRaconteur::RRArrayPtr<uint8_t> rr_data =
        RobotRaconteur::AllocateRRArray<uint8_t>(mat.total() * mat.elemSize());
    cv::Mat rr_mat_target(mat.rows, mat.cols, mat_type, rr_data->data(), mat.step[0]);
    switch (encoding)
    {
    case com::robotraconteur::image::ImageEncoding::rgb888:
        cv::cvtColor(mat, rr_mat_target, cv::COLOR_BGR2RGB);
        break;
    case com::robotraconteur::image::ImageEncoding::rgba8888:
        cv::cvtColor(mat, rr_mat_target, cv::COLOR_BGRA2RGBA);
        break;
    default:
        mat.copyTo(rr_mat_target);
        break;
    }
    image->data = rr_data;

    return image;
}

#if !defined(CV_VERSION_EPOCH) && CV_VERSION_MAJOR >= 3

// doc
/**
 * @brief Convert an OpenCV Mat to a Robot Raconteur compressed image
 *
 * Converts an OpenCV Mat to a com.robotraconteur.image.CompressedImage
 *
 * The format of the input Mat must match the specified encoding
 *
 * Uses cv::imencode to compress the image
 *
 * @param ext The file extension for the desired encoding (e.g., ".jpg", ".png")
 * @param mat The OpenCV Mat to convert
 * @param params Optional parameters for cv::imencode
 * @return com::robotraconteur::image::CompressedImagePtr The Robot Raconteur compressed image
 */
static com::robotraconteur::image::CompressedImagePtr MatToCompressedImage(
    const std::string& ext, const cv::Mat& mat, const std::vector<int>& params = std::vector<int>())
{
    std::vector<uchar> encoded_buffer;
    bool success = cv::imencode(ext, mat, encoded_buffer, params);
    if (!success)
    {
        throw InvalidArgumentException("Failed to encode image to compressed format");
    }

    com::robotraconteur::image::CompressedImagePtr image(new com::robotraconteur::image::CompressedImage());
    com::robotraconteur::image::ImageInfoPtr image_info(new com::robotraconteur::image::ImageInfo());
    image->image_info = image_info;

    image_info->width = mat.cols;
    image_info->height = mat.rows;
    image_info->step = 0;
    image_info->encoding = com::robotraconteur::image::ImageEncoding::compressed;

    image->data = RobotRaconteur::AttachRRArrayCopy<uint8_t>((uint8_t*)&encoded_buffer[0], encoded_buffer.size());

    return image;
}

/**
 * @brief Convert a Robot Raconteur compressed image to an OpenCV Mat
 *
 * Converts a com.robotraconteur.image.CompressedImage to an OpenCV Mat
 *
 * The encoding must be supported by cv::imdecode
 *
 * Uses cv::imdecode to decompress the image
 *
 * @param image The com.robotraconteur.image.CompressedImage to convert
 * @return cv::Mat The OpenCV Mat
 */
static cv::Mat CompressedImageToMat(const com::robotraconteur::image::CompressedImagePtr& image)
{
    if (!image)
    {
        throw InvalidArgumentException("CompressedImage is null");
    }

    if (!image->image_info)
    {
        throw InvalidArgumentException("ImageInfo is null");
    }

    if (image->data->size() == 0)
    {
        throw InvalidArgumentException("CompressedImage data is empty");
    }

    // Create mat from the encoded data
    cv::Mat encoded_buffer(1, boost::numeric_cast<int>(image->data->size()), CV_8UC1, (void*)image->data->data());
    cv::Mat mat = cv::imdecode(encoded_buffer, cv::IMREAD_UNCHANGED);
    if (mat.empty())
    {
        throw InvalidArgumentException("Failed to decode CompressedImage data");
    }

    if (mat.cols != image->image_info->width || mat.rows != image->image_info->height)
    {
        throw InvalidArgumentException("Decoded image dimensions do not match ImageInfo");
    }

    if (mat.channels() <= 0)
    {
        throw InvalidArgumentException("Decoded image has invalid number of channels");
    }

    if (mat.step[0] <= 0)
    {
        throw InvalidArgumentException("Decoded image has invalid step");
    }

    return mat.clone();
}
#endif
} // namespace Util
} // namespace Companion
} // namespace RobotRaconteur
