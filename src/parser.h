#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

class Data {
public:
  Data() = default;
  ~Data() = default;

  std::vector<double> vertexes;
  std::vector<int> facets;
  double max = 0;
};

void Parser(std::string filename, Data *data);

#endif // PARSER_H
