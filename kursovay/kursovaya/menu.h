#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>

enum MENU_TYPE { MAIN, ADMIN, MANAGER, USER };

void draw_main_menu();
void draw_admin_menu();
void draw_manager_menu();
void draw_user_menu();
std::pair<MENU_TYPE,int> choose_menu_point(MENU_TYPE curr_type);
void draw_menu(MENU_TYPE& type, bool& authen, bool& admin_auth, std::string admin_pass);
bool checkingManager();
