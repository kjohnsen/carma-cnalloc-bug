#include <carma>
#include <pybind11/pybind11.h>
#include "mat_container.h"

namespace py = pybind11;

class LocalMatrixContainer {
 public:
  LocalMatrixContainer(size_t d) {
    A = arma::Mat<double>(d, d, arma::fill::ones);
  }
  arma::Mat<double> A;
};

PYBIND11_MODULE(pymod, m) {
  py::class_<LocalMatrixContainer>(m, "LocalMC").def(py::init<size_t>());
  py::class_<CompiledMatrixContainer>(m, "CompiledMC").def(py::init<size_t>());
  py::class_<HeaderMatrixContainer>(m, "HeaderMC").def(py::init<size_t>());
}