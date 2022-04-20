#pragma once
#include <algorithm>
#include <list>
#include <queue>

class sorting {
public:
	static void bubble(int* start, int length);
	static void insertion(int* start, int length);
	static void mergeSort(int* start, int left, int right);
	static void quick(int* start, int low, int high);
	//static void counting(int* start, int length);
	static void radix(int* start, int length);

private:
	static int* merge(int* start, int left, int mid, int rl);
};

