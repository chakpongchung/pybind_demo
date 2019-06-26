#!/usr/bin/env python3
from pybind_demo import split_naive as cpp_split_naive

content = ""
with open('test_split.txt', 'r') as file:
    content = file.read().replace('\n', '')

chunks = cpp_split_naive(content, ',')
print("Got {} chunks".format(len(chunks)))