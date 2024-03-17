/**
 * @file EigenConverters.h
 *
 * @author John Wason, PhD
 *
 * @copyright Copyright 2023 Wason Technology, LLC
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

#include <Eigen/Geometry>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <RobotRaconteur/DataTypes.h>
#include <RobotRaconteurCompanion/Util/UtilMacros.h>

#include <com__robotraconteur__geometry.h>

#pragma once

namespace RobotRaconteur
{
namespace Companion
{
namespace Converters
{
namespace Eigen
{
    
    template <typename T>
    class RRArrayEigenTraits
    {

    };

    template <typename T, int N>
    class RRArrayEigenTraits<::Eigen::Matrix<T,N,1> >
    {
    public:
        typedef RobotRaconteur::RRArrayPtr<T> RRArrayPtrType;
        typedef T NumberType;
        enum { Rows = N };

        static ::Eigen::Matrix<T,N,1> CopyToEigen(RRArrayPtrType rr_array)
        {
            RobotRaconteur::rr_null_check(rr_array);
            if (rr_array->size() != N)
            {
                throw RobotRaconteur::InvalidArgumentException("Invalid array length for Eigen vector, expected " 
                    + boost::lexical_cast<std::string>(N) + " got " + boost::lexical_cast<std::string>(rr_array->size()));
            }

            return ::Eigen::Map<::Eigen::Matrix<T,N,1> >(rr_array->data());
        }
    };

    template <typename T>
    class RRArrayEigenTraits<::Eigen::Matrix<T,::Eigen::Dynamic,1> >
    {
    public:
        typedef RobotRaconteur::RRArrayPtr<T> RRArrayPtrType;
        typedef T NumberType;

        static ::Eigen::Matrix<T,::Eigen::Dynamic,1> CopyToEigen(RRArrayPtrType rr_array)
        {
            RobotRaconteur::rr_null_check(rr_array);
            
            return ::Eigen::Map<::Eigen::Matrix<T,::Eigen::Dynamic,1> >(rr_array->data(),rr_array->size());
        }        
    };


    /**
     * @brief Convert Eigen vector to RRArray
     * 
     * @tparam T Numeric type
     * @tparam N Size of vector
     * @param eigen_in The Eigen vector
     * @return RobotRaconteur::RRArrayPtr<T> The RRArray
     */
    template<typename T, int N>
    RobotRaconteur::RRArrayPtr<T> EigenToRRArray(const ::Eigen::Matrix<T,N,1>& eigen_in)
    {        
        return RobotRaconteur::AttachRRArrayCopy<T>(eigen_in.data(),eigen_in.rows());
    }

    /**
     * @brief Convert RRArray to Eigen vector
     * 
     * @tparam T Desired Eigen type
     * @param rr_array The RRArray
     * @return T The Eigen result
     */
    template<typename T>
    T RRArrayToEigen(typename RRArrayEigenTraits<T>::RRArrayPtrType rr_array)
    {
        return RRArrayEigenTraits<T>::CopyToEigen(rr_array);
    }

    /**
     * @brief Convert Eigen matrix to RRMultiDimArray
     * 
     * @tparam T The numeric type
     * @param eigen_in The Eigen matrix
     * @return RobotRaconteur::RRMultiDimArrayPtr<T> The RRMultiDimArray
     */
    template<typename T, int R, int C>
    RobotRaconteur::RRMultiDimArrayPtr<T> EigenToRRMultiDimArray(const ::Eigen::Matrix<T,R,C>& eigen_in)
    {
        std::vector<uint32_t> dims {(uint32_t)eigen_in.rows(),(uint32_t)eigen_in.cols()};
        RobotRaconteur::RRMultiDimArrayPtr<T> out = RobotRaconteur::AllocateEmptyRRMultiDimArray<T>(dims);
        ::Eigen::Matrix<T,::Eigen::Dynamic,::Eigen::Dynamic, ::Eigen::ColMajor> eigen_in2 = eigen_in;
        size_t total_elems = eigen_in.rows() * eigen_in.cols();
        memcpy(&out->Array->at(0),eigen_in2.data(),sizeof(T)*total_elems);
        return out;
    }

    /**
     * @brief Convert RRMultiDimArray to Eigen matrix
     * 
     * @tparam T The numeric type
     * @param array_in The RRMultiDimArray
     * @return ::Eigen::Matrix<T,::Eigen::Dynamic,::Eigen::Dynamic> The Eigen result
     */
    template<typename T>
    ::Eigen::Matrix<T,::Eigen::Dynamic,::Eigen::Dynamic> RRMultiDimArrayToEigen(RobotRaconteur::RRMultiDimArrayPtr<T> array_in)
    {
        RobotRaconteur::rr_null_check(array_in);
        RobotRaconteur::rr_null_check(array_in->Dims);
        RobotRaconteur::rr_null_check(array_in->Array);

        switch (array_in->Dims->size())
        {
            case 0:
                throw RobotRaconteur::InvalidArgumentException("Invalid matrix dimensions");
            case 1:
            {
                ::Eigen::Matrix<T,::Eigen::Dynamic,::Eigen::Dynamic,::Eigen::ColMajor> o(array_in->Dims->at(0), 1);
                memcpy(o.data(), array_in->Array->data(), sizeof(T)*array_in->Array->size());
                return o;
            }
            case 2:
            {
                ::Eigen::Matrix<T,::Eigen::Dynamic,::Eigen::Dynamic,::Eigen::ColMajor> o(array_in->Dims->at(0), array_in->Dims->at(1));
                memcpy(o.data(), array_in->Array->data(), sizeof(T)*array_in->Array->size());
                return o;
            }
            default:
                throw RobotRaconteur::InvalidArgumentException("Invalid matrix dimensions");
        }
    }

    /**
     * @brief Convert Eigen vector to com::robotraconteur::geometry::Vector2
     * 
     * @param vs The Eigen vector with 2 elements
     * @return com::robotraconteur::geometry::Vector2 The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Vector2 ToVector2(const ::Eigen::Ref<const ::Eigen::Vector2d>& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::Vector2 to Eigen vector
     * 
     * @param vs The com::robotraconteur::geometry::Vector2
     * @return ::Eigen::Vector2d The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Vector2d ToVector(const com::robotraconteur::geometry::Vector2& vs);

    /**
     * @brief Convert Eigen vector to com::robotraconteur::geometry::Vector3
     * 
     * @param vs The Eigen vector with 3 elements
     * @return com::robotraconteur::geometry::Vector3 The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Vector3 ToVector3(const ::Eigen::Ref<const ::Eigen::Vector3d>& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::Vector3 to Eigen vector
     * 
     * @param vs The com::robotraconteur::geometry::Vector3
     * @return ::Eigen::Vector3d The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Vector3d ToVector(const com::robotraconteur::geometry::Vector3& vs);

    /**
     * @brief Convert Eigen vector to com::robotraconteur::geometry::Vector6
     * 
     * @param vs The Eigen vector with 6 elements
     * @return com::robotraconteur::geometry::Vector6 The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Vector6 ToVector6(const ::Eigen::Ref<const ::Eigen::Matrix<double,6,1> >& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::Vector6 to Eigen vector
     * 
     * @param vs The com::robotraconteur::geometry::Vector6
     * @return ::Eigen::Matrix<double,6,1> The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::Vector6& vs);

    /**
     * @brief Convert Eigen vector with 2 elements to com::robotraconteur::geometry::Point2D
     * 
     * @param vs The Eigen vector with 2 elements
     * @return com::robotraconteur::geometry::Point2D The result point
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Point2D ToPoint2D(const ::Eigen::Ref<const ::Eigen::Vector2d>& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::Point2D to Eigen vector
     * 
     * @param vs The com::robotraconteur::geometry::Point2D
     * @return ::Eigen::Vector2d The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Vector2d ToVector(const com::robotraconteur::geometry::Point2D& vs);

    /**
     * @brief Convert Eigen vector with 3 elements to com::robotraconteur::geometry::Point
     * 
     * @param vs The Eigen vector with 3 elements
     * @return com::robotraconteur::geometry::Point The result point
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Point ToPoint(const ::Eigen::Ref<const ::Eigen::Vector3d>& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::Point to Eigen vector with 3 elements
     * 
     * @param vs The com::robotraconteur::geometry::Point
     * @return ::Eigen::Vector3d The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Vector3d ToVector(const com::robotraconteur::geometry::Point& vs);

    /**
     * @brief Convert Eigen vector with 2 elements to com::robotraconteur::geometry::Size2D
     * 
     * @param vs The Eigen vector with 2 elements
     * @return com::robotraconteur::geometry::Size2D The result size
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Size2D ToSize2D(const ::Eigen::Ref<const ::Eigen::Vector2d>& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::Size2D to Eigen vector with 2 elements
     * 
     * @param vs The com::robotraconteur::geometry::Size2D
     * @return ::Eigen::Vector2d The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Vector2d ToVector(const com::robotraconteur::geometry::Size2D& vs);

    /**
     * @brief Convert Eigen vector with 3 elements to com::robotraconteur::geometry::Size
     * 
     * @param vs The Eigen vector with 3 elements
     * @return com::robotraconteur::geometry::Size The result size
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Size ToSize(const ::Eigen::Ref<const ::Eigen::Vector3d>& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::Size to Eigen vector with 3 elements
     * 
     * @param vs The com::robotraconteur::geometry::Size
     * @return ::Eigen::Vector3d The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Vector3d ToVector(const com::robotraconteur::geometry::Size& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::Quaternion to Eigen Quaternion
     * 
     * @param q The com::robotraconteur::geometry::Quaternion
     * @return ::Eigen::Quaterniond The result Eigen Quaternion
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Quaterniond ToQuaternion(const com::robotraconteur::geometry::Quaternion& q);

    /**
     * @brief Convert Eigen Quaternion to com::robotraconteur::geometry::Quaternion
     * 
     * @param q The Eigen Quaternion
     * @return com::robotraconteur::geometry::Quaternion The result com::robotraconteur::geometry::Quaternion
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Quaternion ToQuaternion(const ::Eigen::Quaterniond& q);

    /**
     * @brief Convert com::robotraconteur::geometry::Transform to Eigen Isometry
     * 
     * @param t The com::robotraconteur::geometry::Transform
     * @return ::Eigen::Isometry3d The result Eigen Isometry
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Isometry3d ToIsometry(const com::robotraconteur::geometry::Transform& t);

    /**
     * @brief Convert Eigen Isometry to com::robotraconteur::geometry::Transform
     * 
     * @param iso The Eigen Isometry
     * @return com::robotraconteur::geometry::Transform The result com::robotraconteur::geometry::Transform
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Transform ToTransform(const ::Eigen::Isometry3d& iso);

    /**
     * @brief Convert com::robotraconteur::geometry::Pose to Eigen Isometry
     * 
     * @param t The com::robotraconteur::geometry::Pose
     * @return ::Eigen::Isometry3d The result Eigen Isometry
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Isometry3d ToIsometry(const com::robotraconteur::geometry::Pose& t);

    /**
     * @brief Convert Eigen Isometry to com::robotraconteur::geometry::Pose
     * 
     * @param iso The Eigen Isometry
     * @return com::robotraconteur::geometry::Pose The result com::robotraconteur::geometry::Pose
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Pose ToPose(const ::Eigen::Isometry3d& iso);

    /**
     * @brief Convert Eigen Vector with 6 elements to com::robotraconteur::geometry::SpatialVelocity
     * 
     * @param vs The Eigen vector with 6 elements
     * @return com::robotraconteur::geometry::SpatialVelocity The result com::robotraconteur::geometry::SpatialVelocity
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::SpatialVelocity ToSpatialVelocity(const ::Eigen::Ref<const ::Eigen::Matrix<double,6,1> >& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::SpatialVelocity to Eigen vector with 6 elements
     * 
     * @param vs The com::robotraconteur::geometry::SpatialVelocity
     * @return ::Eigen::Matrix<double,6,1> The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::SpatialVelocity& vs);

    /**
     * @brief Convert Eigen Vector with 6 elements to com::robotraconteur::geometry::SpatialAcceleration
     * 
     * @param vs The Eigen vector with 6 elements
     * @return com::robotraconteur::geometry::SpatialAcceleration The result com::robotraconteur::geometry::SpatialAcceleration
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::SpatialAcceleration ToSpatialAcceleration(const ::Eigen::Ref<const ::Eigen::Matrix<double,6,1> >& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::SpatialAcceleration to Eigen vector with 6 elements
     * 
     * @param vs The com::robotraconteur::geometry::SpatialAcceleration
     * @return ::Eigen::Matrix<double,6,1> The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::SpatialAcceleration& vs);

    /**
     * @brief Convert Eigen Vector with 6 elements to com::robotraconteur::geometry::Wrench
     * 
     * @param vs The Eigen vector with 6 elements
     * @return com::robotraconteur::geometry::Wrench The result com::robotraconteur::geometry::Wrench
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API com::robotraconteur::geometry::Wrench ToWrench(const ::Eigen::Ref<const ::Eigen::Matrix<double,6,1> >& vs);

    /**
     * @brief Convert com::robotraconteur::geometry::Wrench to Eigen vector with 6 elements
     * 
     * @param vs The com::robotraconteur::geometry::Wrench
     * @return ::Eigen::Matrix<double,6,1> The result vector
     */
    ROBOTRACONTEUR_COMPANION_UTIL_API ::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::Wrench& vs);

}
}
}
}

