/**
 * @file EigenConverters.cpp
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

#include "RobotRaconteurCompanion/Converters/EigenConverters.h"

namespace RobotRaconteur
{
namespace Companion
{
namespace Converters
{
namespace Eigen
{

com::robotraconteur::geometry::Vector2 ToVector2(const ::Eigen::Ref<const ::Eigen::Vector2d>& vs)
{
    com::robotraconteur::geometry::Vector2 o{};
    o.s.x = vs[0];
    o.s.y = vs[1];
    return o;
}

::Eigen::Vector2d ToVector(const com::robotraconteur::geometry::Vector2& vs)
{
    ::Eigen::Vector2d o;
    o[0] = vs.s.x;
    o[1] = vs.s.y;
    return o;
}

com::robotraconteur::geometry::Vector3 ToVector3(const ::Eigen::Ref<const ::Eigen::Vector3d>& vs)
{
    com::robotraconteur::geometry::Vector3 o{};
    o.s.x = vs[0];
    o.s.y = vs[1];
    o.s.z = vs[2];
    return o;
}

::Eigen::Vector3d ToVector(const com::robotraconteur::geometry::Vector3& vs)
{
    ::Eigen::Vector3d o;
    o[0] = vs.s.x;
    o[1] = vs.s.y;
    o[2] = vs.s.z;
    return o;
}

com::robotraconteur::geometry::Vector6 ToVector6(const ::Eigen::Ref<const ::Eigen::Matrix<double,6,1> >& vs)
{
    com::robotraconteur::geometry::Vector6 o{};
    o.s.alpha = vs[0];
    o.s.beta = vs[1];
    o.s.gamma = vs[2];
    o.s.x = vs[3];
    o.s.y = vs[4];
    o.s.y = vs[5];
    return o;
}

::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::Vector6& vs)
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

com::robotraconteur::geometry::Point2D ToPoint2D(const ::Eigen::Ref<const ::Eigen::Vector2d>& vs)
{
    com::robotraconteur::geometry::Point2D o{};
    o.s.x = vs[0];
    o.s.y = vs[1];
    return o;
}

::Eigen::Vector2d ToVector(const com::robotraconteur::geometry::Point2D& vs)
{
    ::Eigen::Vector2d o;
    o[0] = vs.s.x;
    o[1] = vs.s.y;
    return o;
}

com::robotraconteur::geometry::Point ToPoint(const ::Eigen::Ref<const ::Eigen::Vector3d>& vs)
{
    com::robotraconteur::geometry::Point o{};
    o.s.x = vs[0];
    o.s.y = vs[1];
    o.s.z = vs[2];
    return o;
}

::Eigen::Vector3d ToVector(const com::robotraconteur::geometry::Point& vs)
{
    ::Eigen::Vector3d o;
    o[0] = vs.s.x;
    o[1] = vs.s.y;
    o[2] = vs.s.z;
    return o;
}

com::robotraconteur::geometry::Size2D ToSize2D(const ::Eigen::Ref<const ::Eigen::Vector2d>& vs)
{
    com::robotraconteur::geometry::Size2D o{};
    o.s.width = vs[0];
    o.s.height = vs[1];
    return o;
}

::Eigen::Vector2d ToVector(const com::robotraconteur::geometry::Size2D& vs)
{
    ::Eigen::Vector2d o;
    o[0] = vs.s.width;
    o[1] = vs.s.height;
    return o;
}

com::robotraconteur::geometry::Size ToSize(const ::Eigen::Ref<const ::Eigen::Vector3d>& vs)
{
    com::robotraconteur::geometry::Size o{};
    o.s.width = vs[0];
    o.s.height = vs[1];
    o.s.depth = vs[2];
    return o;
}

::Eigen::Vector3d ToVector(const com::robotraconteur::geometry::Size& vs)
{
    ::Eigen::Vector3d o;
    o[0] = vs.s.width;
    o[1] = vs.s.depth;
    o[2] = vs.s.height;
    return o;
}

::Eigen::Quaterniond ToQuaternion(const com::robotraconteur::geometry::Quaternion& q)
{
    if (q.s.x == 0 && q.s.y == 0 && q.s.z == 0 && q.s.w == 0)
    {
        return ::Eigen::Quaterniond();
    }

    return ::Eigen::Quaterniond(q.s.w, q.s.x, q.s.y, q.s.z);
}

com::robotraconteur::geometry::Quaternion ToQuaternion(const ::Eigen::Quaterniond& q)
{
    com::robotraconteur::geometry::Quaternion o{};
    o.s.w = q.w();
    o.s.x = q.x();
    o.s.y = q.y();
    o.s.z = q.z();
    return o;
}

::Eigen::Isometry3d ToIsometry(const com::robotraconteur::geometry::Transform& t)
{
    return ::Eigen::Translation3d(ToVector(t.s.translation)) * ToQuaternion(t.s.rotation);        
}

com::robotraconteur::geometry::Transform ToTransform(const ::Eigen::Isometry3d& iso)
{
    com::robotraconteur::geometry::Transform o{};
    ::Eigen::Quaterniond q = (::Eigen::Quaterniond)iso.linear();
    o.s.rotation = ToQuaternion(q);
    ::Eigen::Vector3d p = (::Eigen::Vector3d)iso.translation();
    o.s.translation = ToVector3(p);
    return o;
}

::Eigen::Isometry3d ToIsometry(const com::robotraconteur::geometry::Pose& t)
{
    return ::Eigen::Translation3d(ToVector(t.s.position)) * ToQuaternion(t.s.orientation);        
}

com::robotraconteur::geometry::Pose ToPose(const ::Eigen::Isometry3d& iso)
{
    com::robotraconteur::geometry::Pose o{};
    ::Eigen::Quaterniond q = (::Eigen::Quaterniond)iso.linear();
    o.s.orientation = ToQuaternion(q);
    ::Eigen::Vector3d p = (::Eigen::Vector3d)iso.translation();
    o.s.position = ToPoint(p);
    return o;
}

com::robotraconteur::geometry::SpatialVelocity ToSpatialVelocity(const ::Eigen::Ref<const ::Eigen::Matrix<double,6,1> >& vs)
{
    com::robotraconteur::geometry::SpatialVelocity o{};
    o.s.angular.s.x = vs[0];
    o.s.angular.s.y = vs[1];
    o.s.angular.s.z = vs[2];
    o.s.linear.s.x = vs[3];
    o.s.linear.s.y = vs[4];
    o.s.linear.s.z = vs[5];
    return o;
}

::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::SpatialVelocity& vs)
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

com::robotraconteur::geometry::SpatialAcceleration ToSpatialAcceleration(const ::Eigen::Ref<const ::Eigen::Matrix<double,6,1> >& vs)
{
    com::robotraconteur::geometry::SpatialAcceleration o{};
    o.s.angular.s.x = vs[0];
    o.s.angular.s.y = vs[1];
    o.s.angular.s.z = vs[2];
    o.s.linear.s.x = vs[3];
    o.s.linear.s.y = vs[4];
    o.s.linear.s.z = vs[5];
    return o;
}

::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::SpatialAcceleration& vs)
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

com::robotraconteur::geometry::Wrench ToWrench(const ::Eigen::Ref<const ::Eigen::Matrix<double,6,1> >& vs)
{
    com::robotraconteur::geometry::Wrench o{};
    o.s.torque.s.x = vs[0];
    o.s.torque.s.y = vs[1];
    o.s.torque.s.z = vs[2];
    o.s.force.s.x = vs[3];
    o.s.force.s.y = vs[4];
    o.s.force.s.z = vs[5];
    return o;
}

::Eigen::Matrix<double,6,1> ToVector(const com::robotraconteur::geometry::Wrench& vs)
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