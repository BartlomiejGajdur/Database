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

enum class Status{
    Student,
    Employee
};

class Record{

public:
Record( Status status,
        const std::string& name,
        const std::string& surname,
        const std::string& address,
        const std::string& pesel,
        Gender gender) :
        status_(status),
        name_(name),
        surname_(surname),
        address_(address),
        pesel_(pesel),
        gender_(gender)
        {}

        //Getters
        Status getStatus() const {return status_;}
        std::string getName() const {return name_;}
        std::string getSurname() const {return surname_;}
        std::string getAddress() const {return address_;}
        std::string getPesel() const {return pesel_;}
        Gender getGender() const {return gender_;}

        

        //Setters
        void setStatus(Status status){status_=status;}
        void setName(const std::string& name) {name_=name;}
        void setSurname(const std::string& surname) {surname_=surname;}
        void setAddress(const std::string& address) {address_=address;}
        void setPesel(const std::string& pesel) {pesel_=pesel;}
        void setGender(Gender gender){gender_=gender;}

        //virtual void setByStatus(const std::string&) const = 0;

        virtual std::string show() const = 0;
        std::string getGenderString() const;
        std::string getStatusString() const ; // Optional -> IndexNumber for Student / Salary for Employee
private:  
    Status status_; 
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string pesel_;
    Gender gender_;


};



class Student : public Record{

public:
Student(const std::string& name,
        const std::string& lastName,
        const std::string& address,
        const std::string& pesel,
        Gender gender,
        const std::string& indexNumber) : 
        Record(Status::Student,name,lastName,address,pesel,gender),
        indexNumber_(indexNumber)
        {}


        std::string show() const override;
        std::string getindexNumber() const {return indexNumber_; }

private:
std::string indexNumber_;







    // public:
    // Student(const std::string& name,
    //         const std::string& lastName,
    //         const std::string& address,
    //         const int& indexNumber,
    //         const std::string& pesel,
    //         Gender gender);
    
    //         
    //         
    //         
            
    //         std::string GenderToString(Gender gender);
           

    //         std::map<Gender, std::string> genderPrint{{Gender::Female,"Female"}, {Gender::Male,"Male"}};
    // private:
            
    //         int indexNumber_;
            

};