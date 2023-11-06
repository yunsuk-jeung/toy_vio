#include <iostream>
#include <tbb/concurrent_unordered_map.h>
#include <Eigen/Dense>

#include <functional>
#include "Slam.h"

using Map = tbb::concurrent_unordered_map<int, int, std::hash<int>>;

int main() {


  auto accCallback = [](uint64_t& ns, float* acc) {
    toy::SLAM::getInstance()->setAcc(ns, acc);
  };

  auto gyrCallback = [](uint64_t& ns, float* gyr) {
    toy::SLAM::getInstance()->setGyr(ns, gyr);
  };


  Map map;

  int i = 0;

  map.emplace(i, i);
  i++;
  map.emplace(i, i);
  i++;
  map.emplace(i, i);
  i++;
  map.emplace(i, i);
  map.emplace(i, i);
  map.emplace(i, i);
  map.emplace(i, i);

  Eigen::Matrix4f I = Eigen::Matrix4f::Identity();
  std::cout << I << std::endl;

  for (auto aa = map.begin(); aa != map.end(); aa++) {
    std::cout << aa->first << " / " << aa->second << std::endl;
  }

  for (auto& [key, val] : map) {
    std::cout << key << " / " << val << std::endl;
  }

  return 0;
}