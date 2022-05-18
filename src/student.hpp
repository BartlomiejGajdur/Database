#pragma once
#include <string>
#include <map>

enum class Gender{
    Male,
    Female
};


class Student{
    public:
    Student(std::string name,
            std::string lastName,
            std::string address,
            int indexNumber,
            std::string pesel,
            Gender gender);
    
            std::string show() const;
            std::string getlastName() const { return lastName_; }
            std::string getPesel() const { return pesel_;}
            int getindexNumber() const {return indexNumber_; }
            Gender getGender() const {return gender_;}

            std::map<Gender, std::string> genderPrint{{Gender::Female,"Female"}, {Gender::Male,"Male"}};
    private:
            std::string name_;
            std::string lastName_;
            std::string address_;
            int indexNumber_;
            std::string pesel_;
            Gender gender_;

};