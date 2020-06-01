#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iomanip>


struct Cargo {
  int weight;
  std::string type;
  std::string comment = "No comments to this cargo";
  int price;
};

struct Information {
  Cargo cargo;
  int distance;
  std::string type_of_delivering;
  int full_price;
  int CountPrice() {
      return distance * cargo.price * cargo.weight * 3;
  }
};
