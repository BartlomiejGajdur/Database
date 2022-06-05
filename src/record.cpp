#include "record.hpp"

Student::Student(
    const std::string& name,
    const std::string& lastName,
    const std::string& address,
    const int& indexNumber,
    const std::string& pesel,
    Gender gender)
    : name_(name),
      lastName_(lastName),
      address_(address),
      indexNumber_(indexNumber),
      pesel_(pesel),
      gender_(gender)
{
}

std::string Student::show() const
{
    return name_ + " " + lastName_ + "; "+address_+"; "
    + std::to_string(indexNumber_) + "; "+pesel_+ "; "+genderPrint.at(getGender())+"\n";
}

Student Student::enterData()
{
    std::string name;
    std::string lastName;
    std::string address;
    int indexNumber = 4;
    std::string pesel;
    Gender gender = Gender::Female;
    
    Student student("0","0","0",indexNumber,"1",gender);

    std::cin>>name;
    student.setName(name);

    return student;

}