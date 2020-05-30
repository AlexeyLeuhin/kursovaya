#include "choice.h"

std::vector<Information> admin_choice(std::vector<Information>& data, int x, bool& file_was_opened) {

  switch (x)
  {
  case 1: {
    std::string path;
    std::cout << "������� �������� �����: ";
    std::cin >> path;
    data = openFile(path, file_was_opened);
    if (file_was_opened) {
      std::cout << "���� ��� ������� ������, � ������ �������.\n";
      system("pause");
    }
    else {
      std::cout << "�� ������� ��������� ����\n";
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
      std::cout << std::setw(11) << std::left << "���"
        << " " << std::setw(13) << "���" << " "
        << std::setw(9) << "����" << " "
        << std::setw(16) << "�����������" << " " << std::setw(12) << "����������" << " " << "��� ��������" << "\n";

      for (auto& inf : data) {
        printTabled(inf);
      }
      system("pause");
    }
    else {
      std::cout << "�� �� �������� ���� � �� ������ ������ ������\n";
      system("pause");
    }
    
    return data;
  }
        break;
  default:
    break;
  }
}