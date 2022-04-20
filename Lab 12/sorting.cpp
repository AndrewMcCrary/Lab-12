#include "sorting.h"

using namespace std;

void sorting::bubble(int* start, int length) {
    int temp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (start[j] > start[j + 1]) {
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }
}

void sorting::insertion(int* start, int length) {
	int i, key, j;
    for (i = 1; i < length; i++) {
        key = start[i];
        j = i - 1;
        while (j >= 0 && start[j] > key) {
            start[j+1] = start[j];
            j = j - 1;
        }
        start[j+1] = key;
    }
}

void sorting::mergeSort(int* start, int begin, int end) {

    int middle = (end + begin) / 2;

    if (end - begin <= 1)
        return;

    // Left
    mergeSort(start, 0, middle);
    // Right
    mergeSort(start, middle + 1, end);

    merge(start, begin, middle, end);
}

void sorting::quick(int* start, int low, int high) {
    if (low < high) {
        
        int pivot = start[high];
        int x = low - 1; 
        int temp;
        for (int y = low; y < high; y++) {
            if (start[y] <= pivot) {
                x++;
                temp = start[x];
                start[x] = start[y];
                start[y] = temp;
            }
        }
        temp = start[x+1];
        start[x+1] = start[high];
        start[high] = temp;

        pivot = x + 1;
        quick(start, low, pivot - 1);
        quick(start, pivot + 1, high);
    }
}
/*
void sorting::counting(int* start, int length) {
    int max = start[0];
    for (int x = 1; x < length; x++) {
        if (start[x] > max) max = start[x];
    }
    int occs[max+1];
    for (int x = 0; x <= max; x++) {
        occs[x] = 0;
    }
    for (int x = 0; x < length; x++) {
        occs[start[x]]++;
    }
    for (int x = 1; x <= max; x++) {
        occs[x] += occs[x - 1];
    }
    int output[length];
    for (int x = length - 1; x >= 0; x--) {
        output[occs[start[x]] - 1] = start[x];
        occs[start[x]]--;
    }
    for (int x = 0; x < length; x++) {
        start[x] = output[x];
    }
}*/

void sorting::radix(int* start, int length) {
    queue<int> ones = queue<int>();
    queue<int> zeros = queue<int>();

    for (int i = 0, bit = 1; i < sizeof(int) * 8; ++i, bit <<= 1) {
        for (int j = 0; j < length; j++) {
            if ((bit & start[j]) == bit)
                ones.push(start[j]);
            else
                zeros.push(start[j]);
        }

        int index = 0;
        while (!zeros.empty()) {
            start[index++] = zeros.front();
            zeros.pop();
        }

        while (!ones.empty()) {
            start[index++] = ones.front();
            ones.pop();
        }
    }
    
}

int* sorting::merge(int* start, int left, int mid, int right) { // [left, right)
    // assumes that both individual arrays are already sorted
    int ls = left;
    int rs = mid + 1;
    int* sorted = new int[right - left];

    for (int i = 0; i < right - left; i++) {
        if (ls < mid + 1 && rs < right) {
            if (start[ls] > start[rs])
                sorted[i] = start[rs++];
            else
                sorted[i] = start[ls++];
        }
        else if (ls < mid + 1)
            sorted[i] = start[ls++];
        else
            sorted[i] = start[rs++];
    }
    copy(sorted, sorted + right - left, &(start[left]));
    delete sorted;
    return start;
}
