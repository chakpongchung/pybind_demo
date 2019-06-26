#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind_demo/pybind_demo.hpp>
#include <iterator>
#include <sstream>

namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<int>);

PYBIND11_MODULE(pybind_demo, m) {
    m.doc() = "pybind11 tutorial: ackermann";
    m.def("ackermann", &ackermann, "A function which calculates ackermann number");
    m.def("split", &split, "Splits string according to delimiter");
    m.def("split_mut", &split_mut, "Splits string according to delimiter with mutable vector as func arguments");
    m.def("split_naive", &split_naive, "Splits string according to delimiter, naive implementation");

    // binds stl type vector<int>
    py::class_<std::vector<int>>(m, "IntVector")
            .def(py::init<>())
            .def("clear", &std::vector<int>::clear)
            .def("reserve", [](std::vector<int>& v, int size) { return v.reserve(size); })
            .def("pop_back", &std::vector<int>::pop_back)
            .def("push_back", [](std::vector<int>&v, int elem) {
                return v.push_back(elem);
            })
            .def("__str__", [](const std::vector<int>& v) {
                std::stringstream ss;
                std::copy(v.begin(), v.end(), std::ostream_iterator<int>(ss, " "));
                return ss.str();
            })
            .def("__len__", [](const std::vector<int> &v) { return v.size(); })
            .def("__iter__", [](std::vector<int> &v) {
                return py::make_iterator(v.begin(), v.end());
            }, py::keep_alive<0, 1>());

    py::class_<CSVReader>(m, "CSVReader")
            .def(py::init<const std::string &, char>())
            .def_property("filename", &CSVReader::getFilename, &CSVReader::setFilename) // directly exposes filename
            .def("processFile", &CSVReader::processFile)
            .def("dataAt", &CSVReader::dataAt)
            .def("showData", &CSVReader::showData);
}
