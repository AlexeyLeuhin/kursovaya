#include "choice.h"

void admin_choice(std::vector<Information>& data, int x, bool& file_was_opened, std::string& path) {

  switch (x)
  {
  case 1: {
    std::cout << "������� �������� �����: ";
    std::cin >> path;
    openFile(data, path, file_was_opened);
    if (file_was_opened) {
      std::cout << "���� ��� ������� ������, � ������ �������.\n";
      system("pause");
    }
    else {
      std::cout << "�� ������� ��������� ����\n";
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