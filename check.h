#pragma once
#include <iostream>

template <typename C>
C getData() {
	C temp;
	std::cin >> temp;
	while (std::cin.fail() || std::cin.get() != '\n') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.sync();
		std::cout << "Enter again: ";
		std::cin >> temp;
	}
	return temp;
}

template <>
char* getData<char*>() {
	char* temp = new char[128];
	std::cin >> temp;

	while (std::cin.fail() || std::cin.get() != '\n') {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.sync();
		std::cin >> temp;
	}
	return temp;
}