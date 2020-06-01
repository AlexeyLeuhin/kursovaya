#pragma once
#include <string>
#include <vector>
#include "Information.h"
#include <iostream>
#include <algorithm>
#include <map>

void openFile(std::vector<Information>& data, std::string& filepath, bool& file_was_opened);
std::string toString(const Information& inf);
void printTabled(const Information& inf);
void appendObject(std::vector<Information>& data, bool& file_was_opened, std::string filepath);
void createManager();
void sortDataByPrice(std::vector<Information>&);
void sortDataByDistance(std::vector<Information>&);
void changeInformation(std::vector<Information>& a, int x, const std::string& filepath, bool& file_was_opened);
void deleteInformation(std::vector<Information>& a, int x, const std::string& filepath, bool& file_was_opened);
void findInformationByName(const std::vector<Information>& a, bool& file_was_opened);
void findInformationByTypeOfDelivering(const std::vector<Information>& a, bool& file_was_opened);
void filtrationInformation(const std::vector<Information>& a, bool& file_was_opened);
void changeManager();
