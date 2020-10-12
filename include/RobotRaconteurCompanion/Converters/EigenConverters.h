#include <Eigen/Geometry>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <RobotRaconteur/DataTypes.h>

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


    template<typename T, int N>
    RobotRaconteur::RRArrayPtr<T> EigenToRRArray(const ::Eigen::Matrix<T,N,1>& eigen_in)
    {        
        return RobotRaconteur::AttachRRArrayCopy<T>(eigen_in.data(),eigen_in.rows());
    }

    template<typename T>
    T RRArrayToEigen(typename RRArrayEigenTraits<T>::RRArrayPtrType rr_array)
    {
        return RRArrayEigenTraits<T>::CopyToEigen(rr_array);
    }

    template<typename T>
    RobotRaconteur::RRMultiDimArrayPtr<T> EigenToRRMultiDimArray(const ::Eigen::Matrix<T,::Eigen::Dynamic,::Eigen::Dynamic>& eigen_in)
    {
        std::vector<uint32_t> dims {(uint32_t)eigen_in.rows(),(uint32_t)eigen_in.cols()};
        RobotRaconteur::RRMultiDimArrayPtr<T> out = RobotRaconteur::AllocateEmptyRRMultiDimArray<T>(dims);
        ::Eigen::Matrix<T,::Eigen::Dynamic,::Eigen::Dynamic, ::Eigen::ColMajor> eigen_in2 = eigen_in;
        size_t total_elems = eigen_in.rows() * eigen_in.cols();
        memcpy(&out->Array->at(0),eigen_in2.data(),sizeof(T)*total_elems);
        return out;
    }

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

    static com::robotraconteur::geometry::Vector2 ToVector2(::Eigen::Ref<::Eigen::Vector2d> vs)
    {
        com::robotraconteur::geometry::Vector2 o;
        o.s.x = vs[0];
        o.s.y = vs[1];
        return o;
    }

    static ::Eigen::Vector2d ToVector(const com::robotraconteur::geometry::Vector2& vs)
    {
        ::Eigen::Vector2d o;
        o[0] = vs.s.x;
        o[1] = vs.s.y;
        return o;
    }

    static com::robotraconteur::geometry::Vector3 ToVector3(::Eigen::Ref<::Eigen::Vector3d> vs)
    {
        com::robotraconteur::geometry::Vector3 o;
        o.s.x = vs[0];
        o.s.y = vs[1];
        o.s.z = vs[2];
        return o;
    }

    static ::Eigen::Vector3d ToVector(const com::robotraconteur::geometry::Vector3& vs)
    {
        ::Eigen::Vector3d o;
        o[0] = vs.s.x;
        o[1] = vs.s.y;
        o[2] = vs.s.z;
        return o;
    }

    static com::robotraconteur::geometry::Vector6 ToVector6(::Eigen::Ref<::Eigen::Matrix<double,6,1> > vs)
    {
        com::robotraconteur::geometry::Vector6 o;
        o.s.alpha = vs[0];
        o.s.beta = vs[1];
        o.s.gamma = vs[2];
        o.s.x = vs[3];
        o.s.y = vs[4];
        o.s.y = vs[5];
        return o;
    }

    static ::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::Vector6& vs)
    {
        ::Eigen::Matrix<double,6,1> o;
        o[0] = vs.s.alpha;
        o[1] = vs.s.beta;
        o[2] = vs.s.gamma;
        o[3] = vs.s.x;
        o[4] = vs.s.y;
        o[5] = vs.s.z;
        return o;
    }

    static com::robotraconteur::geometry::Point2D ToPoint2D(::Eigen::Ref<::Eigen::Vector2d> vs)
    {
        com::robotraconteur::geometry::Point2D o;
        o.s.x = vs[0];
        o.s.y = vs[1];
        return o;
    }

    static ::Eigen::Vector2d ToVector(const com::robotraconteur::geometry::Point2D& vs)
    {
        ::Eigen::Vector2d o;
        o[0] = vs.s.x;
        o[1] = vs.s.y;
        return o;
    }

    static com::robotraconteur::geometry::Point ToPoint(::Eigen::Ref<::Eigen::Vector3d> vs)
    {
        com::robotraconteur::geometry::Point o;
        o.s.x = vs[0];
        o.s.y = vs[1];
        o.s.z = vs[2];
        return o;
    }

    static ::Eigen::Vector3d ToVector(const com::robotraconteur::geometry::Point& vs)
    {
        ::Eigen::Vector3d o;
        o[0] = vs.s.x;
        o[1] = vs.s.y;
        o[2] = vs.s.z;
        return o;
    }

    static com::robotraconteur::geometry::Size2D ToSize2D(::Eigen::Ref<::Eigen::Vector2d> vs)
    {
        com::robotraconteur::geometry::Size2D o;
        o.s.width = vs[0];
        o.s.height = vs[1];
        return o;
    }

    static ::Eigen::Vector2d ToVector(const com::robotraconteur::geometry::Size2D& vs)
    {
        ::Eigen::Vector2d o;
        o[0] = vs.s.width;
        o[1] = vs.s.height;
        return o;
    }

    static com::robotraconteur::geometry::Size ToSize(::Eigen::Ref<::Eigen::Vector3d> vs)
    {
        com::robotraconteur::geometry::Size o;
        o.s.width = vs[0];
        o.s.height = vs[1];
        o.s.depth = vs[2];
        return o;
    }

    static ::Eigen::Vector3d ToVector(const com::robotraconteur::geometry::Size& vs)
    {
        ::Eigen::Vector3d o;
        o[0] = vs.s.width;
        o[1] = vs.s.depth;
        o[2] = vs.s.height;
        return o;
    }

    static ::Eigen::Quaterniond ToQuaternion(const com::robotraconteur::geometry::Quaternion& q)
    {
        if (q.s.x == 0 && q.s.y == 0 && q.s.z == 0 && q.s.w == 0)
        {
            return ::Eigen::Quaterniond();
        }

        return ::Eigen::Quaterniond(q.s.w, q.s.x, q.s.y, q.s.z);
    }

    static com::robotraconteur::geometry::Quaternion ToQuaternion(const ::Eigen::Quaterniond& q)
    {
        com::robotraconteur::geometry::Quaternion o;
        o.s.w = q.w();
        o.s.x = q.x();
        o.s.y = q.y();
        o.s.z = q.z();
        return o;
    }

    static ::Eigen::Isometry3d ToIsometry(const com::robotraconteur::geometry::Transform& t)
    {
        return ::Eigen::Translation3d(ToVector(t.s.translation)) * ToQuaternion(t.s.rotation);        
    }

    static com::robotraconteur::geometry::Transform ToTransform(::Eigen::Isometry3d iso)
    {
        com::robotraconteur::geometry::Transform o;
        ::Eigen::Quaterniond q = (::Eigen::Quaterniond)iso.linear();
        o.s.rotation = ToQuaternion(q);
        ::Eigen::Vector3d p = (::Eigen::Vector3d)iso.translation();
        o.s.translation = ToVector3(p);
        return o;
    }

    static ::Eigen::Isometry3d ToIsometry(const com::robotraconteur::geometry::Pose& t)
    {
        return ::Eigen::Translation3d(ToVector(t.s.position)) * ToQuaternion(t.s.orientation);        
    }

    static com::robotraconteur::geometry::Pose ToPose(::Eigen::Isometry3d iso)
    {
        com::robotraconteur::geometry::Pose o;
        ::Eigen::Quaterniond q = (::Eigen::Quaterniond)iso.linear();
        o.s.orientation = ToQuaternion(q);
        ::Eigen::Vector3d p = (::Eigen::Vector3d)iso.translation();
        o.s.position = ToPoint(p);
        return o;
    }

    static com::robotraconteur::geometry::SpatialVelocity ToSpatialVelocity(::Eigen::Ref<::Eigen::Matrix<double,6,1> > vs)
    {
        com::robotraconteur::geometry::SpatialVelocity o;
        o.s.angular.s.x = vs[0];
        o.s.angular.s.y = vs[1];
        o.s.angular.s.z = vs[2];
        o.s.linear.s.x = vs[3];
        o.s.linear.s.y = vs[4];
        o.s.linear.s.z = vs[5];
        return o;
    }

    static ::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::SpatialVelocity& vs)
    {
        ::Eigen::Matrix<double,6,1> o;
        o[0] = vs.s.angular.s.x;
        o[1] = vs.s.angular.s.y;
        o[2] = vs.s.angular.s.z;
        o[3] = vs.s.linear.s.x;
        o[4] = vs.s.linear.s.y;
        o[5] = vs.s.linear.s.z;
        return o;
    }

    static com::robotraconteur::geometry::SpatialAcceleration ToSpatialAcceleration(::Eigen::Ref<::Eigen::Matrix<double,6,1> > vs)
    {
        com::robotraconteur::geometry::SpatialAcceleration o;
        o.s.angular.s.x = vs[0];
        o.s.angular.s.y = vs[1];
        o.s.angular.s.z = vs[2];
        o.s.linear.s.x = vs[3];
        o.s.linear.s.y = vs[4];
        o.s.linear.s.z = vs[5];
        return o;
    }

    static ::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::SpatialAcceleration& vs)
    {
        ::Eigen::Matrix<double,6,1> o;
        o[0] = vs.s.angular.s.x;
        o[1] = vs.s.angular.s.y;
        o[2] = vs.s.angular.s.z;
        o[3] = vs.s.linear.s.x;
        o[4] = vs.s.linear.s.y;
        o[5] = vs.s.linear.s.z;
        return o;
    }

    static com::robotraconteur::geometry::Wrench ToWrench(::Eigen::Ref<::Eigen::Matrix<double,6,1> > vs)
    {
        com::robotraconteur::geometry::Wrench o;
        o.s.torque.s.x = vs[0];
        o.s.torque.s.y = vs[1];
        o.s.torque.s.z = vs[2];
        o.s.force.s.x = vs[3];
        o.s.force.s.y = vs[4];
        o.s.force.s.z = vs[5];
        return o;
    }

    static ::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::Wrench& vs)
    {
        ::Eigen::Matrix<double,6,1> o;
        o[0] = vs.s.torque.s.x;
        o[1] = vs.s.torque.s.y;
        o[2] = vs.s.torque.s.z;
        o[3] = vs.s.force.s.x;
        o[4] = vs.s.force.s.y;
        o[5] = vs.s.force.s.z;
        return o;
    }




}
}
}
}

