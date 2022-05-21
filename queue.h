#pragma once
#include <iostream>
#include "check.h"

template <typename T1>
struct node {
	T1 value;
	node* next;
};

template <typename T>
class Queue {
public:
	Queue() {
		_first = nullptr;
		_last = nullptr;
		_size = 0;
	}
	Queue(const Queue& obj) {
		_first = nullptr;
		_last = nullptr;
		for (node<T>* i = obj._first; i != nullptr; i = i->next) {
			this->push(i->value);
		}
	}
	~Queue() {
		node<T>* temp = nullptr;
		do {
			temp = _first->next;
			delete _first;
			_first = temp;
		} while (_first != nullptr);
		_size = 0;
	}

	Queue<T>& operator=(const Queue<T>& q) {
		if (this == &q) return *this;

		while (_first != nullptr) {
			auto next = _first->next;
			delete _first;
			_first = next;
		}
		_first = _last = nullptr;

		for (node<T>* i = q._first; i != nullptr; i = i->next) {
			this->push(i->value);
		}

		return *this;
	}

	template <typename T>
	friend Queue<T> operator +(const Queue<T>& l, const Queue<T>& r);
	template <typename T>
	friend Queue<T> operator -(const Queue<T>& l, const Queue<T>& r);

	template <typename T>
	friend std::ostream& operator<< (std::ostream& out, const Queue<T>& p);
	template <typename T>
	friend std::istream& operator>> (std::istream& in, Queue<T>& p);

	void operator!() {
		if (Queue<T>::isEmpty()) std::cout << "Queue is Empty" << std::endl;
	}

protected:
	void push(T val) {
		if (isEmpty()) {
			_last = init(val);
			_first = _last;
		}
		else {
			_last = addElem(_last, val);
		}
		_size++;
	}
	node<T>* init(T val) {
		node<T>* temp = new node<T>[1];
		temp->value = val;
		temp->next = nullptr;
		return temp;
	}
	bool isEmpty() {
		return (_first == nullptr ? true : false);
	}
	node<T>* addElem(node<T>* elem, T value) {
		node<T>* temp = new node<T>[1];
		elem->next = temp;
		temp->value = value;
		temp->next = nullptr;
		return temp;
	}

private:
	node<T>* _first;
	node<T>* _last;
	unsigned int _size;
};

template <typename T>
std::istream& operator>> (std::istream& in, Queue<T>& obj) {
	T value;
	in >> value;
	if (in.fail() || in.get() != '\n') throw "Incorrect input";
	std::cout << "\n";
	obj.push(value);

	return in;
}
template <>
std::istream& operator>> (std::istream& in, Queue<char*>& obj) {
	char* value = new char[128];
	in >> value;
	if (in.fail() || in.get() != '\n') throw "Incorrect input";
	std::cout << "\n";
	obj.push(value);

	return in;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const Queue<T>& obj) {
	if(obj._first == nullptr) std::cout << "Queue is Empty" << std::endl;
	for (node<T>* i = obj._first; i != nullptr; i = i->next) {
		out << i->value << "\t";
	}
	out << "\n";
	return out;
}

template <typename T>
Queue<T> operator -(const Queue<T>& l, const Queue<T>& r) {
	if (l._size != r._size) throw "Size mismatch";
	Queue<T> temp;
	for (node<T>* i = l._first, * j = r._first; i != nullptr && j != nullptr; i = i->next, j = j->next) {
		temp.push(i->value - j->value);
	}
	
	return temp;
}

template <>
Queue<char> operator - <char>(const Queue<char>& l, const Queue<char>& r) {
	throw "Incorrect type";
}

template <>
Queue<char*> operator - <char*>(const Queue<char*>& l, const Queue<char*>& r) {
	throw "Incorrect type";
}


template <typename T>
Queue<T> operator +(const Queue<T>& l, const Queue<T>& r) {
	if (l._size != r._size) throw "Size mismatch";
	Queue<T> temp;
	for (node<T>* i = l._first, * j = r._first; i != nullptr && j != nullptr; i = i->next, j = j->next) {
		temp.push(i->value + j->value);
	}
	
	return temp;
}

template <>
Queue<char> operator + <char>(const Queue<char>& l, const Queue<char>& r) {
	throw "Incorrect type";
}

template <>
Queue<char*> operator + <char*>(const Queue<char*>& l, const Queue<char*>& r) {
	if (l._size != r._size) throw "Size mismatch";

	Queue<char*> temp;
	for (node<char*>* i = l._first, * j = r._first; i != nullptr && j != nullptr; i = i->next, j = j->next) {
		char* buffer = new char[128];
		buffer[0] = '\0';
		strcat_s(buffer, 128, i->value);
		strcat_s(buffer, 128, j->value);
		temp.push(buffer);
	}
	
	return temp;
}
