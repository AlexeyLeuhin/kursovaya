#pragma once
#include <string>
#include <vector>
#include "Information.h"


std::vector<Information> openFile(const std::string& filepath, bool& file_was_opened);
std::string toString(const Information& inf);
void printTabled(const Information& inf);
std::vector<Information> appendObject(const std::vector<Information>& data, bool& file_was_opened);