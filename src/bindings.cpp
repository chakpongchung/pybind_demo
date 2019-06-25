#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind_demo/pybind_demo.hpp>

namespace py = pybind11;

PYBIND11_MODULE(pybind_demo, m) {
    m.doc() = "pybind11 tutorial: ackermann";
    m.def("ackermann", &ackermann, "A function which calculates ackermann number");
    m.def("split", &split, "Splits a string according to delimiter");

    py::class_<CSVReader>(m, "CSVReader")
            .def(py::init<const std::string &, char>())
            .def("processFile", &CSVReader::processFile)
            .def("dataAt", &CSVReader::dataAt)
            .def("showData", &CSVReader::showData);
}
