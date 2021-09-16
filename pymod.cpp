#include <pybind11/pybind11.h>
#include "mat_container.h"

namespace py = pybind11;

PYBIND11_MODULE(pymod, m) {
  py::class_<DynamicMatrixContainer>(m, "DynamicMC").def(py::init<size_t, bool>())
      .def_readwrite("A", &DynamicMatrixContainer::A)
      .def("swapA", &DynamicMatrixContainer::swapA);

  m.def("test", [](size_t d2) {
    DynamicMatrixContainer dmc1(100, false);
    DynamicMatrixContainer dmc2(d2, false);
    dmc1.A = dmc2.A;
  });
  py::class_<StaticMatrixContainer>(m, "StaticMC").def(py::init<size_t>());
}