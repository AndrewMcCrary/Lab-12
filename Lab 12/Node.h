#pragma once
#include <string>

class Node
{
public:
	Node(int m, std::string fir, std::string las);
	~Node();
	Node* Next = nullptr;
	Node* Prev = nullptr;
	int getM();
	std::string getFirst();
	std::string getLast();
private:
	int M;
	std::string First;
	std::string Last;
};