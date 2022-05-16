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

    db.add(adam);
    // check adding the same person twice

    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 00110103033; Male\n";
    EXPECT_EQ(content,expected);

}

TEST(FindLastName, SerchLastName)
{
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
        "Maciek",
        "Maruda",
        "ul. cos 134, 00-200 Krakow",
        234567,
        "2313331233",
        Gender::Male 
        };

    db.add(adam);
    db.add(maciek);

    
    auto content = db.findLastName("Maruda");
    auto expected = "Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 2313331233; Male\n";
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

TEST(FindLastName, SerchLastNameWhenNoone){

    Database db;

    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "00110103033",
        Gender::Male 
        };

    db.add(adam);
    // check adding the same person twice

    auto content = db.findLastName("Maruda");
    auto expected = "";
    EXPECT_EQ(content,expected);

}