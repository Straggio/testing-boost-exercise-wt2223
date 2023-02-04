#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    filename       = "../data/m3.csv";
    dimension      = 3;
    expectedMatrix = MatrixXd(dimension, dimension);
    expectedMatrix << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
  }
  std::string filename;
  int         dimension;
  MatrixXd    expectedMatrix;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture)

BOOST_AUTO_TEST_CASE(openData)
{
  MatrixXd actualMatrix = matrixIO::openData(filename, dimension);
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      BOOST_TEST(expectedMatrix(i, j) == actualMatrix(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()
