// Grey Espinoza
// CPSC 120-12
// 2022-11-03
// gray@csu.fullerton.edu
// @CSUFgrey
//
// Lab 09-01
// Partners: @brian-250
//
// returns score using Olympic rules
//

#include <iostream>
#include <string>
#include <vector>

double JudgeAverage(const std::vector<double>& scores) {
  double min{scores.front()};
  double max{scores.front()};
  double total{};
  for (const double& score : scores) {
    if (score < min) {
      min = score;
    } else if (score > max) {
      max = score;
    }
    total += score;
  }
  return (((total - min) - max) / (static_cast<double>(scores.size()) - 2.0));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);

  if (arguments.size() < 4) {
    std::cout << "error: you must give at least three scores";
    return 1;
  }

  std::vector<double> scores{};
  bool is_first{true};
  for (const std::string& argument : arguments) {
    if (is_first) {
      is_first = false;
      continue;
    }
    scores.push_back(std::stod(argument));
  }

  double calculated_score{JudgeAverage(scores)};
  std::cout << "average is " << calculated_score << "\n";

  return 0;
}
