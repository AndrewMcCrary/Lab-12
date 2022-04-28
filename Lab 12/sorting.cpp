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

void sorting::mergeSort(int* array, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        merge(array, l, m, r);
    }
}

void sorting::merge(int* array, int l, int m, int r) {
    int left, right, k, nl, nr;

    nl = m - l + 1;
    nr = r - m;

    int* larr = new int[nl];
    for (left = 0; left < nl; left++)
        larr[left] = array[l + left];

    int* rarr = new int[nr];
    for (right = 0; right < nr; right++)
        rarr[right] = array[m + 1 + right];

    left = 0; right = 0; k = l;
    while (left < nl && right < nr) {
        if (larr[left] <= rarr[right]) {
            array[k] = larr[left];
            left++;
        }
        else {
            array[k] = rarr[right];
            right++;
        }
        k++;
    }

    while (left < nl) {
        array[k] = larr[left];
        left++; k++;
    }

    while (right < nr) {
        array[k] = rarr[right];
        right++; k++;
    }

    delete[] larr, rarr;
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

list<studentData> sorting::studentRadix(list<studentData> l, bool desc) {    
    vector<studentData> sorted = vector<studentData>(l.size());
    std::copy(l.begin(), l.end(), sorted.begin());

    unsigned int max = 0;
    for (int i = 0; i < l.size(); i++)
        if (sorted[i].lname.size() > max)
            max = sorted[i].lname.size();

    for (int i = max - 1; i >= 0; i--) {
        vector<studentData> students;
        vector<studentData> vec[27];

        for (int j = 0; j < l.size(); j++) {
            if (sorted[j].lname.size() < i + 1) {
                vec[0].push_back(sorted[j]);
                continue;
            }

            vec[tolower(sorted[j].lname[i]) - 96].push_back(sorted[j]);
        }

        for (auto v : vec) {
            for (auto s : v) {
                students.push_back(s);
            }
        }

        sorted.clear();
        sorted = students;
    }

    list<studentData> out;
    std::copy(sorted.begin(), sorted.end(), std::back_inserter(out));

    if (desc)
        out.reverse();

    return out;
}

list<studentData> sorting::studentInsertion(std::list<studentData> l, bool desc) {
    vector<studentData> sorted = vector<studentData>(l.size());
    std::copy(l.begin(), l.end(), sorted.begin());

    int i, j;
    studentData key;
    for (i = 1; i < sorted.size(); i++) {
        key = sorted[i];
        j = i - 1;
        while (j >= 0 && sorted[j].number > key.number) {
            sorted[j + 1] = sorted[j];
            j = j - 1;
        }
        sorted[j + 1] = key;
    }

    list<studentData> out;
    std::copy(sorted.begin(), sorted.end(), std::back_inserter(out));

    if (desc)
        out.reverse();

    return out;
}

std::list<studentData> sorting::studentBubble(std::list<studentData> l, bool desc) {
    vector<studentData> sorted = vector<studentData>(l.size());
    std::copy(l.begin(), l.end(), sorted.begin());

    studentData temp;

    for (int i = 0; i < sorted.size(); i++) {
        for (int j = 0; j < sorted.size() - i - 1; j++) {
            if (strcmp(sorted[j].fname.c_str(), sorted[j + 1].fname.c_str()) > 0) {
                temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    list<studentData> out;
    std::copy(sorted.begin(), sorted.end(), std::back_inserter(out));

    if (desc)
        out.reverse();

    return out;
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

    std::copy(zeros, zeros + counts[0], start);
    std::copy(ones, ones + counts[1], start + counts[0]);
    delete[] zeros, ones, counts;
}
