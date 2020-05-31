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
  std::cout << "1. Вход - администратор\n";
  std::cout << "2. Вход - менеджер\n";
  std::cout << "3. Вход - пользователь\n";
  std::cout << "4. Выход\n";
}

void draw_admin_menu() {
  system("cls");
  std::cout << "1. Создать/открыть файл\n";
  std::cout << "2. Добавить запись\n";
  std::cout << "3. Редактировать запись\n";
  std::cout << "4. Удалить запись\n";
  std::cout << "5. Сортировать записи\n";
  std::cout << "6. Вывести данные в виде таблицы\n";
  std::cout << "7. Поиск и фильтрация записей\n";
  std::cout << "8. Создание менеджера\n";
  std::cout << "9. Изменить логин/пароль менеджера\n";
  std::cout << "10. Выйти в главное меню\n";
}

void draw_manager_menu() {
  system("cls");
  std::cout << "1. Создать/открыть файл\n";
  std::cout << "2. Добавить запись\n";
  std::cout << "3. Редактировать запись\n";
  std::cout << "4. Удалить запись\n";
  std::cout << "5. Сортировать записи\n";
  std::cout << "6. Вывести данные в виде таблицы\n";
  std::cout << "7. Поиск и фильтрация записей\n";
  std::cout << "8. Выйти в главное меню\n";
}

void draw_user_menu() {
  system("cls");
  std::cout << "1. Открыть файл\n";
  std::cout << "2. Вывести данные в виде таблицы\n";
  std::cout << "3. Поиск и фильтрация записей\n";
  std::cout << "4. Выйти в главное меню\n";
}

std::pair<MENU_TYPE, int> choose_menu_point(MENU_TYPE curr_type) {
  int x;
  MENU_TYPE type;
  std::cout << "Введите пункт меню, который хотите выбрать: ";
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
        std::cout << "Завершение программы";
        throw - 1;      //завершение программы
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
        throw - 2; //  выбран непраивльный пункт меню
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
        throw - 2; //  выбран непраивльный пункт меню
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
        throw - 2; //  выбран непраивльный пункт меню
      }
    }
       break;


    default:
      break;   
  }
}