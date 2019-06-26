#!/usr/bin/env python3

class CSVReader():
    def __init__(self, filename, delimiter):
        self.filename = filename
        self.delimiter = delimiter
        self.data = []

    def processFile(self):
        f = open(self.filename,'r')
        lines = f.read().splitlines()
        for line in lines:
            self.data.append(line.split(self.delimiter))

    def dataAt(self, idx):
        if idx > len(self.data):
            raise IndexError("Index out of bounds")

        return self.data[idx]

    def __str__(self):
        for line in self.data:
            print(line)

csv = CSVReader('test.csv', 'r')
csv.processFile()
print("Data at row {}: {}".format(5, csv.dataAt(5)))