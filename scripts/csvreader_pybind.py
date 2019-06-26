#!/usr/bin/env python3

from pybind_demo import CSVReader

csv = CSVReader("test.csv", ',')
csv.processFile()
print("Data at row 5: {}".format(csv.dataAt(5)))
