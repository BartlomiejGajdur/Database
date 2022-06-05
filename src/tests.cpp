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
    Employee P_antek{
        "Antek",
        "Antkowski",
        "Makowa 15",
        "9911929292",
        Gender::Male,
        2500
    };
    Employee P_marcelina{
        "Marcelina",
        "Tynska",
        "Basztowa 15",
        "2032323232",
        Gender::Female,
        7000
    };
};

TEST_F(DatabaseTest, DisplayEmptyDB){

    
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content,expected);


 }

TEST_F(DatabaseTest, DisplayNonEmptyDB){

    db.add(std::make_shared<Student>(Adam));
    db.add(std::make_shared<Student>(Maciek));
    // check adding the same person twice
    
    auto content = db.show();
    auto expected = "Student: Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nStudent: Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\n";
    EXPECT_EQ(content,expected);

}

TEST_F(DatabaseTest, SerchLastNameWhenIsMoreThan1)
{
    db.add(std::make_shared<Student>(Adam));
    db.add(std::make_shared<Student>(Kacper));
    db.add(std::make_shared<Student>(Krzysiek));

    
    auto content = db.findLastName("Maruda");
    auto expected = "Student: Adam Maruda; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nStudent: Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 1111111111; Male\n";
    EXPECT_EQ(content,expected);
}

TEST_F(DatabaseTest, SerchForPesel)
{

    db.add(std::make_shared<Student>(Adam));
    db.add(std::make_shared<Student>(Maciek));
    db.add(std::make_shared<Student>(Krzysiek));

    auto content = db.findPesel("1111111111");
    auto expected = "Student: Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 1111111111; Male\n";
    EXPECT_EQ(content,expected);
}

TEST_F(DatabaseTest, SortByLastName)
{
    db.add(std::make_shared<Student>(Maciek));
    db.add(std::make_shared<Student>(Krzysiek));
    // check adding the same person twice
    db.sortBySurname();
    auto content = db.show();
    auto expected = "Student: Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nStudent: Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 1111111111; Male\n";
    EXPECT_EQ(content,expected);   
}

TEST_F(DatabaseTest, SortByPesel)
{
    db.add(std::make_shared<Student>(Kacper));
    db.add(std::make_shared<Student>(Krzysiek));
    
    db.sortByPesel();
    auto content = db.show();
    auto expected = "Student: Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 1111111111; Male\nStudent: Adam Maruda; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\n";
    EXPECT_EQ(content,expected);

 }

// TEST_F(DatabaseTest, DeleteStudentByIndexNumber)
// {
     
//     db.add(std::make_shared<Student>(Krzysiek));
//     db.add(std::make_shared<Student>(Adam));
    
//     db.deleteByIndexNumber("234567");
//     auto content = db.show();
//     auto expected = "Student: Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\n";
//     EXPECT_EQ(content,expected);
    
// }

TEST_F(DatabaseTest, ShowingProperlyGender)
{
    db.add(std::make_shared<Student>(Kasia));

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

TEST_F(DatabaseTest, Employeeds)
{
    db.add(std::make_shared<Employee>(P_marcelina));
    auto content = db.show();
    auto expected = "Employee: Marcelina Tynska; Basztowa 15; 7000zl ; 2032323232; Female\n";
    EXPECT_EQ(content,expected);
    
}
