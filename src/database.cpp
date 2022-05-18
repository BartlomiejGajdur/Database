#include "database.hpp"
#include "PESELvalidation.hpp"

void Database::add(const Student &s)
{

   // PESELvalidation pesel;
    
   // if(pesel.validatePESEL(s.getPesel())== true)
        students_.push_back(s);

}

void Database::display() const 
{
        std::cout<< show();
}

std::string Database::show() const
{
    std::string result = "";
    for(auto && student :students_)
        result += student.show();
    return result;
}

std::string Database::findLastName(std::string lastName) const
{   
    std::string result = "";
    for(auto && student :students_)
    {
        if(lastName == student.getlastName())
        {
            result += student.show();
        }
    }
    return result;
}

std::string Database::findPesel(std::string pesel)const
{
    std::string result = "";
    for(auto && student :students_)
    {
        if(pesel == student.getPesel())
        {
            result += student.show();
        }
    }
    return result;
}

void Database::sortBySurname()
{
    sort(students_.begin(),students_.end(),[](auto l, auto r)
    {return l.getlastName() < r.getlastName(); });
}

void Database::sortByPesel()
{
    sort(begin(students_), end(students_),[] (auto l, auto r)
        {return l.getPesel() < r.getPesel();});
}

void Database::deleteByIndexNumber(const int& index)
{
    auto it = students_.begin();
    for(auto && students : students_)
    {
        if(students.getindexNumber() == index)
        {
            students_.erase(it);
        }
        it++;
    }

}
