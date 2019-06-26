#ifndef PYBIND_DEMO_HPP
#define PYBIND_DEMO_HPP

#include <vector>
#include <string>

using Data = std::vector<std::vector<int>>;

unsigned int ackermann(unsigned int m, unsigned int n);

std::vector<int> split(const std::string &content, char delimiter);

std::vector<int> split_naive(std::string &content, char delimiter);

void split_mut(const std::string &content, char delimiter, std::vector<int> &chunks);

struct CSVReader {
    CSVReader() = delete;

    CSVReader(const std::string &filename, char delimiter);

    void processFile();

    void showData();

    std::vector<int> dataAt(size_t index);

    const std::string &getFilename() const;

    void setFilename(const std::string &filename);

private:
    Data data;
    std::string filename;
    char delimiter;
};

#endif // PYBIND_DEMO_HPP
