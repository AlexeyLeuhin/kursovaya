#include "menu.h"

void draw_menu(MENU_TYPE& type, bool& authenticated) {
  switch (type)
  {
  case MAIN:
    draw_main_menu();
    break;
  case ADMIN:
    draw_admin_menu();
    break;
  case MANAGER:   // manager has to log in
    if (!authenticated) {
      if (checkingManager()) {    //checks if manager logged in
        draw_manager_menu();
        authenticated = true;
      }
      else {
        draw_main_menu();
        type = MAIN;
      }
    }
    else {
      draw_manager_menu();
    }
    
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

  switch (curr_type) {      //check if was chosen correct point
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
        throw - 1;      //exit from programm
        break;
      }  
      return std::make_pair(type, -1);
     }
      break;

    case ADMIN: {
      if (x >= 1 && x <= 9) {
        return  std::make_pair(ADMIN, x);
      }
      else if(x==10) {      //exit point
        return  std::make_pair(MAIN, x);
      }
      else {
        throw - 2; //  incorrect point of menu was chosen
      }
    }
      break;

    case MANAGER: {
      if (x >= 1 && x <= 7) {
        return std::make_pair(MANAGER, x);
      }
      else if (x == 8) {    //exit point
        return std::make_pair(MAIN, x);
      }
      else {
        throw - 2; //  incorrect point of menu was chosen
      }
    }
      break;

    case USER: {
      if (x >= 1 && x <= 3) {
        return  std::make_pair(USER, x);
      }
      else if (x == 4) { // exit point
        return  std::make_pair(MAIN, x);
      }
      else {
        throw - 2; //  incorrect point of menu was chosen
      }
    }
       break;


    default:
      break;   
  }
}

//checks authentication of manager
bool checkingManager() {
    char r = ' ';
    std::ifstream fin;
    std::map<std::string, std::string> log_pass;    //stores all accounts
    std::string log, str, pass;
    fin.open("managers.txt"); 
    while (fin.good()) {      //read accounts from file
        getline(fin, str);
        std::size_t pos = str.find(r);
        log = str.substr(0, pos);
        pass = str.substr(pos + 1, str.length() - log.length());
        log_pass[log] = pass;
    }
    fin.close();

    std::cout << "\n������� �����: ";     //user enters login and password
    std::cin >> log;
    auto it = log_pass.find(log);
    if (it != log_pass.end()) {     //checks if they are correct
        while (true) {
            std::cout << "������� ������: ";
            std::cin >> pass;

            if (log_pass[log] == pass) {
                std::cout << "����� ���������� � �������, �������� " << log << "!\n";
                system("pause");
                return 1;
            }
            else {
                std::cout << "�������� ������!\n";
                system("pause");
            }
        }

    }
    else {      //error
        std::cout << "������������� � ����� ������� �� ����������!\n";
        system("pause");
        return 0;
    }


}