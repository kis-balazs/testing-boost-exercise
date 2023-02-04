#define BOOST_TEST_MODULE SideMadeTests
#define BOOST_TEST_DYN_LINK
#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    mat = MatrixXd(3, 3);
    mat << 1, 0, 0,
        0, 1, 0,
        0, 0, 1;
  }

  MatrixXd mat;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture)

BOOST_AUTO_TEST_CASE(MyOnlyTest)
{
  matrixIO::saveData("../data/text.csv", mat);

  MatrixXd output = matrixIO::openData("../data/text.csv", 3);
  BOOST_TEST(mat == output);
}

BOOST_AUTO_TEST_SUITE_END()
