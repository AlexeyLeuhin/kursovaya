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
void sortDataByPrice(std::vector<Information>&);
void sortDataByDistance(std::vector<Information>&);
void changeInformation(std::vector<Information>& a, int x, const std::string& filepath);