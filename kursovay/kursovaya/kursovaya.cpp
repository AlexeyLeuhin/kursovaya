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

  while (true) {
    draw_menu(check.first);
     
    try {
      check = choose_menu_point(check.first);
    }
    catch (int a) {
      if (a == -1) {    //был выбран "выход" в главном меню
        return 0;
      }
      if (a == -2) {
        std::cout << "Выбран неверный пункт меню, попробуйте еще раз\n";
        system("pause");
        continue;
      }  
    }

    if (check.second == -1) {        // мы находились в главном меню, пункты далее впроверять не нужно
      continue;
    }

    switch (check.first)
    {
    case MAIN:
      filepath = "";
      file_was_opened = false;
      data.clear();
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

