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

      if (data->vertexes[data->vertexes.size()-3] > data->max_x)
          data->max_x = data->vertexes[data->vertexes.size()-3];
      if (data->vertexes[data->vertexes.size()-2] > data->max_y)
          data->max_y = data->vertexes[data->vertexes.size()-2];
      if (data->vertexes[data->vertexes.size()-1] > data->max_z)
          data->max_z = data->vertexes[data->vertexes.size()-1];
      if (data->vertexes[data->vertexes.size()-3] < data->min_x)
          data->min_x = data->vertexes[data->vertexes.size()-3];
      if (data->vertexes[data->vertexes.size()-2] < data->min_y)
          data->min_y = data->vertexes[data->vertexes.size()-2];
      if (data->vertexes[data->vertexes.size()-1] < data->min_z)
          data->min_z = data->vertexes[data->vertexes.size()-1];
    }
  }
  file.close();
}
