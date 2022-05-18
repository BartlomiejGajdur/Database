#include "database.hpp"


void Database::add(const Student &s)
{
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



void Database::mainMenu() const
{   
    system("clear");
    std::cout<<"===================================\n";
    std::cout<<"1. Add student\n";
    std::cout<<"2. Show all students\n";
    std::cout<<"3. Find students by surname\n";
    std::cout<<"4. Find students by Pesel\n";
    std::cout<<"5. Sort students by surname\n";
    std::cout<<"6. Sort students by Pesel\n";
    std::cout<<"7. Remove student by index number\n";
    std::cout<<"8. Check pesel\n";
    std::cout<<"===================================\n";
    std::cout<<"Insert a number between 1-9 and click enter: \n";
}

void Database::chooseFromMenu()
{
    mainMenu();
    int choose;
    std::cin>>choose;
    PESELvalidation pesel1;
    std::string zmienna;

    switch(choose)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
        system("clear");
        std::cin>>zmienna;
        std::cout<<pesel1.validatePESEL(zmienna);
            break;
        default:
            std::cout<<"Choose a noumber [1-8] and click ENTER";
            break;
    }
}