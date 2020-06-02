#include "menu.h"
#include "choice.h"


int main()
{
  bool file_was_opened = false;
  std::string filepath;
  setlocale(LC_ALL, "Russian");
  std::pair < MENU_TYPE, int> check;    // check  = (type of menu, point of menu)
  check.first = MENU_TYPE::MAIN;
  std::vector<Information> data;
  bool authenticated = false;
  bool admin_auth = false;
  std::string admin_pass;
  std::cout << "Введите пароль администратора: ";
  std::cin >> admin_pass;
  system("pause");
  system("cls");
  while (true) {   // main cicle
    draw_menu(check.first, authenticated, admin_auth, admin_pass);    // takes type of menu and draws it
     
    try {
      check = choose_menu_point(check.first);   //enables to choose menu point, throws exception if wrong point
    }                                         //return pair (type of menu, point of menu)
    catch (int a) {
      if (a == -1) {    //was chosen exit point in main menu
        return 0;
      }
      if (a == -2) {
        std::cout << "Выбран неверный пункт меню, попробуйте еще раз\n";
        system("pause");
        continue;
      }  
    }

    if (check.second == -1) {        // dont need to check points of main menu 
      continue;
    }

    switch (check.first)      //realiztion of chosen point
    {
    case MAIN:      //after we quit to main menu program should clear its buffer
      filepath = "";
      file_was_opened = false;
      data.clear();
      authenticated = false;
      admin_auth = false;
      break;
    case ADMIN:
      admin_choice(data, check.second, file_was_opened, filepath);
      break;
    case MANAGER:
      manager_choice(data, check.second, file_was_opened, filepath);
      break;
    case USER:
      user_choice(data, check.second, file_was_opened, filepath);
      break;

    default:
      break;
    }

  }
  
  return 0;

}

