#pragma once

#include "functions.h"

void admin_choice(std::vector<Information>& data, int x, bool& file_was_opened, std::string& path, std::string& pass);
void manager_choice(std::vector<Information>& data, int x, bool& file_was_opened, std::string& path);
void user_choice(std::vector<Information>& data, int x, bool& file_was_opened, std::string& path);
