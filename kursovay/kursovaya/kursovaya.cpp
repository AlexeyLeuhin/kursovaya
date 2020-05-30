#include "menu.h"
#include "choice.h"


int main()
{
  bool file_was_opened = false;
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
        continue;
      }  
    }

    if (check.second == -1) {        // мы находились в главном меню, пункты далее впроверять не нужно
      continue;
    }

    switch (check.first)
    {
    case MAIN:
      continue;
      break;
    case ADMIN:
      data = admin_choice(data, check.second, file_was_opened);
      break;
    case MANAGER:
      break;
    case USER:
      break;

    default:
      break;
    }

  }
  
  std::cout << "Fuck you!";

}

