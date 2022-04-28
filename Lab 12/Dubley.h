#pragma once
#include "Node.h"
#include <iostream>


class Dubley
{
public:
	Dubley() {};
	Dubley(Node* start);
	~Dubley();
	void AddItem(Node* var);
	bool IsInList(int Mnum);
	bool IsEmpty();
	int Size();
	void printList();
	//void bubbleWithFirstNames(bool desc);
private:
	Node* Current = nullptr;
	Node* _head = nullptr;
};

inline Dubley::Dubley(Node* start)
{
	this->_head = start;
}

inline Dubley::~Dubley()
{
	while (this->_head != nullptr) {
		this->Current = this->_head->Next;
		delete this->_head;
		this->_head = this->Current;
	}
}

inline void Dubley::AddItem(Node* var)
{
	var->Next = this->_head;
	this->_head = var;
}

inline bool Dubley::IsInList(int Mnum)
{
	Node* temp = this->_head;
	while (temp != nullptr) {
		if (temp->getM() == Mnum)
			return true;
		temp = temp->Next;
	}
	return false;
}

inline bool Dubley::IsEmpty()
{
	return this->_head == nullptr;
}

inline int Dubley::Size()
{
	Node* temp = this->_head;
	int i = 0;
	while (temp != nullptr) {
		i++;
		temp = temp->Next;
	}
	return i;
}

inline void Dubley::printList()
{
	Node* temp = this->_head;
	if (temp == nullptr) {
		std::cout << "\nList is empty.\n";
	}
	else {
		while (temp != nullptr) {
			std::cout << temp->getM() << std::endl;
			temp = temp->Next;
		}
	}
}

//inline void Dubley::bubbleWithFirstNames(bool desc)
//{
//	Node* temp;
//	Node* i = this->_head;
//	int y = 0; 
//	while (i != nullptr) {
//		Node* j = this->_head;
//		int x = 0; 
//		while (x < this->Size() - y - 1) {
//			if (j->getFirst().compare(j->Next->getFirst()) < 0) {
//				temp = j;
//				j = j->Next;
//				j->Next = temp;
//			}
//			x++;
//			j = j->Next;
//		}
//		y++;
//		i = i->Next;
//	}
//	
//}