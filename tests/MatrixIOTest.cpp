#define BOOST_TEST_DYN_LINK
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
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      BOOST_TEST(mat(i, j) == output(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()
