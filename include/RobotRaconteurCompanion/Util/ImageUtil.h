#include "com__robotraconteur__image.h"

#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>

#pragma once

#include <boost/predef/other/endian.h>

#if !defined(BOOST_ENDIAN_LITTLE_WORD) 
BOOST_STATIC_ASSERT(false);
#endif

namespace RobotRaconteur
{
namespace Companion
{
namespace Util
{ 
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

        int32_t width = image->image_info->width;
        int32_t height = image->image_info->height;
        int32_t step = image->image_info->step;

        if (width <= 0 || height <= 0)
        {
            throw InvalidArgumentException("Invalid image dimensions");
        }

        int32_t mat_type = -1;
        switch (image->image_info->encoding)
        {
        case com::robotraconteur::image::ImageEncoding::rgb888:
        {
            if (step <= 0)
            {
                step = width * 3;
            }
            mat_type = CV_8UC3;
            break;
        }
        case com::robotraconteur::image::ImageEncoding::rgba8888:
        {
            if (step <= 0)
            {
                step = width * 4;
            }
            mat_type = CV_8UC4;
            break;
        }
        case com::robotraconteur::image::ImageEncoding::bgr888:
        {
            if (step <= 0)
            {
                step = width * 3;
            }
            mat_type = CV_8UC3;
            break;
        }
        case com::robotraconteur::image::ImageEncoding::bgra8888:
        {
            if (step <= 0)
            {
                step = width * 4;
            }
            mat_type = CV_8UC4;
            break;
        }
        case com::robotraconteur::image::ImageEncoding::mono8:
        {
            if (step <= 0)
            {
                step = width;
            }
            mat_type = CV_8UC1;
            break;
        }
        case com::robotraconteur::image::ImageEncoding::mono16:
        case com::robotraconteur::image::ImageEncoding::depth_u16:
        {
            if (step <= 0)
            {
                step = width * 2;
            }
            mat_type = CV_16UC1;
            break;
        }
        case com::robotraconteur::image::ImageEncoding::mono32:
        case com::robotraconteur::image::ImageEncoding::depth_u32:
        {
            if (step <= 0)
            {
                step = width * 4;
            }
            mat_type = CV_32SC1;
            break;
        }
        case com::robotraconteur::image::ImageEncoding::mono_f16:
        {
            if (step <= 0)
            {
                step = width * 2;
            }
            mat_type = CV_16FC1;
            break;
        }
        case com::robotraconteur::image::ImageEncoding::depth_f32:
        {
            if (step <= 0)
            {
                step = width * 4;
            }
            mat_type = CV_32FC1;
            break;
        }
        default:
            throw InvalidArgumentException("Unsupported image encoding");
        }

        cv::Mat mat(height, width, mat_type, image->data->data(), step);

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

    static com::robotraconteur::image::ImagePtr MatToImage(const cv::Mat& mat, com::robotraconteur::image::ImageEncoding::ImageEncoding encoding)
    {
        if (mat.empty())
        {
            throw InvalidArgumentException("Mat is empty");
        }

        if (mat.channels() <= 0)
        {
            throw InvalidArgumentException("Invalid number of channels");
        }

        if (mat.depth() <= 0)
        {
            throw InvalidArgumentException("Invalid depth");
        }

        if (mat.step <= 0)
        {
            throw InvalidArgumentException("Invalid step");
        }

        com::robotraconteur::image::ImagePtr image(new com::robotraconteur::image::Image());
        com::robotraconteur::image::ImageInfoPtr image_info(new com::robotraconteur::image::ImageInfo());
        image->image_info = image_info;

        image_info->width = mat.cols;
        image_info->height = mat.rows;
        image_info->step = boost::numeric_cast<uint32_t>((size_t)mat.step);
        image_info->encoding = encoding;

        switch (encoding)
        {
        case com::robotraconteur::image::ImageEncoding::rgb888:
        {
            if (mat.type() != CV_8UC3)
            {
                throw InvalidArgumentException("Invalid image type passed for encoding rgb888");
            }
            RobotRaconteur::RRArrayPtr<uint8_t> rr_data = RobotRaconteur::AllocateRRArray<uint8_t>(mat.total());
            cv::Mat rr_mat_target(mat.rows, mat.cols, CV_8UC3, rr_data->data(), mat.step);
            cv::cvtColor(mat, rr_mat_target, cv::COLOR_BGR2RGB);
            image->data = rr_data;
            return image;
        }
        case com::robotraconteur::image::ImageEncoding::rgba8888:
        {
            if (mat.type() != CV_8UC4)
            {
                throw InvalidArgumentException("Invalid image type passed for encoding rgba8888");
            }
            RobotRaconteur::RRArrayPtr<uint8_t> rr_data = RobotRaconteur::AllocateRRArray<uint8_t>(mat.total());
            cv::Mat rr_mat_target(mat.rows, mat.cols, CV_8UC4, rr_data->data(), mat.step);
            cv::cvtColor(mat, rr_mat_target, cv::COLOR_BGRA2RGBA);
            image->data = rr_data;
            return image;
        }
        case com::robotraconteur::image::ImageEncoding::bgr888:
        {
            if (mat.type() != CV_8UC3)
            {
                throw InvalidArgumentException("Invalid image type passed for encoding bgr888");
            }
            RobotRaconteur::RRArrayPtr<uint8_t> rr_data = RobotRaconteur::AllocateRRArray<uint8_t>(mat.total());
            cv::Mat rr_mat_target(mat.rows, mat.cols, CV_8UC3, rr_data->data(), mat.step);
            mat.copyTo(rr_mat_target);
            image->data = rr_data;
            return image;
        }
        case com::robotraconteur::image::ImageEncoding::bgra8888:
        {
            if (mat.type() != CV_8UC4)
            {
                throw InvalidArgumentException("Invalid image type passed for encoding bgra8888");
            }
            RobotRaconteur::RRArrayPtr<uint8_t> rr_data = RobotRaconteur::AllocateRRArray<uint8_t>(mat.total());
            cv::Mat rr_mat_target(mat.rows, mat.cols, CV_8UC4, rr_data->data(), mat.step);
            mat.copyTo(rr_mat_target);
            image->data = rr_data;
            return image;
        }
        case com::robotraconteur::image::ImageEncoding::mono8:
        {
            if (mat.type() != CV_8UC1)
            {
                throw InvalidArgumentException("Invalid image type passed for encoding mono8");
            }
            RobotRaconteur::RRArrayPtr<uint8_t> rr_data = RobotRaconteur::AllocateRRArray<uint8_t>(mat.total());
            cv::Mat rr_mat_target(mat.rows, mat.cols, CV_8UC1, rr_data->data(), mat.step);
            mat.copyTo(rr_mat_target);
            image->data = rr_data;
            return image;
        }
        case com::robotraconteur::image::ImageEncoding::mono16:
        case com::robotraconteur::image::ImageEncoding::depth_u16:
        {
            if (mat.type() != CV_16UC1)
            {
                throw InvalidArgumentException("Invalid image type passed for encoding mono16");
            }
            RobotRaconteur::RRArrayPtr<uint8_t> rr_data = RobotRaconteur::AllocateRRArray<uint8_t>(mat.total() * 2);
            cv::Mat rr_mat_target(mat.rows, mat.cols, CV_16UC1, rr_data->data(), mat.step);
            mat.copyTo(rr_mat_target);
            image->data = rr_data;
            return image;
        }
        case com::robotraconteur::image::ImageEncoding::mono32:
        case com::robotraconteur::image::ImageEncoding::depth_u32:
        {
            if (mat.type() != CV_32SC1)
            {
                throw InvalidArgumentException("Invalid image type passed for encoding mono32");
            }
            RobotRaconteur::RRArrayPtr<uint8_t> rr_data = RobotRaconteur::AllocateRRArray<uint8_t>(mat.total() * 4);
            cv::Mat rr_mat_target(mat.rows, mat.cols, CV_32SC1, rr_data->data(), mat.step);
            mat.copyTo(rr_mat_target);
            image->data = rr_data;
            return image;
        }
        case com::robotraconteur::image::ImageEncoding::depth_f32:
        {
            if (mat.type() != CV_32FC1)
            {
                throw InvalidArgumentException("Invalid image type passed for encoding depth_f32");
            }
            RobotRaconteur::RRArrayPtr<uint8_t> rr_data = RobotRaconteur::AllocateRRArray<uint8_t>(mat.total() * 4);
            cv::Mat rr_mat_target(mat.rows, mat.cols, CV_32FC1, rr_data->data(), mat.step);
            mat.copyTo(rr_mat_target);
            image->data = rr_data;
            return image;
        }
        default:
            throw InvalidArgumentException("Unsupported image encoding");
        }
    }
}
}
}
