#include <iostream>
#include "student.hpp"
#include "database.hpp"


int main(){

    Database db;
    Student bg("Bartek", "Gajdur","Mikolajowice 21, 33,121,",128994,"991101030443",Gender::Male);
    Student ba("Bartek", "Łuczyński","Mikolajowice 21, 33,121,",128994,"991101030443",Gender::Male);
    Student bc("Bartek", "Drab","Mikolajowice 21, 33,121,",128994,"4444213",Gender::Male);
    Student bd("Bartek", "Caban","Mikolajowice 21, 33,121,",128994,"991101030443",Gender::Male);
    Student jp("Bartek", "Drab","Mikolajowice 21, 33,121,",128994,"111",Gender::Female);

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


    std::cout<<"Hello, World! ";
    std::cout<<std::endl;
    

    return 0;
}