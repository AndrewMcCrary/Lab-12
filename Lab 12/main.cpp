#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <random>
#include <list>
#include <chrono>
#include "sorting.h"
#include "student.h"

// Ricky Roberts, Andrew McCrary and Vitta Silberberg
// All contributions equal

using namespace std;


int main() {

    int* test10 = new int[10];
    int* test100 = new int[100];
    int* test500 = new int[500];
    int* test5000 = new int[5000];
    int* test25000 = new int[25000];
    int* test100000 = new int[100000];

    srand(time(NULL));

    for (int i = 0; i < 10; i++) test10[i] = rand() % 20;
    for (int i = 0; i < 100; i++) test100[i] = rand() % 200;
    for (int i = 0; i < 500; i++) test500[i] = rand() % 1000;
    for (int i = 0; i < 5000; i++) test5000[i] = rand() % 10000;
    for (int i = 0; i < 25000; i++) test25000[i] = rand() % 50000;
    for (int i = 0; i < 100000; i++) test100000[i] = rand() % 200000;

    std::list<studentData> Student = std::list<studentData>();

#pragma region Students
    Student.emplace_back(studentData("Andrew", "McCrary", 00000001));
    Student.emplace_back(studentData("Richard", "Roberts", 00000002 ));
    Student.emplace_back(studentData("Vitta", "Silberberg", 00000003));
    Student.emplace_back(studentData("Anirudh", "Bharadwaj", 17348942));
    Student.emplace_back(studentData("Chris", "Christodoulou", 0125623));
    Student.emplace_back(studentData("Fblthp", "Lstsl", 85901265));
    Student.emplace_back(studentData("Zndrsplt", "Lzrblst", 74890571));
    Student.emplace_back(studentData("Chandra", "Nalaar", 36148731));
    Student.emplace_back(studentData("Jace", "Beleren", 65907123));
    Student.emplace_back(studentData("Ob", "Nixilis", 67940165)); //10th
    Student.emplace_back(studentData("Liliana", "Vess", 67950313));
    Student.emplace_back(studentData("Niv", "Mizzet", 87641659));
    Student.emplace_back(studentData("Gideon", "Jura", 16738014));
    Student.emplace_back(studentData("Ajani", "Goldmane", 78940371));
    Student.emplace_back(studentData("Nicol", "Bolas", 63901643));
    Student.emplace_back(studentData("Billie", "Eilish", 53168943));
    Student.emplace_back(studentData("Daniel", "Tingstad", 43712403));
    Student.emplace_back(studentData("Scarlett", "Chartier", 36431876));
    Student.emplace_back(studentData("MJ", "Johnson", 78903165));
    Student.emplace_back(studentData("Malcolm", "Blackthorn", 01632556)); //20th
    Student.emplace_back(studentData("Will", "Kenrith", 89514132));
    Student.emplace_back(studentData("Rowan", "Kenrith", 89514133));
    Student.emplace_back(studentData("Ral", "Zarek", 87641660));
    Student.emplace_back(studentData("Kudro", "Drannith", 64387913));
    Student.emplace_back(studentData("Vivien", "Reed", 37591334));
    Student.emplace_back(studentData("Bruno", "Mars", 69696969));
    Student.emplace_back(studentData("Lil", "Darkie", 66666666));
    Student.emplace_back(studentData("Robert", "Plant", 05361570));
    Student.emplace_back(studentData("Kanye", "West", 11236243));
    Student.emplace_back(studentData("Trevor", "Bauer", 64387912)); //30th
    Student.emplace_back(studentData("Tyler", "Blevins", 99999999));
    Student.emplace_back(studentData("Morty", "Sanchez", 69420666));
    Student.emplace_back(studentData("Rick", "Sanchez", 69420667));
    Student.emplace_back(studentData("Ricky", "Bobby", 11111111));
    Student.emplace_back(studentData("Will", "Smith", 14353242));
    Student.emplace_back(studentData("Jesus", "Christ", 10101010));
    Student.emplace_back(studentData("Patrick", "Star", 55555555));
    Student.emplace_back(studentData("Vladimir", "Putin", 90000000));
    Student.emplace_back(studentData("Judas", "Escariot", 96431444));
    Student.emplace_back(studentData("Spongebob", "Squarepants", 51515234)); //40th
    Student.emplace_back(studentData("Basri", "Ket", 31584311));
    Student.emplace_back(studentData("Charles", "Zimmer", 10011111));
    Student.emplace_back(studentData("Neville", "Pinto", 54381256));
    Student.emplace_back(studentData("Sample", "Text", 14357415));
    Student.emplace_back(studentData("Johnson", "Johnson", 01010101));
    Student.emplace_back(studentData("Mark", "Fishbach", 13371337));
    Student.emplace_back(studentData("Zain", "Hamid", 13317777));
    Student.emplace_back(studentData("Matthew", "Leung", 64352544));
    Student.emplace_back(studentData("Nitin", "Nitin", 00150000));
    Student.emplace_back(studentData("Osama", "Laden", 00150001)); //50th
#pragma endregion

    cout << "####### UNSORTED #######\n";
    for (auto i : Student)
        cout << std::setw(10) << std::left << i.fname << std::setw(15) << std::left << i.lname << std::setw(10) << std::left << i.number << endl;
    cout << endl << endl;

	bool connectionTerminated = false;
	while (!connectionTerminated) {
        std::cout << "\nStudent Sorting Menu\n\n [1] Buuble By First Name\n [2] Insetrion By M Number\n [3] Radix By Last Name\n";
        int choice = 0;
		std::cin >> choice;
		bool correct = true;
		int base, dest;
		switch (choice) {
		case 1:
            std::cout << "\nYou selected [1] Buuble By First Name. Do you want this ascending(0) or descending(1): ";
            cin >> correct;

            Student = sorting::studentBubble(Student, correct);
            cout << "####### SORTED #######\n";
            for (auto i : Student)
                cout << std::setw(10) << std::left << i.fname << std::setw(15) << std::left << i.lname << std::setw(10) << std::left << i.number << endl;
			break;
		case 2:
            std::cout << "\nYou selected [2] Insetrion By M Number. Do you want this ascending(0) or descending(1): ";
            cin >> correct;

            Student = sorting::studentInsertion(Student, correct);
            cout << "####### SORTED #######\n";
            for (auto i : Student)
                cout << std::setw(10) << std::left << i.fname << std::setw(15) << std::left << i.lname << std::setw(10) << std::left << i.number << endl;
            break;
		case 3:
            std::cout << "\nYou selected [2] Insetrion By M Number. Do you want this ascending(0) or descending(1): ";
            cin >> correct;

            Student = sorting::studentRadix(Student, correct);
            cout << "####### SORTED #######\n";
            for (auto i : Student)
                cout << std::setw(10) << std::left << i.fname << std::setw(15) << std::left << i.lname << std::setw(10) << std::left << i.number << endl;
            break;
		default:
			continue;
		};
		std::cout << "\nContinue? [0 = yes/1 = no]: ";
		std::cin >> connectionTerminated;
	}


    


    //double duration;
    //auto start = chrono::steady_clock::now();

    //sorting::mergeSort(test10, 0, 9);

    //auto end = chrono::steady_clock::now();

    //cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds for 10" << endl;

    //start = chrono::steady_clock::now();

    //sorting::mergeSort(test100, 0, 99);

    //end = chrono::steady_clock::now();

    //cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds for 100" << endl;

    //start = chrono::steady_clock::now();

    //sorting::mergeSort(test500, 0, 499);

    //end = chrono::steady_clock::now();

    //cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds for 500" << endl;

    //start = chrono::steady_clock::now();

    //sorting::mergeSort(test5000, 0, 4999);

    //end = chrono::steady_clock::now();

    //cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds for 5000" << endl;

    //start = chrono::steady_clock::now();

    //sorting::mergeSort(test25000, 0, 24999);

    //end = chrono::steady_clock::now();

    //cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds for 25000" << endl;

    //start = chrono::steady_clock::now();

    //sorting::mergeSort(test100000, 0, 99999);

    //end = chrono::steady_clock::now();

    //cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds for 100000" << endl;



    return 0;
}
