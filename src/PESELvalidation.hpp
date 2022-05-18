#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
class PESELvalidation
{
public:
    bool validatePESELsize(const std::string &pesel);
    bool validatePESELmonth(const std:: string &pesel);
    bool validatePESELcontrolNumber(const std::string &pesel);
    bool validatePESEL(const std::string &pesel);
private:
    

};


