#!/usr/bin/env python3

content = ""
with open('test_split.txt', 'r') as file:
    content = file.read().replace('\n', '')

chunks = content.split(',')
print("Got {} chunks".format(len(chunks)))