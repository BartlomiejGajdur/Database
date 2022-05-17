#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

TEST(DisplayDb, DisplayEmptyDB){

    Database db;
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content,expected);


}

TEST(DisplayDb, DisplayNonEmptyDB){

    Database db;

    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "00110103033",
        Gender::Male 
        };
        Student maciek{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "00110103033",
        Gender::Male 
        };

    db.add(adam);
    db.add(maciek);
    // check adding the same person twice

    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 00110103033; Male\nAdam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 00110103033; Male\n";
    EXPECT_EQ(content,expected);

}

TEST(FindLastName, SerchLastNameWhenIsMoreThan1)
{
    Database db;
    Student adam{
        "Adam",
        "Maruda",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "00110103033",
        Gender::Male 
        };
    Student maciek{
        "Maciek",
        "Maruda",
        "ul. cos 134, 00-200 Krakow",
        234567,
        "2313331233",
        Gender::Male 
        };
    Student Kacper{
        "Kacper",
        "Kacperski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "00110103033",
        Gender::Male 
        };

    db.add(adam);
    db.add(maciek);
    db.add(Kacper);

    
    auto content = db.findLastName("Maruda");
    auto expected = "Adam Maruda; ul. Dobra 134, 00-200 Warszawa; 123456; 00110103033; Male\nMaciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 2313331233; Male\n";
    EXPECT_EQ(content,expected);
}

TEST(FindPesel, SerchForPesel)
{
     Database db;
    Student adam{
        "Adam",
        "Maruda",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11111111111",
        Gender::Male 
        };
    Student maciek{
        "Maciek",
        "Maruda",
        "ul. cos 134, 00-200 Krakow",
        234567,
        "22222222222",
        Gender::Male 
        };
    Student Kacper{
        "Kacper",
        "Kacperski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "333333333333",
        Gender::Male 
        };

    db.add(adam);
    db.add(maciek);
    db.add(Kacper);

    auto content = db.findPesel("22222222222");
    auto expected = "Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 22222222222; Male\n";
    EXPECT_EQ(content,expected);
}

TEST(SortLastName, SortByLastName)
{
     Database db;

    Student adam{
        "Adam",
        "Bwulski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "00110103033",
        Gender::Male 
        };
        Student maciek{
        "Maciek",
        "Asinski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "00110103033",
        Gender::Male 
        };

    db.add(adam);
    db.add(maciek);
    // check adding the same person twice
    db.sortBySurname();
    auto content = db.show();
    auto expected = "Maciek Asinski; ul. Dobra 134, 00-200 Warszawa; 123456; 00110103033; Male\nAdam Bwulski; ul. Dobra 134, 00-200 Warszawa; 123456; 00110103033; Male\n";
    EXPECT_EQ(content,expected);

    
}

TEST(SortPesel, SortByPesel)
{
     Database db;

    Student adam{
        "Adam",
        "Bwulski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "00110103033",
        Gender::Male 
        };
        Student maciek{
        "Maciek",
        "Asinski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "00110103031",
        Gender::Male 
        };

    db.add(adam);
    db.add(maciek);
    
    db.sortByPesel();
    auto content = db.show();
    auto expected = "Maciek Asinski; ul. Dobra 134, 00-200 Warszawa; 123456; 00110103031; Male\nAdam Bwulski; ul. Dobra 134, 00-200 Warszawa; 123456; 00110103033; Male\n";
    EXPECT_EQ(content,expected);

    
}
