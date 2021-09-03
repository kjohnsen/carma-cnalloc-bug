#include <armadillo>

using namespace std;

class DynamicMatrixContainer {
 public:
  DynamicMatrixContainer(size_t d, bool vec_not_mat = false);
  arma::Mat<double> A;
  std::vector<double> stdvec;
};
