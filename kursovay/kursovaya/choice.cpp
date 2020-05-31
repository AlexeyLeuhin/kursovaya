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

  case 2: {
    appendObject(data, file_was_opened, path);
  }
   break;

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

  case 8: {
    createManager();
    break;
  }
    break;
  default:
    break;
  }
}