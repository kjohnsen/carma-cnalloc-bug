// #include <iostream>  // <-- only needed to use std::?
#include <armadillo>

class DynamicMatrixContainer {
 public:
  DynamicMatrixContainer(size_t d, bool vec_not_mat = false);
  void swapA(size_t d);
  arma::Mat<double> A;
  std::vector<double> stdvec;
};

class StaticMatrixContainer {
 public:
  StaticMatrixContainer(size_t d) {
    A = arma::Mat<double>(d, d, arma::fill::ones);
  }
  arma::Mat<double> A;
};