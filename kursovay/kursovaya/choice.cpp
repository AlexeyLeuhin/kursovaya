#include "choice.h"

std::vector<Information> admin_choice(std::vector<Information>& data, int x, bool& file_was_opened) {

  switch (x)
  {
  case 1: {
    std::string path;
    std::cout << "Введите название файла: ";
    std::cin >> path;
    data = openFile(path, file_was_opened);
    if (file_was_opened) {
      std::cout << "Файл был успешно открыт, а данные считаны.\n";
      system("pause");
    }
    else {
      std::cout << "Не удалось прочитать файл\n";
      system("pause");
    }
    return data;
  }
   break;

  case 2: {
    data = appendObject(data, file_was_opened);
    return data;
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
    
    return data;
  }
        break;
  default:
    break;
  }
}