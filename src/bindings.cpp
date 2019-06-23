#include <pybind11/pybind11.h>
#include <pybind_demo/pybind_demo.hpp>

PYBIND11_MODULE(pybind_demo, m) {
    m.doc() = "pybind11 tutorial: ackermann";
    m.def("ackermann", &ackermann, "A function which calculates ackermann number");
}
