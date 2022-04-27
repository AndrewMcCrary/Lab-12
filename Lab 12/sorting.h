#pragma once
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <list>
#include "student.h"

class sorting {
public:
	static void bubble(int* start, int length);
	static void insertion(int* start, int length);
	static void mergeSort(int* start, int left, int right);
	static void quick(int* start, int low, int high);
	static void counting(int* start, int length);
	static void radix(int* start, int length);
	static std::list<studentData> studentRadix(std::list<studentData> l, bool desc);
	static std::list<studentData> studentInsertion(std::list<studentData> l, bool desc);
	static std::list<studentData> studentBubble(std::list<studentData> l, bool desc);
private:
	static void merge(int* start, int left, int mid, int rl);
	static void binaryCounting(int* start, int length, int bit);
};

