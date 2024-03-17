#include <RobotRaconteur.h>
#include "RobotRaconteurCompanion/Converters/EigenConverters.h"
#include "RobotRaconteurCompanion/Util/IdentifierUtil.h"

namespace RR = RobotRaconteur;
namespace RREigen = RobotRaconteur::Companion::Converters::Eigen;

template<typename T,int N>
void eigen_ca(Eigen::Matrix<T,N,1> eig, RR::RRArrayPtr<T> a)
{
    if (eig.rows() != a->size())
    {
        throw std::runtime_error("");
    }
    for (size_t i=0; i<a->size(); i++)
    {
        if (a->at(i) != eig[i])
        {
            throw std::runtime_error("");
        }
    }
}

void test_vectors()
{
    const double a1_1[] {1, 2, 3}; // NOLINT
    RR::RRArrayPtr<double> a1 = RR::AttachRRArrayCopy(a1_1,3);
    Eigen::VectorXd a1_e = RREigen::RRArrayToEigen<Eigen::VectorXd>(a1);
    eigen_ca(a1_e,a1);
    Eigen::Vector3d a1_e2 = RREigen::RRArrayToEigen<Eigen::Vector3d>(a1);
    eigen_ca(a1_e2,a1);

    Eigen::Vector3d b1;
    // cppcheck-suppress constStatement
    b1 << 3,4,6;
    RR::RRArrayPtr<double> b1_a = RREigen::EigenToRRArray(b1);
    eigen_ca(b1,b1_a);

    Eigen::VectorXd b2(4);
    // cppcheck-suppress constStatement
    b2 << 7,8,9,10;
    RR::RRArrayPtr<double> b2_a = RREigen::EigenToRRArray(b2);
    eigen_ca(b2,b2_a);
}

void test_matrices()
{
    const double a1_1[] {1,2,3,4,5,6}; // NOLINT
    const uint32_t a1_dims[] = {3,2}; // NOLINT
    RR::RRMultiDimArrayPtr<double> a1 = RR::AllocateRRMultiDimArray<double>(RR::AttachRRArrayCopy(a1_dims,2),RR::AttachRRArrayCopy(a1_1,6));
    ::Eigen::MatrixXd a1_e = RREigen::RRMultiDimArrayToEigen(a1);

    std::cout << a1_e << std::endl;

    ::Eigen::MatrixXd b1(3,3);
    // cppcheck-suppress constStatement
    b1 << 7,8,9,10,11,12,13,14,15;
    RR::RRMultiDimArrayPtr<double> b1_a = RREigen::EigenToRRMultiDimArray(b1);

    for (size_t i=0; i<9; i++)
    {
        std::cout << b1_a->Array->at(i) << std::endl;
    }
}

int main(int ac, char** av) // NOLINT
{
	test_vectors();

    test_matrices();

    std::cout << "Done" << std::endl;
    return 0;
}