#include <pybind11/pybind11.h>
#include "mat_container.h"

using namespace std;
namespace py = pybind11;

class StaticMatrixContainer {
 public:
  StaticMatrixContainer(size_t d) {
      A = arma::Mat<double>(d, d, arma::fill::ones);
  }
  arma::Mat<double> A;
};

PYBIND11_MODULE(example, m) {
  py::class_<DynamicMatrixContainer>(m, "DynamicMC").def(py::init<size_t, bool>());
  py::class_<StaticMatrixContainer>(m, "StaticMC").def(py::init<size_t>());
}