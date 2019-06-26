#!/usr/bin/env python3
from pybind_demo import split as cpp_split

content = ""
with open('test_split.txt', 'r') as file:
    content = file.read().replace('\n', '')

chunks = cpp_split(content, ',')
print("Got {} chunks".format(len(chunks)))