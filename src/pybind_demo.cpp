#include <pybind11/pybind11.h>

unsigned int ackermann(unsigned int m, unsigned int n) {
  if (m == 0) {
    return n + 1;
  }

  if (n == 0) {
    return ackermann(m - 1, 1);
  }

  return ackermann(m - 1, ackermann(m, n - 1));
}

PYBIND11_MODULE(pybind_demo, m) {
    m.doc() = "pybind11 tutorial: ackermann";
    m.def("ackermann", &ackermann, "A function which calculates ackermann number");
}
