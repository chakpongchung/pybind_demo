#!/usr/bin/env python3

from pybind_demo import CSVReader

csv = CSVReader("test.csv", ',')
csv.processFile()
print("Data from file {} at row {}: {}".format(csv.filename, 5, csv.dataAt(5)))
