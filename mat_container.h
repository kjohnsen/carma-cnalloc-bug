// #include <iostream>  // <-- only needed to use std::?
#include <armadillo>

class CompiledMatrixContainer {
 public:
  CompiledMatrixContainer(size_t d);
  arma::Mat<double> A;
};

class HeaderMatrixContainer {
 public:
  HeaderMatrixContainer(size_t d) {
    A = arma::Mat<double>(d, d, arma::fill::ones);
  }
  arma::Mat<double> A;
};