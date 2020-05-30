#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iomanip>


struct Cargo {
  double weight;
  std::string type;
  std::string comment = "No comments to this cargo";
  double price;
};

struct Information {
  Cargo cargo;
  int distance;
  std::string type_of_delivering;
  int full_price;
  int CountPrice() {
    if (type_of_delivering == "ship" || type_of_delivering == "Ship") {
      return distance * cargo.price * cargo.weight * 3;
    }
    else {
      return distance * cargo.price * cargo.weight * 2;
    }
  }
};
