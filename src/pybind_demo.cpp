#include <pybind_demo/pybind_demo.hpp>
#include <fstream>
#include <iostream>
#include <iterator>

unsigned int ackermann(unsigned int m, unsigned int n) {
  if (m == 0) {
    return n + 1;
  }

  if (n == 0) {
    return ackermann(m - 1, 1);
  }

  return ackermann(m - 1, ackermann(m, n - 1));
}

std::vector<int> split(std::string& content, char delimiter) {
    static size_t pos = 0;
    static std::string chunk;
    static std::vector<int> chunks(1'000);
    chunks.clear();

    while ((pos = content.find(delimiter)) != std::string::npos) {
        chunk = content.substr(0, pos);
        chunks.push_back(std::stoi(chunk));
        content.erase(0, pos + 1);
    }

    chunks.shrink_to_fit();
    return chunks;
}

CSVReader::CSVReader(const std::string &filename, char delimiter)
    : filename(filename), delimiter(delimiter) {

    data.reserve(1000);
}

void CSVReader::processFile() {
	std::ifstream file(filename);
    if (!file)
		return;

    size_t pos = 0;
	std::string line, token;

	while (std::getline(file, line)) {
        static std::vector<int> splits;
        splits.reserve(10);

	    while ((pos = line.find(delimiter)) != std::string::npos) {
    		token = line.substr(0, pos);
    		splits.push_back(std::stoi(token));
    		line.erase(0, pos + 1);
		}

	    data.emplace_back(std::move(splits));
	}
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
