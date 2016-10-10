#include "stdafx.h"
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

void ReadFile(std::map<std::string, std::set<std::string>> & people)
{
	std::ifstream file("db.csv");
	std::string str;
	std::getline(file, str);
	while (std::getline(file, str))
	{
		std::stringstream lineStr(str);
		std::string word;
		std::string id;
		int counter = 0;
		while (std::getline(lineStr, word, ','))
		{
			if (counter == 0)
			{
				id = word;
				counter++;
				continue;
			}
			if (counter == 4)
				people[word.c_str()].insert(id.c_str());
			counter++;
		}
	}
}

int main()
{
	std::map<std::string, std::set<std::string>> people;
	ReadFile(people);
	std::string name;
	std::set<std::string> names;
	std::cout << "Enter name: ";
	std::cin >> name;
	while (name != "Exite")
	{
		auto namesMap = people.find(name);
		if (namesMap != people.end())
		{
			names = namesMap->second;
			for (auto id : names)
			{
				std::cout << id << " ";
			}
			std::cout << std::endl << "Enter name: ";
			std::cin >> name;
		}
		else
		{
			std::cout << "Name not found. Enter name: ";
			std::cin >> name;
		}
	}
    return 0;
}

