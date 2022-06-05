#pragma once
#include <string>
#include <map>
#include <iostream>
#include <ostream>
#include <sstream>

enum class Gender{
    Male,
    Female
};





class Student{
    public:
    Student(const std::string& name,
            const std::string& lastName,
            const std::string& address,
            const int& indexNumber,
            const std::string& pesel,
            Gender gender);
    
            std::string show() const;
            Student enterData();
            std::string getlastName() const { return lastName_; }
            std::string getPesel() const { return pesel_;}
            int getindexNumber() const {return indexNumber_; }
            Gender getGender() const {return gender_;}
            std::string GenderToString(Gender gender);
            void setName(std::string name) {name_ = name;}

            std::map<Gender, std::string> genderPrint{{Gender::Female,"Female"}, {Gender::Male,"Male"}};
    private:
            std::string name_;
            std::string lastName_;
            std::string address_;
            int indexNumber_;
            std::string pesel_;
            Gender gender_;

};