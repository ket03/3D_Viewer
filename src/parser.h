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
  double min_x = std::numeric_limits<double>::max();
  double min_y = std::numeric_limits<double>::max();
  double min_z = std::numeric_limits<double>::max();
  double max_x = std::numeric_limits<double>::min();
  double max_y = std::numeric_limits<double>::min();
  double max_z = std::numeric_limits<double>::min();
};

void Parser(std::string filename, Data *data);

#endif // PARSER_H
