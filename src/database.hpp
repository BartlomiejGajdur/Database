#pragma once
#include "student.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
class Database {
    public:
        void add(const Student& s);
        void display() const;
        std::string show() const;
        std::string findLastName(std::string lastName) const;
        std::string findPesel(std::string pesel) const;
        void sortBySurname();
        void sortByPesel();
        void deleteByIndexNumber(const int&);
    private:
        std::vector<Student> students_;
};