#include <pybind_demo/pybind_demo.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

unsigned int ackermann(unsigned int m, unsigned int n) {
  if (m == 0) {
    return n + 1;
  }

  if (n == 0) {
    return ackermann(m - 1, 1);
  }

  return ackermann(m - 1, ackermann(m, n - 1));
}

std::vector<int> split(const std::string &content, char delimiter) {
    static std::vector<int> chunks(content.size()*2);
    chunks.clear();
    static std::string token;

    std::istringstream stream(content);
    while (std::getline(stream, token, delimiter))
    {
        chunks.push_back(std::stoi(token));
    }

    chunks.shrink_to_fit();
    return chunks;
}

std::vector<int> split_naive(std::string &content, char delimiter) {
    static std::vector<int> splits(content.size()*2);
    splits.clear();
    static std::string token;
    size_t pos = 0;

    while ((pos = content.find(delimiter)) != std::string::npos) {
        token = content.substr(0, pos);
        splits.push_back(std::stoi(token));
        content.erase(0, pos + 1);
    }

    return splits;
}

void split_mut(const std::string &content, char delimiter, std::vector<int> &chunks) {
    chunks.reserve(content.size()*2);
    static std::string token;

    std::istringstream stream(content);
    while (std::getline(stream, token, delimiter))
    {
        chunks.push_back(std::stoi(token));
    }

    chunks.shrink_to_fit();
}

CSVReader::CSVReader(const std::string &filename, char delimiter)
    : filename(filename), delimiter(delimiter) {

    data.reserve(2'000'000);
}

void CSVReader::processFile() {
	std::ifstream file(filename);
    if (!file)
		return;

	std::string line;

	while (std::getline(file, line)) {
	    // strangely/interestingly, naive implementation is the fastest here, wtf
	    // naive implementation is blown out of the water for large strings by split and split_mut
	    data.emplace_back(std::move(split_naive(line, delimiter)));
	}

	data.shrink_to_fit();
}

void CSVReader::showData() {
    for (auto it = std::begin(data); it != std::end(data); it++) {
        std::cout << std::distance(std::begin(data), it) + 1 << ": ";
        std::copy(std::begin(*it), std::end(*it), std::ostream_iterator<int>(std::cout, ","));
        std::cout << "\n";
    }
}

std::vector<int> CSVReader::dataAt(size_t index) {
    return data.at(index);
}

const std::string &CSVReader::getFilename() const {
    return filename;
}

void CSVReader::setFilename(const std::string &name) {
    filename = name;
}
