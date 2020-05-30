#pragma once

#include <iostream>
enum MENU_TYPE { MAIN, ADMIN, MANAGER, USER };

void draw_main_menu();
void draw_admin_menu();
void draw_manager_menu();
void draw_user_menu();
std::pair<MENU_TYPE,int> choose_menu_point(MENU_TYPE curr_type);
void draw_menu(MENU_TYPE type);
