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

        //Functions
        virtual std::string show() const = 0;
        virtual std::string getindexNumber() const = 0;
        std::string getGenderString() const;
        std::string getStatusString() const; 
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

        //Getter
        std::string getindexNumber() const override {return indexNumber_; }

        //Setter
        void setindexNumber(const std::string& indexNumber) {indexNumber_ = indexNumber;}

        //Functions
        std::string show() const override;


private:
std::string indexNumber_;

};

class Employee : public Record
{
public:
Employee(const std::string& name,
        const std::string& surname,
        const std::string& address,
        const std::string& pesel,
        Gender gender,
        const int& salary) :
        Record(Status::Employee,name,surname,address,pesel,gender),
        salary_(salary)
        {}

        //Getter
        int getSalary() const {return salary_;}
        std::string getindexNumber() const override {return "123445"; }
        //Setter
        void setSalary(const int& salary) {salary_ = salary;}

        //Functions
        std::string show() const override
        {
            return getStatusString()+": "+getName() + " " + getSurname() + "; "+getAddress()+"; "+
                std::to_string(getSalary())+"zl "+ "; "+getPesel()+ "; "+getGenderString()+"\n";
        }

       


private:
int salary_;

        

};