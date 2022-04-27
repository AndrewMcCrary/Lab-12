#pragma once
#include <string>

struct studentData {
public:
    studentData(std::string fname, std::string lname, int number) {
        this->fname = fname;
        this->lname = lname;
        this->number = number;
    }
    std::string fname;
    std::string lname;
    int number;
};
