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

  case 2: { // ���������� ������
    appendObject(data, file_was_opened, path);
    break;
  }
   
  case 3: { // �������������� ������

      int x;
      std::cout << "\n������� ����� ������, ������� ������ ��������: ";
      std::cin >> x;
      changeInformation(data, x, path);
      break;
  }
  case 4: { // �������� ������
      int x;
      std::cout << "\n������� ����� ������, ������ ������ �������: ";
      std::cin >> x;
      deleteInformation(data, x, path);
      break;
  }
   
  case 5: {       // ����������                                        
      int a;
      std::cout << "1. ��������� �� ������ ��������� ��������.\n";
      std::cout << "2. ���������� �� ���������� �� ������ ����������.\n";
      std::cout << "�������� ����� ����(1-2) >>> ";
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

  case 7: {
      int a;
      std::cout << "\n1. ����� ������ �� ��������.\n";
      std::cout << "2. ����� ������ �� ������� ��������.\n";
      std::cout << "3. ���������� ������ �� ���� ������.";
      std::cout << "�������� ����� ����(1-3) >>> ";
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