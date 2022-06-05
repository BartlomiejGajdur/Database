#include "database.hpp"


void Database::add(std::shared_ptr<Record> record)
{
        database_.push_back(record);
        
}

void Database::display() const 
{
        std::cout<< show();
}

std::string Database::show() const
{
    std::string result = "";
    for(auto && student :database_)
        result += student->show();
    return result;
}

std::string Database::findLastName(std::string lastName) const
{   
    std::string result = "";
    for(auto && student :database_)
    {
        if(lastName == student->getSurname())
        {
            result += student->show();
        }
    }
    return result;
}

std::string Database::findPesel(std::string pesel)const
{
    std::string result = "";
    for(auto && student :database_)
    {
        if(pesel == student->getPesel())
        {
            result += student->show();
        }
    }
    return result;
}

void Database::sortBySurname()
{
    sort(database_.begin(),database_.end(),[](auto l, auto r)
    {return l->getSurname() < r->getSurname(); });
}

void Database::sortByPesel()
{
    sort(begin(database_), end(database_),[] (auto l, auto r)
        {return l->getPesel() < r->getPesel();});
}

// void Database::deleteByIndexNumber(const std::string& index)
// {
//     // auto it = students_.begin();
//     // for(auto && students : students_)
//     // {
//     //     if(students->getindexNumber() == index) //Chyba musze ogarnac ze jednak z klasy pierwotnej wychodza wszystkie funckje sa one virtuane w pochodnej override tylko np tam gdzie ma nic nie zwracać ( employyee -> index) zwraca nic np.
//     //     {
//     //         students_.erase(it);
//     //     }
//     //     it++;
//     // }

// }



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