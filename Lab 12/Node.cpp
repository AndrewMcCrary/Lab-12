#include "Node.h"

Node::Node(int m, std::string fir, std::string las)
{
	this->M = m;
	this->First = fir;
	this->Last = las;
}

Node::~Node()
{
	if (this->Next && this->Prev) {
		this->Prev->Next = this->Next;
		this->Next->Prev = this->Prev;
	}
}

int Node::getM()
{
	return this->M;
}

std::string Node::getFirst()
{
	return this->First;
}

std::string Node::getLast()
{
	return this->Last;
}