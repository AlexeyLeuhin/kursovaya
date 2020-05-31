#include "functions.h"

void openFile(std::vector<Information>& data, std::string& filepath, bool& file_was_opened) {
  char r = ' ';
  data.clear();
  std::fstream fin(filepath, std::ios_base::in| std::ios_base::out| std::ios_base::app);
  std::string str;
  while (fin.good()) {
    file_was_opened = true;
    getline(fin, str);
    if (str.empty()) {
      break;
    }
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

    data.push_back(inf);
    
  }
  fin.close();
}



std::string toString(const Information& inf) {
  std::string result = "cargo: ";
  result += std::to_string(inf.cargo.weight);
  result += " " + inf.cargo.type + " ";
  result += std::to_string( inf.cargo.price);
  result += " " + inf.cargo.comment + "Gruz: ";
  result += std::to_string(inf.distance) + " " + inf.type_of_delivering + "\n";
  return result;
}


void printTabled(const Information& inf) {
  std::cout << std::setw(10) << std::left << inf.cargo.weight
             <<"| "<< std::setw(12) <<inf.cargo.type<<"| "
              << std::setw(8) <<inf.cargo.price<<"| "
              << std::setw(15) <<inf.cargo.comment<< "| "<< std::setw(11) <<inf.distance<<"| "<< inf.type_of_delivering<<"\n";
}


void appendObject(std::vector<Information>& data, bool& file_was_opened, std::string filepath) {
  if (!file_was_opened) {
    std::cout << "Чтобы добавить запись файл, сначла откройте файл\n";
    system("pause");
  }
  else {
    Information tmp;
    std::cout << "Введите вес груза: ";
    std::cin >> tmp.cargo.weight;
    std::cout << "Введите тип груза: ";
    std::cin >> tmp.cargo.type;
    std::cout << "Введите цену груза: ";
    std::cin >> tmp.cargo.price;
    std::cin.ignore();
    std::cout << "Введите комментарий к грузу: ";
    getline(std::cin, tmp.cargo.comment);
    std::cout << "Введите тип доставки груза: ";
    std::cin >> tmp.type_of_delivering;
    std::cout << "Введите расстояние доставки: ";
    std::cin >> tmp.distance;
    tmp.CountPrice();
    data.push_back(tmp);
    std::ofstream fout(filepath, std::ios_base::app);
    fout <<toString(tmp)<<"\n";
    std::cout << "Запись груза успешно создана.\n";
    system("pause");
    fout.close();
  }
}

void createManager() {
  char r = ' ';
  std::string log, pass;  
  std::vector<std::string> logs;
  std::string str;
  std::ifstream fin;
  fin.open("managers.txt");
  while (fin.good()) {
    getline(fin, str);
    std::size_t pos = str.find(r);
    log = str.substr(0, pos);
    logs.push_back(log);
  }
  fin.close();

  std::cout << "Введите логин: ";
  std::cin >> log;
  std::cout << "Введите пароль: ";
  std::cin >> pass;

  if (std::find(logs.begin(),logs.end(),log)!=logs.end()) {
    std::cout << "Менеджер с таким логином уже существует, придумайте другое имя.\n";
    system("pause");
    
  }
  else {
    std::ofstream fout("managers.txt", std::ios_base::app);
    fout << "\n" << log << " " << pass;
    std::cout << "Запись менеджера успешно создана.\n";
    system("pause");
    fout.close();
  }
  
}


void sortDataByPrice(std::vector<Information>& a) {
    std::sort(a.begin(), a.end(), [](Information a, Information b) {return a.full_price > b.full_price; });
}

void sortDataByDistance(std::vector<Information>& a) {
    std::sort(a.begin(), a.end(), [](Information a, Information b) {return a.distance > b.distance; });
}

void changeInformation(std::vector<Information>& a, int x, const std::string& filepath) {
    printTabled(a[x]);
    std::cout << "\n---------------------------------------\n";
    std::cout << "Введите новые данные:\n";
    a.erase(a.begin() + x);
    Information tmp;
    std::cout << "Введите вес груза: ";
    std::cin >> tmp.cargo.weight;
    std::cout << "Введите тип груза: ";
    std::cin >> tmp.cargo.type;
    std::cout << "Введите цену груза: ";
    std::cin >> tmp.cargo.price;
    std::cin.ignore();
    std::cout << "Введите комментарий к грузу: ";
    getline(std::cin, tmp.cargo.comment);
    std::cout << "Введите тип доставки груза: ";
    std::cin >> tmp.type_of_delivering;
    std::cout << "Введите расстояние доставки: ";
    std::cin >> tmp.distance;
    tmp.CountPrice();
    a.push_back(tmp);
    std::ofstream fout(filepath);
    for (auto& x : a) {
        fout << toString(x) << "\n";
    }
    std::cout << "Запись груза успешно создана.\n";
    system("pause");
    fout.close();    
}


void deleteInformation(std::vector<Information>& a, int x, const std::string& filepath) {

    // TODO: проверка на введенный индекс

    a.erase(a.begin() + x);
    std::ofstream fout(filepath);
    for (auto& x : a) {
        fout << toString(x) << "\n";
    }
    std::cout << "\nУдаление записи номер " << x << " завершено!\n";
    system("pause");
    fout.close();
}

void findInformationByName(const std::vector<Information>& a) {
    std::string name;
    std::cout << "\n Введите название товара: ";
    std::cin >> name;
    std::for_each(a.begin(), a.end(), [name](Information s) {
        if (s.cargo.type == name) {
            printTabled(s);
        }

        });
    system("pause");
  
}

void findInformationByTypeOfDelivering(const std::vector<Information>& a) {
    std::string type;
    std::cout << "\n Введите название товара: ";
    std::cin >> type;
    std::for_each(a.begin(), a.end(), [type](Information s) {
        if (s.type_of_delivering == type) {
            printTabled(s);
        }

        });
    system("pause");

}


void filtrationInformation(const std::vector<Information>& a) {
    int lower_bound;
    int upper_bound;
    std::cout << "\nВведите нижнюю границу цены: ";
    std::cin >> lower_bound;
    std::cout << "Введите верхнюю границу цены: ";
    std::cin >> upper_bound;
    std::for_each(a.begin(), a.end(), [lower_bound, upper_bound](Information s) {
        if (s.cargo.price <= upper_bound && s.cargo.price >= lower_bound) {
            printTabled(s);
        }

        });
    system("pause");
}