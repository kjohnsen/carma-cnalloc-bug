#include "mat_container.h"

CompiledMatrixContainer::CompiledMatrixContainer(std::size_t d) {
    A = arma::Mat<double>(d, d, arma::fill::ones);
    std::cerr << "filled arma matrix\n";
}