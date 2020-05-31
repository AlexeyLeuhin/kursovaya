#include "menu.h"

void draw_menu(MENU_TYPE type) {
  switch (type)
  {
  case MAIN:
    draw_main_menu();
    break;
  case ADMIN:
    draw_admin_menu();
    break;
  case MANAGER:
    draw_manager_menu();
    break;
  case USER:
    draw_user_menu();
    break;

  default:
    break;
  }
}

void draw_main_menu() {
  system("cls");
  std::cout << "1. ���� - �������������\n";
  std::cout << "2. ���� - ��������\n";
  std::cout << "3. ���� - ������������\n";
  std::cout << "4. �����\n";
}

void draw_admin_menu() {
  system("cls");
  std::cout << "1. �������/������� ����\n";
  std::cout << "2. �������� ������\n";
  std::cout << "3. ������������� ������\n";
  std::cout << "4. ������� ������\n";
  std::cout << "5. ����������� ������\n";
  std::cout << "6. ������� ������ � ���� �������\n";
  std::cout << "7. ����� � ���������� �������\n";
  std::cout << "8. �������� ���������\n";
  std::cout << "9. �������� �����/������ ���������\n";
  std::cout << "10. ����� � ������� ����\n";
}

void draw_manager_menu() {
  system("cls");
  std::cout << "1. �������/������� ����\n";
  std::cout << "2. �������� ������\n";
  std::cout << "3. ������������� ������\n";
  std::cout << "4. ������� ������\n";
  std::cout << "5. ����������� ������\n";
  std::cout << "6. ������� ������ � ���� �������\n";
  std::cout << "7. ����� � ���������� �������\n";
  std::cout << "8. ����� � ������� ����\n";
}

void draw_user_menu() {
  system("cls");
  std::cout << "1. ������� ����\n";
  std::cout << "2. ������� ������ � ���� �������\n";
  std::cout << "3. ����� � ���������� �������\n";
  std::cout << "4. ����� � ������� ����\n";
}

std::pair<MENU_TYPE, int> choose_menu_point(MENU_TYPE curr_type) {
  int x;
  MENU_TYPE type;
  std::cout << "������� ����� ����, ������� ������ �������: ";
  std::cin >> x;

  switch (curr_type) {
    case MAIN: {
      switch (x) {
      case 1:
        type = ADMIN;
        break;
      case 2:
        type = MANAGER;
        break;
      case 3:
        type = USER;
        break;
      default:
        std::cout << "���������� ���������";
        throw - 1;      //���������� ���������
        break;
      }  
      return std::make_pair(type, -1);
     }
      break;

    case ADMIN: {
      if (x >= 1 && x <= 9) {
        return  std::make_pair(ADMIN, x);
      }
      else if(x==10) {
        return  std::make_pair(MAIN, x);
      }
      else {
        throw - 2; //  ������ ������������ ����� ����
      }
    }
      break;

    case MANAGER: {
      if (x >= 1 && x <= 7) {
        return std::make_pair(MANAGER, x);
      }
      else if (x == 8) {
        return std::make_pair(MAIN, x);
      }
      else {
        throw - 2; //  ������ ������������ ����� ����
      }
    }
      break;

    case USER: {
      if (x >= 1 && x <= 3) {
        return  std::make_pair(USER, x);
      }
      else if (x == 4) {
        return  std::make_pair(MAIN, x);
      }
      else {
        throw - 2; //  ������ ������������ ����� ����
      }
    }
       break;


    default:
      break;   
  }
}