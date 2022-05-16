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
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 00110103033; Male";
    EXPECT_EQ(content,expected);

}

