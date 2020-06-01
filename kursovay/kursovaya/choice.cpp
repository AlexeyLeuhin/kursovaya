#include "choice.h"

void admin_choice(std::vector<Information>& data, int x, bool& file_was_opened, std::string& path) {

  switch (x)
  {
  case 1: {
    std::cout << "Введите название файла: ";
    std::cin >> path;
    openFile(data, path, file_was_opened);
    if (file_was_opened) {
      std::cout << "Файл был успешно открыт, а данные считаны.\n";
      system("pause");
    }
    else {
      std::cout << "Не удалось прочитать файл\n";
      system("pause");
    }
  }
   break;

  case 2: { // добавление записи
    appendObject(data, file_was_opened, path);
    break;
  }
   
  case 3: { // редактирование записи
    if (!file_was_opened) {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
      break;
      }
      int x;
      std::cout << "\nВведите номер записи, которую хотите изменить: ";
      std::cin >> x;
      if (x >= data.size()) {
        std::cout << "Запись с таким номер не существует.\n";
        system("pause");
        break;
      }
      changeInformation(data, x, path, file_was_opened);
      break;
  }
  case 4: { // удаление записи
    if (!file_was_opened) {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
      break;
    }
      int x;
      std::cout << "\nВведите номер записи, котрую хотите удалить: ";
      std::cin >> x;
      if (x >= data.size()) {
        std::cout << "Запись с таким номер не существует.\n";
        system("pause");
        break;
      }
      deleteInformation(data, x, path, file_was_opened);
      break;
  }
   
  case 5: {       // сортировка    
    if (!file_was_opened) {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
      break;
    }
      int a;
      std::cout << "1. Сортровка по полной стоимости доставки.\n";
      std::cout << "2. Сортировка по расстоянию до пункта назначения.\n";
      std::cout << "Выбирете пункт меню(1-2) >>> ";
      std::cin >> a;
      if (a != 1 && a != 2) {
        std::cout << "Выбран неверный пункт меню\n";
        system("pause");
        break;
      }
      switch (a) {
      case 1: {
          sortDataByPrice(data);
          break;
      }
      case 2: {
          sortDataByDistance(data);
          break;
      }

      default:
          break;
      }
      break;
  }

  case 6: {
    if (file_was_opened) {
      std::cout << std::setw(11) << std::left << "Вес"
        << " " << std::setw(13) << "Тип" << " "
        << std::setw(9) << "Цена" << " "
        << std::setw(30) << "Комментарий" << " " << std::setw(12) << "Расстояние" << " "<< std::setw(16) 
        << "Тип доставки" <<" "<< "Полная цена груза" <<"\n";

      for (auto& inf : data) {
        printTabled(inf);
      }
      system("pause");
    }
    else {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
    }
    
  }
        break;

  case 7: {
    if (!file_was_opened) {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
      break;
    }
      int a;
      std::cout << "\n1. Поиск товара по названию.\n";
      std::cout << "2. Поиск данных по способу доставки.\n";
      std::cout << "3. Фильтрация данных по цене товара.\n";
      std::cout << "Выбирете пункт меню(1-3) >>> ";
      std::cin >> a;
      if (a != 1 && a != 2 && a != 3) {
        std::cout << "Выбран неверный пункт меню\n";
        system("pause");
        break;
      }
      switch (a) {
      case 1: {
          findInformationByName(data, file_was_opened);
          break;
      }
      case 2: {
          findInformationByTypeOfDelivering(data, file_was_opened);
          break;
      }
      case 3: {
          filtrationInformation(data, file_was_opened);
          break;
      }

      default:
          break;
      }
      break;
  }

  case 8: {
    createManager();
    break;
  }
    break;

  case 9: {
    changeManager();
    break;
  }
   break;
  default:
    break;
  }
}


void manager_choice(std::vector<Information>& data, int x, bool& file_was_opened, std::string& path) {
    
  switch (x)
  {
  case 1: {   // открытие или создание файла
    std::cout << "Введите название файла: ";
    std::cin >> path;
    openFile(data, path, file_was_opened);
    if (file_was_opened) {
      std::cout << "Файл был успешно открыт, а данные считаны.\n";
      system("pause");
    }
    else {
      std::cout << "Не удалось прочитать файл\n";
      system("pause");
    }
  }
        break;

  case 2: { // добавление записи
    appendObject(data, file_was_opened, path);
    break;
  }

  case 3: { // редактирование записи
    if (!file_was_opened) {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
      break;
    }
    int x;
    std::cout << "\nВведите номер записи, которую хотите изменить: ";
    std::cin >> x;
    if (x >= data.size()) {
      std::cout << "Запись с таким номер не существует.\n";
      system("pause");
      break;
    }
    changeInformation(data, x, path, file_was_opened);
    break;
  }
  case 4: { // удаление записи
    if (!file_was_opened) {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
      break;
    }
    int x;
    std::cout << "\nВведите номер записи, котрую хотите удалить: ";
    std::cin >> x;
    if (x >= data.size()) {
      std::cout << "Запись с таким номер не существует.\n";
      system("pause");
      break;
    }
    deleteInformation(data, x, path, file_was_opened);
    break;
  }

  case 5: {       // сортировка    
    if (!file_was_opened) {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
      break;
    }
    int a;
    std::cout << "1. Сортровка по полной стоимости доставки.\n";
    std::cout << "2. Сортировка по расстоянию до пункта назначения.\n";
    std::cout << "Выбирете пункт меню(1-2) >>> ";
    std::cin >> a;
    if (a != 1 && a != 2) {
      std::cout << "Выбран неверный пункт меню\n";
      system("pause");
      break;
    }
    switch (a) {
    case 1: {
      sortDataByPrice(data);
      break;
    }
    case 2: {
      sortDataByDistance(data);
      break;
    }

    default:
      break;
    }
    break;
  }

  case 6: { //просмотр данных в табличной форме
    if (file_was_opened) {
      std::cout << std::setw(11) << std::left << "Вес"
        << " " << std::setw(13) << "Тип" << " "
        << std::setw(9) << "Цена" << " "
        << std::setw(21) << "Комментарий" << " " << std::setw(12) << "Расстояние" << " " << std::setw(16)
        << "Тип доставки" << " " << "Полная цена груза" << "\n";

      for (auto& inf : data) {
        printTabled(inf);
      }
      system("pause");
    }
    else {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
    }

  }
        break;

  case 7: {   // поиск и фильтрация данных
    if (!file_was_opened) {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
      break;
    }
    int a;
    std::cout << "\n1. Поиск товара по названию.\n";
    std::cout << "2. Поиск данных по способу доставки.\n";
    std::cout << "3. Фильтрация данных по цене товара.\n";
    std::cout << "Выбирете пункт меню(1-3) >>> ";
    std::cin >> a;
    if (a != 1 && a != 2 && a != 3) {
      std::cout << "Выбран неверный пункт меню\n";
      system("pause");
      break;
    }
    switch (a) {
    case 1: {
      findInformationByName(data, file_was_opened);
      break;
    }
    case 2: {
      findInformationByTypeOfDelivering(data, file_was_opened);
      break;
    }
    case 3: {
      filtrationInformation(data, file_was_opened);
      break;
    }

    default:
      break;
    }
    break;
  }

  default:
    break;
  }
}


void user_choice(std::vector<Information>& data, int x, bool& file_was_opened, std::string& path) {
  switch (x)
  {
  case 1: {
    file_was_opened = false;
    std::cout << "Введите название файла: ";
    std::cin >> path;
    char r = ' ';
    data.clear();
    std::string str;
    std::ifstream fin;
    fin.open(path);  
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
    if (file_was_opened) {
      std::cout << "Файл был успешно открыт, а данные считаны.\n";
      system("pause");
    }
    else {
      std::cout << "Не удалось прочитать файл\n";
      system("pause");
    }
  }
        break;

  case 2: {
    if (file_was_opened) {
      std::cout << std::setw(11) << std::left << "Вес"
        << " " << std::setw(13) << "Тип" << " "
        << std::setw(9) << "Цена" << " "
        << std::setw(21) << "Комментарий" << " " << std::setw(12) << "Расстояние" << " " << std::setw(16)
        << "Тип доставки" << " " << "Полная цена груза" << "\n";

      for (auto& inf : data) {
        printTabled(inf);
      }
      system("pause");
    }
    else {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
    }

  }
        break;

  case 3: {
    if (!file_was_opened) {
      std::cout << "Вы не открвали файл и не читали оттуда данные\n";
      system("pause");
      break;
    }
    int a;
    std::cout << "\n1. Поиск товара по названию.\n";
    std::cout << "2. Поиск данных по способу доставки.\n";
    std::cout << "3. Фильтрация данных по цене товара.\n";
    std::cout << "Выбирете пункт меню(1-3) >>> ";
    std::cin >> a;
    if (a != 1 && a != 2 && a != 3) {
      std::cout << "Выбран неверный пункт меню\n";
      system("pause");
      break;
    }
    switch (a) {
    case 1: {
      findInformationByName(data, file_was_opened);
      break;
    }
    case 2: {
      findInformationByTypeOfDelivering(data, file_was_opened);
      break;
    }
    case 3: {
      filtrationInformation(data, file_was_opened);
      break;
    }

    default:
      break;
    }
    break;
  }
  default:
    break;
  }
}