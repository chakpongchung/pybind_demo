#!/usr/bin/env python3
from pybind_demo import IntVector, split_mut as cpp_split_mut

content = ""
with open('test_split.txt', 'r') as file:
    content = file.read().replace('\n', '')

chunks = IntVector()
cpp_split_mut(content, ',', chunks)
print("Got {} chunks".format(len(chunks)))