#include <iostream>
#include "bsearch.h"
#include "queue.h"
#include "check.h"

template <typename T>
void q() {
	int select;
	Queue<T> q1, q2, res_q;
	Queue<T>* temp = nullptr;
	do {
		std::cout << "\nFirst Queue: \n" << q1 <<
			"\nSecond Queue: \n" << q2 << 
			"\nResult Queue: \n" << res_q << std::endl;
		std::cout << "\n1. !=\n"
			"2. SuB\n"
			"3. Sum\n"
			"4. Push\n"
			"5. Exit\n";

		select = getData<int>();

		switch (select)
		{
		case 1:
			do {
				std::cout << "Choose queue [1 or 2]:\n";
				select = getData<int>();
			} while (select <= 0 || select >= 3);
			(select == 1) ? temp = &q1 : temp = &q2;
			!*temp;
			temp = nullptr;
			break;
		case 2:
			try {
				res_q = q1 - q2;
			}
			catch (const char* m) {
				std::cout << m << '\n';
			}

			break;
		case 3:
			try {
				res_q = q1 + q2;
			}
			catch (const char* m) {
				std::cout << m << '\n';
			}
			break;
		case 4:
			do {
				std::cout << "Choose queue [1 or 2]:\n";
				select = getData<int>();
			} while (select <= 0 || select >= 3);
			(select == 1) ? temp = &q1 : temp = &q2;
			std::cout << "Enter a value: ";
			try {
				std::cin >> *temp;
			}
			catch (const char* m) {
				std::cout << m << '\n';
			}
			temp = nullptr;
			break;
		case 5:
			return;
			break;
		default:
			break;
		}

	} while (true);
	return;
}

int main() {
	srand(time(NULL));
	int select;
	do {
		std::cout << "1. Queue\n"
			"2. BSearch\n"
			"3. Exit\n";
		select = getData<int>();
		switch (select)
		{
		case 1:
			std::cout << "Select the data type\n"
				"1. Int\n"
				"2. Float\n"
				"3. Double\n"
				"4. Char\n"
				"5. Char*\n"
				"6. Exit\n";

			select = getData<int>();

			switch (select)
			{
			case 1:
				q<int>();
				break;
			case 2:
				q<float>();
				break;
			case 3:
				q<double>();
				break;
			case 4:
				q<char>();
				break;
			case 5:
				q<char*>();
				break;
			default:
				break;
			}


			break;
		case 2:
		{
			std::cout << "Select type\n"
				"1. Int\n"
				"2. Float\n"
				"3. Double\n"
				"4. Char\n"
				"5. Char*\n"
				"6. Exit\n";

			select = getData<int>();
			switch (select)
			{
			case 1:
				try {
					bSearch<int>();
				}
				catch (const char* m) {
					std::cout << m << '\n';
				}
				break;
			case 2:
				try {
					bSearch<float>();
				}
				catch (const char* m) {
					std::cout << m << '\n';
				}
				break;
			case 3:
				try {
					bSearch<double>();
				}
				catch (const char* m) {
					std::cout << m << '\n';
				}
				break;
			case 4:
				try {
					bSearch<char>();
				}
				catch (const char* m) {
					std::cout << m << '\n';
				}
				break;
			case 5:
				try {
					bSearch<char*>();
				}
				catch (const char* m) {
					std::cout << m << '\n';
				}
				break;
			default:
				break;
			}
		}
		break;
		case 3:
			return 1;
			break;
		default:
			break;
		}
	} while (true);


	return 0;
}