#include "PESELvalidation.hpp"


bool PESELvalidation::validatePESELsize(const std::string &pesel)
{
    return (pesel.size()==11) ? true : false;
}