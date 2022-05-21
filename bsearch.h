#pragma once
#include <random>
#include <time.h>
#include <iostream>
#include "check.h"

template <typename T>
void swap(T& left, T& right) {
    auto temp = left;
    left = right;
    right = temp;
}

template <typename D>
D* enterArr(D* arr, int size) {
	for (int i = 0; i < size; i++) {
        std::cout << i << ". ";
		*(arr + i) = getData<D>();
	}
	return arr;
}

template <>
char** enterArr<char*>(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = getData<char*>();
    }
    return arr;
}

template <typename B>
B* fillArr(B* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = (float)(rand() % 256 - 128) + (float)(rand() % 100) / 100;
    }
    return arr;
}

template <>
int* fillArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = rand() % 256 - 128;
    }
    return arr;
}

template <>
char* fillArr(char* arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = rand() % 94 + 33;
    }
    return arr;
}

template <>
char** fillArr<char*>(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        int size_str = rand() % 10 + 2;
        char* buffer = new char[size_str];
        for (int j = 0; j < size_str - 1; j++) {
            buffer[j] = rand() % 94 + 33;
        }
        buffer[size_str - 1] = '\0';
        arr[i] = buffer;
    }
    return arr;
}

template <typename A>
A* sort(A* arr, int size) {
	for (int i = 1; i < size; ++i) {
		for (int j = 0; j < size - i; j++) {
			if (arr[j] > arr[j + 1]) {
                swap<A>(arr[j], arr[j + 1]);
			}
		}
	}
    return arr;
}

template <>
char** sort<char*>(char** arr, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size - i; j++) {
            if (strlen(arr[j]) > strlen(arr[j + 1])) {
                swap<char*>(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

template <typename T>
void bSearch() {
    T seek;
    int size;
    T* arr;

    do {
        std::cout << "Enter the size of the array" << std::endl;
        size = getData<int>();
    } while (size<=0);
    arr = new T[size];
    int choice;
    do {
        std::cout << "1. Enter an array from the keyboard\n2. Fill the array with random values\n" << std::endl;
        choice = getData<int>();
    } while (choice <= 0 || choice >= 3);

    if (choice == 1) {
        arr = enterArr<T>(arr, size);
        std::cout << "\n";
    }

    else {
        arr = fillArr<T>(arr, size);

        for (int i = 0; i < size; i++) {
            std::cout << i << ". " << arr[i] << std::endl;
        }
        std::cout << "\n";
    }


    arr = sort<T>(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout << i << ". " << arr[i] << std::endl;
    }
    std::cout << "\n";

    std::cout << "Enter the item you want to find" << std::endl;
    seek = getData<T>();
    

    


	int search = -1;
    bool isExist = false;
	int l = 0;
	int r = size - 1;
	int m;

    while (l <= r) 
    {
        m = (l + r) / 2; 
        if (seek == *(arr + m)) {  
            search = m;    
            isExist = true;
            break;            
        }
        if (seek < *(arr + m))     
            r = m - 1;  
        else                
            l = m + 1;   
    }
    if (!isExist) throw "There is no searched element in this list";

    std::cout << search << std::endl;
}

template <>
void bSearch<char*>() {
    char* seek;
    int size = 0;
    char** arr;

    do {
        std::cout << "Enter the size of the array" << std::endl;
        size = getData<int>();
    } while (size <= 0);
    arr = new char*[size];

    int choice;
    do {
        std::cout << "1. Enter an array from the keyboard\n2. Fill the array with random values\n" << std::endl;
        choice = getData<int>();
    } while (choice <= 0 || choice >= 3);

    if (choice == 1) {
        arr = enterArr<char*>(arr, size);
        std::cout << "\n";
    }

    else {
        arr = fillArr<char*>(arr, size);

        for (int i = 0; i < size; i++) {
            std::cout << i << ". " << arr[i] << std::endl;
        }
        std::cout << "\n";
    }


    arr = sort<char*>(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout << i << ". " << arr[i] << std::endl;
    }
    std::cout << "\n";

    std::cout << "Enter the item you want to find" << std::endl;
    seek = getData<char*>();



    int search = -1;
    bool isExist = false;
    int l = 0;
    int r = size - 1;
    int m;

    while (l <= r) // пока левая граница не "перескочит" правую
    {
        m = (l + r) / 2; // ищем середину отрезка
        if (strcmp(seek, *(arr + m)) == 0) {  // если ключевое поле равно искомому
            search = m;     // мы нашли требуемый элемент,
            isExist = true;
            break;            // выходим из цикла
        }
        if (strlen(seek) < strlen(*(arr + m)))     // если искомое ключевое поле меньше найденной середины
            r = m - 1;  // смещаем правую границу, продолжим поиск в левой части
        else                  // иначе
            l = m + 1;   // смещаем левую границу, продолжим поиск в правой части
    }
    if (!isExist) throw "There is no searched element in this list";
    std::cout << search << std::endl;
}