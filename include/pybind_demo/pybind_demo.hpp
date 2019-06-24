#ifndef PYBIND_DEMO_HPP
#define PYBIND_DEMO_HPP

#include <vector>
#include <string>

using Data = std::vector<std::vector<int>>;

unsigned int ackermann(unsigned int m, unsigned int n);

struct CSVReader {
    CSVReader() = delete;
    CSVReader(const std::string &filename, char delimiter);
    void processFile();
    void showData();
    std::vector<int> dataAt(size_t index);

private:
    Data data;
    std::string filename;
    char delimiter;
};

#endif // PYBIND_DEMO_HPP
