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

      int x;
      std::cout << "\nВведите номер записи, которую хотите изменить: ";
      std::cin >> x;
      changeInformation(data, x, path);
      break;
  }
  case 4: { // удаление записи
      int x;
      std::cout << "\nВведите номер записи, котрую хотите удалить: ";
      std::cin >> x;
      deleteInformation(data, x, path);
      break;
  }
   
  case 5: {       // сортировка                                        
      int a;
      std::cout << "1. Сортровка по полной стоимости доставки.\n";
      std::cout << "2. Сортировка по расстоянию до пункта назначения.\n";
      std::cout << "Выбирете пункт меню(1-2) >>> ";
      std::cin >> a;
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
        << std::setw(16) << "Комментарий" << " " << std::setw(12) << "Расстояние" << " " << "Тип доставки" << "\n";

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
      int a;
      std::cout << "\n1. Поиск товара по названию.\n";
      std::cout << "2. Поиск данных по способу доставки.\n";
      std::cout << "3. Фильтрация данных по цене товара.";
      std::cout << "Выбирете пункт меню(1-3) >>> ";
      std::cin >> a;
      switch (a) {
      case 1: {
          findInformationByName(data);
          break;
      }
      case 2: {
          findInformationByTypeOfDelivering(data);
          break;
      }
      case 3: {
          filtrationInformation(data);
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
  default:
    break;
  }
}