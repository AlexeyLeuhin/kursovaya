#include "functions.h"

std::vector<Information> openFile(const std::string& filepath, bool& file_was_opened) {
  char r = ' ';
  std::vector<Information> res;
  std::ifstream fin;
  fin.open(filepath);
  std::string str;
  while (fin.good()) {
    file_was_opened = true;
    getline(fin, str);
    Information inf;

    std::size_t pos = str.find(r);
    str.erase(0, pos + 1);

    // cargo -> weight
    pos = str.find(r);
    inf.cargo.weight = stoi(str.substr(0, pos));
    str.erase(0, pos + 1);

    // cargo -> type
    pos = str.find(r);
    inf.cargo.type = str.substr(0, pos);
    str.erase(0, pos + 1);

    // cargo -> price
    pos = str.find(r);
    inf.cargo.price = stoi(str.substr(0, pos));
    str.erase(0, pos + 1);

    // cargo -> comment
    pos = str.find("Gruz:");
    inf.cargo.comment = str.substr(0, pos);
    str.erase(0, pos + 6);

    // inf -> distance
    pos = str.find(r);
    inf.distance = stoi(str.substr(0, pos));
    str.erase(0, pos + 1);

    // inf -> type of delivering
    pos = str.find(r);
    inf.type_of_delivering = str.substr(0, pos);
    str.erase(0, pos + 1);

    inf.full_price = inf.CountPrice();

    res.push_back(inf);
    
  }
  fin.close();
  return res;
}

std::string toString(const Information& inf) {
  std::string result = "cargo: ";
  result += std::to_string(inf.cargo.weight);
  result += " " + inf.cargo.type + " ";
  result += std::to_string( inf.cargo.price);
  result += " " + inf.cargo.comment + "Gruz: ";
  result += std::to_string(inf.distance) + inf.type_of_delivering;
  return result;
}


void printTabled(const Information& inf) {
  std::cout << std::setw(10) << std::left << inf.cargo.weight
             <<"| "<< std::setw(12) <<inf.cargo.type<<"| "
              << std::setw(8) <<inf.cargo.price<<"| "
              << std::setw(15) <<inf.cargo.comment<< "| "<< std::setw(11) <<inf.distance<<"| "<< inf.type_of_delivering<<"\n";
}


std::vector<Information> appendObject(const std::vector<Information>& data, bool& file_was_opened) {
  std::vector<Information> answ = data;
  if (!file_was_opened) {
    std::cout << "„тобы добавить запись файл, сначла откройте файл\n";
    system("pause");
    return data;
  }
  else {
    Information tmp;
    std::cout << "¬ведите вес груза: ";
    std::cin >> tmp.cargo.weight;
    std::cout << "¬ведите тип груза: ";
    std::cin >> tmp.cargo.type;
    std::cout << "¬ведите цену груза: ";
    std::cin >> tmp.cargo.price;
    std::cout << "¬ведите комментарий к грузу: ";
    std::cin >> tmp.cargo.comment;
    std::cout << "¬ведите тип доставки груза: ";
    std::cin >> tmp.type_of_delivering;

    tmp.CountPrice();
    answ.push_back(tmp);
    return answ;
  }
}