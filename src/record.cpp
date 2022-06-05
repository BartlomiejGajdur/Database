#include "record.hpp"

std::string Record::getGenderString() const
{
    if(gender_== Gender::Female)
        return "Female";
    else
        return "Male";
}

std::string Record::getStatusString() const
{
    if(status_ == Status::Student)
        return "Student";
    else 
        return "Employee";
}

std::string Student::show() const 
{   
    return "Student: "+getName() + " " + getSurname() + "; "+getAddress()+"; "
    + getindexNumber()+ "; "+getPesel()+ "; "+getGenderString()+"\n";
}

    