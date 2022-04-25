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

void sorting::mergeSort(int* start, int const begin, int const end) {
    if (begin < end) {
        int middle = begin + ((end - begin) / 2);

        mergeSort(start, 0, middle);
        mergeSort(start, middle + 1, end);

        merge(start, begin, middle, end);
    }
}

void sorting::merge(int* arr, int left, int middle, int right) { // left is first index, middle is last index of left, middle + 1 is first index of right, right is last index
// Create L ← A[left..middle] and M ← A[middle+1..r]
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* L = new int[n1];
    int* M = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[middle + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    // Until we reach either end of either L or M, leftick larger among
    // elements L and M and leftlace them in the correct leftosition at A[left..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // leftick uleft the remaining elements and leftut in A[left..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
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

void sorting::counting(int* start, int length) {
    int max = start[0];
    for (int i = 1; i < length; i++)
        if (start[i] > max)
            max = start[i];

    int* arr = new int[max + 1] {0};

    for (int i = 0; i < length; i++)
        arr[start[i]]++;

    int index = 0;
    for (int i = 0; i < max + 1; i++)
        while (arr[i] > 0) {
            start[index] = i;
            arr[i]--;
            index++;
        }

}

void sorting::radix(int* start, int length) {
    for (int i = 0, bit = 1; i < (sizeof(int) * 8) - 1; ++i, bit <<= 1) {
        binaryCounting(start, length, bit);
    }
}

void sorting::binaryCounting(int* start, int length, int bit) {
    // counts[0] stores the number of items with a 0 in this bit
    // counts[1] stores the number of items with a 1 in this bit
    int* counts = new int[] {0, 0};

    for (int i = 0; i < length; i++) {
        counts[(start[i] & bit) == bit]++;
    }


    int* zeros = new int[counts[0]];
    int* ones = new int[counts[1]];;

    int zi = 0;
    int oi = 0;

    for (int i = 0; i < length; i++) {
        bool bitval = (start[i] & bit) == bit;
        if (bitval)
            ones[oi++] = start[i];
        else
            zeros[zi++] = start[i];
    }

    copy(zeros, zeros + counts[0], start);
    copy(ones, ones + counts[1], start + counts[0]);
    delete[] zeros, ones, counts;
}
