#include "PESELvalidation.hpp"
#include "student.hpp"

bool PESELvalidation::validatePESEL(const std::string &pesel)
{
    if(validatePESELsize(pesel)==false)
    {
        std::cout<<"Pesel is invalid";
        return false;
    }
    if(validatePESELmonth(pesel)==false)
    {
        std::cout<<"Pesel is invalid";
        return false;
    }
    if(validatePESELcontrolNumber(pesel)==false)
    {
        std::cout<<"Pesel is invalid";
        return false;
    }
    std::cout<<"Pesel is valid";
        return true;
}


bool PESELvalidation::validatePESELsize(const std::string &pesel)
{
    return (pesel.size()==11) ? true : false;
}

bool PESELvalidation::validatePESELmonth(const std:: string &pesel)
{
    std::string Month = pesel.substr(2, 2);
    std::string Day = pesel.substr(4, 2);

    if (std::stoi(Month) < 1 && std::stoi(Month) > 12)
    {
        return false;
    }
    if (std::stoi(Month) == 2 && (std::stoi(Day) < 1 || std::stoi(Day) > 29))
    {
        return false;
    }
    if ((std::stoi(Month) == 4 || std::stoi(Month) == 6 || std::stoi(Month) == 9 || std::stoi(Month) == 11) && (std::stoi(Day) < 1 || std::stoi(Day) > 30))
    {
        return false;
    }
    if ((std::stoi(Month) == 1 || std::stoi(Month) == 3 || std::stoi(Month) == 5 || std::stoi(Month) == 7 || std::stoi(Month) == 8 || std::stoi(Month) == 10 || std::stoi(Month) == 12) && (std::stoi(Day) < 1 && std::stoi(Day) > 31))
    {
        return false;
    }
    return true;
}

bool PESELvalidation::validatePESELcontrolNumber(const std::string &pesel)
{
      std::vector<int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::transform(begin(weights), end(weights), begin(pesel), begin(weights),
                   [](auto weight, auto PESELNumber)
                   { return weight * (PESELNumber - '0'); });
    std::string tempStr = std::to_string(std::accumulate(begin(weights), end(weights), 0));
    int controlNumber = 10 - (tempStr.back() - '0');
    if(controlNumber == 10)
    {
        controlNumber = 0;
    }

    if (controlNumber != (pesel.back() - '0'))
    {
        return false;
    }
    return true;
}