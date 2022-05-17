#pragma once
#include <string>
#include <map>

enum class Gender{
    Male,
    Female
};

// //Sposob pierwszy przy uzyciu ostream
// std::ostream& operator+(Gender gender_,std::ostream& jakis)
// {
//     switch(gender_)
//     {
//         case Gender::Male   : jakis<<"Male";     break;
//         case Gender::Female : jakis<<"Female";   break;
//     }
//     return jakis;
// }
// //Sposob drugi zwykly string
// std::string operator+(Gender gender_)
// {
//     if(gender_== Gender::Male)
//         return "Male";
//     if(gender_==Gender::Female)
//         return "Female";
// }




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