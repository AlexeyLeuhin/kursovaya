#include "functions.h"

void openFile(std::vector<Information>& data, std::string& filepath, bool& file_was_opened) {
  file_was_opened = false;
  char r = ' ';
  data.clear();     //clears buffer before reading
  std::fstream fin(filepath, std::ios_base::in| std::ios_base::out| std::ios_base::app);  //opens or creates file
  std::string str;
  while (fin.good()) {    
    file_was_opened = true;
    getline(fin, str);    //reads line to str
    if (str.empty()) {
      break;
    }
    Information inf;

    //parcing of information
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



std::string toString(const Information& inf) {    //help function, converts fields of object to string
  std::string result = "cargo: ";
  result += std::to_string(inf.cargo.weight);
  result += " " + inf.cargo.type + " ";
  result += std::to_string( inf.cargo.price);
  result += " " + inf.cargo.comment + " Gruz: ";
  result += std::to_string(inf.distance) + " " + inf.type_of_delivering + " "+ std::to_string(inf.full_price)+ " " + "\n";
  return result;
}


void printTabled(const Information& inf) {    //prints object as a table row
  std::cout << std::setw(10) << std::left << inf.cargo.weight
             <<"| "<< std::setw(12) <<inf.cargo.type<<"| "
              << std::setw(8) <<inf.cargo.price<<"| "
              << std::setw(29) <<inf.cargo.comment<< "| "<< std::setw(11) <<inf.distance<<"| "
              << std::setw(15)<< inf.type_of_delivering <<"| "<< inf.full_price<<"\n";
}


void appendObject(std::vector<Information>& data, bool& file_was_opened, std::string filepath) {
  if (!file_was_opened) {
    std::cout << "Чтобы добавить запись файл, сначла откройте файл\n";
    system("pause");
  }
  else {    //user enters all the parameters
    Information tmp;
    std::cout << "Введите вес груза: ";
    std::cin >> tmp.cargo.weight;
    std::cin.ignore();
    std::cout << "Введите тип груза: ";
    getline(std::cin, tmp.cargo.type);
    std::cout << "Введите цену груза: ";
    std::cin >> tmp.cargo.price;
    std::cin.ignore();
    std::cout << "Введите комментарий к грузу: ";
    std::string y;
    getline(std::cin, y);
    if (y.length() > 30) {
      tmp.cargo.comment = y.substr(0, 29);
    }
    else {
      tmp.cargo.comment = y;
    }
    std::cout << "Введите тип доставки груза: ";
    std::cin >> tmp.type_of_delivering;
    std::cout << "Введите расстояние доставки: ";
    std::cin >> tmp.distance;
    tmp.full_price = tmp.CountPrice();
    data.push_back(tmp);    //objects is pushed to buffer
    std::ofstream fout(filepath, std::ios_base::app);   // object is written to file
    fout <<toString(tmp);
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
  while (fin.good()) {      //all logins are written from file
    getline(fin, str);
    std::size_t pos = str.find(r);
    log = str.substr(0, pos);
    logs.push_back(log);
  }
  fin.close();

  std::cout << "Введите логин: ";   //user enters login and password
  std::cin >> log;
  std::cout << "Введите пароль: ";
  std::cin >> pass;

  if (std::find(logs.begin(),logs.end(),log)!=logs.end()) {   //checks if such login already exists
    std::cout << "Менеджер с таким логином уже существует, придумайте другое имя.\n";
    system("pause");
    
  }
  else {  //writes account to the file
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

void changeInformation(std::vector<Information>& a, int x, const std::string& filepath, bool& file_was_opened) {
  if (!file_was_opened) {
    std::cout << "Чтобы добавить запись файл, сначла откройте файл\n";
    system("pause");
  }
  else {
    printTabled(a[x]);      //prints all the data to console
    std::cout << "\n---------------------------------------\n";
    std::cout << "Введите новые данные:\n";
    a.erase(a.begin() + x);   //erases old object
    Information tmp;
    std::cout << "Введите вес груза: ";   //user enteres new parameters
    std::cin >> tmp.cargo.weight;
    std::cin.ignore();
    std::cout << "Введите тип груза: ";
    getline(std::cin, tmp.cargo.type);
    std::cout << "Введите цену груза: ";
    std::cin >> tmp.cargo.price;
    std::cin.ignore();
    std::cout << "Введите комментарий к грузу: ";
    std::string y;
    getline(std::cin, y);
    if (y.length() > 30) {
      tmp.cargo.comment = y.substr(0, 29);
    }
    else {
      tmp.cargo.comment = y;
    }
    std::cout << "Введите тип доставки груза: ";
    std::cin >> tmp.type_of_delivering;
    std::cout << "Введите расстояние доставки: ";
    std::cin >> tmp.distance;
    tmp.full_price = tmp.CountPrice();
    a.push_back(tmp);         //new object pushed to buffer
    std::ofstream fout(filepath);     //file is overwritten
    for (auto& x : a) {
      fout << toString(x);
    }
    std::cout << "Запись груза успешно создана.\n";
    system("pause");
    fout.close();
  }
    
}


void deleteInformation(std::vector<Information>& a, int x, const std::string& filepath, bool& file_was_opened) {

  if (!file_was_opened) {
    std::cout << "Чтобы добавить запись файл, сначла откройте файл\n";
    system("pause");
  }
  else {
    a.erase(a.begin() + x);     //object is deleted from buffer by index
    std::ofstream fout(filepath);   //file is overwritten
    for (auto& x : a) {
      fout << toString(x);
    }
    std::cout << "\nУдаление записи номер " << x << " завершено!\n";
    system("pause");
    fout.close();
  }
 
}

void findInformationByName(const std::vector<Information>& a, bool& file_was_opened) {
  if (!file_was_opened) {
    std::cout << "Чтобы добавить запись файл, сначла откройте файл\n";
    system("pause");
  }
  else {
    std::string name;
    std::cout << "\nВведите название товара: ";   //user enters parameter
    std::cin >> name;
    std::cout << std::setw(11) << std::left << "Вес"
      << " " << std::setw(13) << "Тип" << " "
      << std::setw(9) << "Цена" << " "
      << std::setw(30) << "Комментарий" << " " << std::setw(12) << "Расстояние" << " " << std::setw(16)
      << "Тип доставки" << " " << "Полная цена груза" << "\n";
    std::for_each(a.begin(), a.end(), [name](Information s) {     //looks for object with such parameter
      if (s.cargo.type == name) {
        printTabled(s);
      }

      });
    system("pause");
  }
  
  
}

void findInformationByTypeOfDelivering(const std::vector<Information>& a, bool& file_was_opened) {
  if (!file_was_opened) {
    std::cout << "Чтобы добавить запись файл, сначла откройте файл\n";
    system("pause");
  }
  else {
    std::string type;
    std::cout << "\nВведите тип доставки: ";    //user enters parameter
    std::cin >> type;
    std::cout << std::setw(11) << std::left << "Вес"
      << " " << std::setw(13) << "Тип" << " "
      << std::setw(9) << "Цена" << " "
      << std::setw(30) << "Комментарий" << " " << std::setw(12) << "Расстояние" << " " << std::setw(16)
      << "Тип доставки" << " " << "Полная цена груза" << "\n";
    std::for_each(a.begin(), a.end(), [type](Information s) {     //looks for object with such parameter
      if (s.type_of_delivering == type) {
        printTabled(s);
      }

      });
    system("pause");
  }
  

}


void filtrationInformation(const std::vector<Information>& a, bool& file_was_opened) {

  if (!file_was_opened) {
    std::cout << "Чтобы добавить запись файл, сначла откройте файл\n";
    system("pause");
  }
  else {
    int lower_bound;
    int upper_bound;
    std::cout << "\nВведите нижнюю границу цены: ";     //user enters bounds of filtration
    std::cin >> lower_bound;
    std::cout << "Введите верхнюю границу цены: ";
    std::cin >> upper_bound;
    std::cout << std::setw(11) << std::left << "Вес"
      << " " << std::setw(13) << "Тип" << " "
      << std::setw(9) << "Цена" << " "
      << std::setw(30) << "Комментарий" << " " << std::setw(12) << "Расстояние" << " " << std::setw(16)
      << "Тип доставки" << " " << "Полная цена груза" << "\n";
    std::for_each(a.begin(), a.end(), [lower_bound, upper_bound](Information s) {   //goes throw all the buffer
      if (s.cargo.price <= upper_bound && s.cargo.price >= lower_bound) {   //and looks for appropriate objects
        printTabled(s);
      }

      });
    system("pause");
  }
 
}

void changeManager() {
  char r = ' ';
  std::ifstream fin;
  std::map<std::string, std::string> log_pass;      //stores managers accounts
  std::string log, str, pass;
  fin.open("managers.txt");
  while (fin.good()) {    //reades and parces accounts from file
    getline(fin, str);
    std::size_t pos = str.find(r);
    log = str.substr(0, pos);
    pass = str.substr(pos + 1, str.length() - log.length());
    log_pass[log] = pass;
  }
  fin.close();

  std::cout << "Список менеджеров и их паролей:\n";
  for (auto x : log_pass) {             //prints accounts to console
    std::cout << x.first << " " << x.second << "\n";
  }
  std::cout << "Введите логин менеджера, учетную запись которого хотите изменить: ";
  std::cin >> log;
  auto it = log_pass.find(log);
  if (it != log_pass.end()) {     //deletes old account and creates a new one if login is correct
    log_pass.erase(it);
    std::cout << "Введите новый логин для менеджера: ";
    std::cin >> log;
    std::cout << "Введите новый пароль для менеджера: ";
    std::cin >> pass;
    log_pass[log] = pass;
    std::cout << "Данные учетной записи изменены.\n";
    system("pause");
  }
  else {
    std::cout << "Менеджера с таким логином не существует.\n";
    system("pause");
  }
  std::ofstream fout("managers.txt");
  for (auto x : log_pass) {         //file of accounts is overwritten
      fout << "\n" << x.first << " " << x.second;
  }
  system("pause");
  fout.close();
  
}

