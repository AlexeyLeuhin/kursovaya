#pragma once
#include <string>
#include <vector>
#include "Information.h"
#include <iostream>
#include <algorithm>

void openFile(std::vector<Information>& data, std::string& filepath, bool& file_was_opened);
std::string toString(const Information& inf);
void printTabled(const Information& inf);
void appendObject(std::vector<Information>& data, bool& file_was_opened, std::string filepath);
void createManager();