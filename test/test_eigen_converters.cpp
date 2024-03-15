
#include <RobotRaconteur.h>
#include "RobotRaconteurCompanion/Converters/EigenConverters.h"
#include "RobotRaconteurCompanion/Util/IdentifierUtil.h"

#include <gtest/gtest.h>

namespace RR = RobotRaconteur;
namespace RREigen = RobotRaconteur::Companion::Converters::Eigen;

template<typename T,int N>
void eigen_ca(Eigen::Matrix<T,N,1> eig, RR::RRArrayPtr<T> a)
{
    ASSERT_EQ(eig.rows(), a->size());

    for (size_t i=0; i<a->size(); i++)
    {
        EXPECT_EQ(a->at(i), eig[i]);
    }
}

// eigen_ca for Eigen::Matrix
template<typename T,int R,int C>
void eigen_ca(Eigen::Matrix<T,R,C> eig, RR::RRMultiDimArrayPtr<T> a)
{
    ASSERT_EQ(eig.rows(), a->Dims->at(0));
    ASSERT_EQ(eig.cols(),  a->Dims->at(1));

    for (size_t i=0; i<a->Array->size(); i++)
    {
        EXPECT_EQ(a->Array->at(i), eig(i%eig.rows(),i/eig.rows()));
    }
}

TEST(EigenConverters,Vectors)
{
    const double a1_1[] {1, 2, 3};
    RR::RRArrayPtr<double> a1 = RR::AttachRRArrayCopy(a1_1,3);
    Eigen::VectorXd a1_e = RREigen::RRArrayToEigen<Eigen::VectorXd>(a1);
    eigen_ca(a1_e,a1);
    Eigen::Vector3d a1_e2 = RREigen::RRArrayToEigen<Eigen::Vector3d>(a1);
    eigen_ca(a1_e2,a1);

    Eigen::Vector3d b1;
    b1 << 3,4,6;
    RR::RRArrayPtr<double> b1_a = RREigen::EigenToRRArray(b1);
    eigen_ca(b1,b1_a);

    Eigen::VectorXd b2(4);
    b2 << 7,8,9,10;
    RR::RRArrayPtr<double> b2_a = RREigen::EigenToRRArray(b2);
    eigen_ca(b2,b2_a);
}

TEST(EigenConverters,Matrices)
{
    const double a1_1[] {1,2,3,4,5,6};
    const uint32_t a1_dims[] = {3,2};
    RR::RRMultiDimArrayPtr<double> a1 = RR::AllocateRRMultiDimArray<double>(RR::AttachRRArrayCopy(a1_dims,2),RR::AttachRRArrayCopy(a1_1,6));
    ::Eigen::MatrixXd a1_e = RREigen::RRMultiDimArrayToEigen(a1);

    eigen_ca(a1_e,a1);

    ::Eigen::MatrixXd b1(3,3);
    b1 << 7,8,9,10,11,12,13,14,15;
    RR::RRMultiDimArrayPtr<double> b1_a = RREigen::EigenToRRMultiDimArray(b1);

    eigen_ca(b1,b1_a);

    ::Eigen::Matrix3d c1(3,3);
    c1 << 7,8,9,10,11,12,13,14,15;
    RR::RRMultiDimArrayPtr<double> c1_a = RREigen::EigenToRRMultiDimArray(c1);

    eigen_ca(c1,c1_a);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}