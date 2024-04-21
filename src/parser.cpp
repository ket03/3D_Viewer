#include "parser.h"

void Parser(std::string filename, Data *data) {
  std::ifstream file;
  std::string line;
  file.open(filename);
  while (std::getline(file, line)) {
    if (line.find("f ") != std::string::npos) {
      std::istringstream iss(line);
      std::string token;
      iss >> token;

      while (iss >> token) {
        std::size_t pos = token.find('/');
        std::string number =
            (pos != std::string::npos) ? token.substr(0, pos) : token;
        data->facets.push_back(std::stoi(number));
      }

    } else if (line.find("v ") != std::string::npos) {
      std::istringstream iss(line);
      std::string token;
      iss >> token;

      while (iss >> token) {
        std::size_t pos = token.find('/');
        std::string number =
            (pos != std::string::npos) ? token.substr(0, pos) : token;
        data->vertexes.push_back(std::stod(number));
      }
    }
  }
  data->max = *std::max_element(data->vertexes.begin(), data->vertexes.end()) * 2.5;
  file.close();
}
