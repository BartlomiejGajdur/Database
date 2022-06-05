#include "record.hpp"

std::string Record::getGenderString() const
{
    if(gender_== Gender::Female)
        return "Female";
    else
        return "Male";
}

std::string Student::show() const 
{   
    return getName() + " " + getSurname() + "; "+getAddress()+"; "
    + getindexNumber()+ "; "+getPesel()+ "; "+getGenderString()+"\n";
}

    

// Student Student::enterData()
// {
//     std::string name;
//     std::string lastName;
//     std::string address;
//     int indexNumber = 4;
//     std::string pesel;
//     Gender gender = Gender::Female;
    
//     Student student("0","0","0",indexNumber,"1",gender);

//     std::cin>>name;
//     student.setName(name);

//     return student;

// }