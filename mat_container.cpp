#include "mat_container.h"

DynamicMatrixContainer::DynamicMatrixContainer(std::size_t d, bool stdvec_instead) {
    if (!stdvec_instead) {
        A = arma::Mat<double>(d, d, arma::fill::ones);
        std::cerr << "filled arma matrix\n";
    } else {
        stdvec = std::vector<double>(d*d, 1);
        std::cerr << "filled std::vector\n";
    }
}