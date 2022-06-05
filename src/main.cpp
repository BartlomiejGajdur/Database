#include <iostream>
#include "record.hpp"
#include "database.hpp"
#include "PESELvalidation.hpp"
#include "menu.hpp"
#include <string>

int main(){

    Database db;
    Student bg("Bartek", "Gajdur","Mikolajowice 21, 33,121,","991101030443",Gender::Male,"128944");
    Student ba("Bartek", "Łuczyński","Mikolajowice 21, 33,121,","991101030443",Gender::Male,"128944");
    Student bc("Bartek", "Drab","Mikolajowice 21, 33,121,","4444213",Gender::Male,"128944");
    Student bd("Bartek", "Caban","Mikolajowice 21, 33,121,","991101030443",Gender::Male,"128944");
    Student jp("Bartek", "Drab","Mikolajowice 21, 33,121,","111",Gender::Female,"128944");

    db.add(bg);
    db.add(ba);
    db.add(bc);
    db.add(bd);
    db.add(jp);


    std::cout<<db.show();
    std::cout<<std::endl<<std::endl;
    db.sortBySurname();
    std::cout<<db.show();
    std::cout<<std::endl<<std::endl;
    std::cout<<db.findLastName("Drab");
    std::cout<<std::endl<<std::endl;
    std::cout<<db.findPesel("111");
    
    return 0;
}