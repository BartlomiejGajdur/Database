#pragma once
#include "record.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include "PESELvalidation.hpp"
#include <memory>
class Database {
    public:
        void add(std::shared_ptr<Record>);
        void display() const;
        std::string show() const;
        std::string findLastName(std::string lastName) const;
        std::string findPesel(std::string pesel) const;
        void sortBySurname();
        void sortByPesel();
        //void deleteByIndexNumber(const std::string&);
        void mainMenu() const ;
        void chooseFromMenu();
    private:
        std::vector<std::shared_ptr<Record>> database_;
};