#include <gtest/gtest.h>
#include "database.hpp"
#include "record.hpp"
#include "PESELvalidation.hpp"

struct DatabaseTest: ::testing::Test
{
    Database db;
    Student Adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        "99110103633",
        Gender::Male,
        "123456"
        };
    Student Maciek{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        "99110103633",
        Gender::Male,
        "123456"
        };
    Student Kacper{
        "Adam",
        "Maruda",
        "ul. Dobra 134, 00-200 Warszawa",
        "99110103633",
        Gender::Male,
        "123456"
    };
    Student Krzysiek{
        "Maciek",
        "Maruda",
        "ul. cos 134, 00-200 Krakow",
        "1111111111",
        Gender::Male,
        "234567"  
    };
    Student Kasia{
        "Kasia",
        "Markowska",
        "ul. Dobra 134, 00-200 Warszawa",
        "01010101011",
        Gender::Female,
        "123456"
        };
};

TEST_F(DatabaseTest, DisplayEmptyDB){

    
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content,expected);


 }

TEST_F(DatabaseTest, DisplayNonEmptyDB){

    db.add(Adam);
    db.add(Maciek);
    // check adding the same person twice
    
    auto content = db.show();
    auto expected = "Student: Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nStudent: Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\n";
    EXPECT_EQ(content,expected);

}

TEST_F(DatabaseTest, SerchLastNameWhenIsMoreThan1)
{
    db.add(Adam);
    db.add(Kacper);
    db.add(Krzysiek);

    
    auto content = db.findLastName("Maruda");
    auto expected = "Student: Adam Maruda; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nStudent: Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 1111111111; Male\n";
    EXPECT_EQ(content,expected);
}

TEST_F(DatabaseTest, SerchForPesel)
{

    db.add(Adam);
    db.add(Maciek);
    db.add(Krzysiek);

    auto content = db.findPesel("1111111111");
    auto expected = "Student: Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 1111111111; Male\n";
    EXPECT_EQ(content,expected);
}

TEST_F(DatabaseTest, SortByLastName)
{
    db.add(Maciek);
    db.add(Krzysiek);
    // check adding the same person twice
    db.sortBySurname();
    auto content = db.show();
    auto expected = "Student: Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nStudent: Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 1111111111; Male\n";
    EXPECT_EQ(content,expected);   
}

TEST_F(DatabaseTest, SortByPesel)
{
    db.add(Kacper);
    db.add(Krzysiek);
    
    db.sortByPesel();
    auto content = db.show();
    auto expected = "Student: Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 1111111111; Male\nStudent: Adam Maruda; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\n";
    EXPECT_EQ(content,expected);

 }

TEST_F(DatabaseTest, DeleteStudentByIndexNumber)
{
     
    db.add(Krzysiek);
    db.add(Adam);
    
    db.deleteByIndexNumber("234567");
    auto content = db.show();
    auto expected = "Student: Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\n";
    EXPECT_EQ(content,expected);
    
}

TEST_F(DatabaseTest, ShowingProperlyGender)
{
    db.add(Kasia);

    auto content = db.show();
    auto expected = "Student: Kasia Markowska; ul. Dobra 134, 00-200 Warszawa; 123456; 01010101011; Female\n";
    EXPECT_EQ(content,expected);
 
}

TEST_F(DatabaseTest, validatePeselSize)
{
    PESELvalidation pesel1;

    EXPECT_TRUE(pesel1.validatePESEL("99110103633"));
    EXPECT_FALSE(pesel1.validatePESEL("1234"));

}

