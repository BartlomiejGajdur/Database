// #include <gtest/gtest.h>
// #include "database.hpp"
// #include "record.hpp"
// #include "PESELvalidation.hpp"

// TEST(DisplayDb, DisplayEmptyDB){

//     Database db;
//     auto content = db.show();
//     auto expected = "";
//     EXPECT_EQ(content,expected);


// }

// TEST(DisplayDb, DisplayNonEmptyDB){

//     Database db;

//     Student adam{
//         "Adam",
//         "Kowalski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "99110103633",
//         Gender::Male 
//         };
//         Student maciek{
//         "Adam",
//         "Kowalski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "99110103633",
//         Gender::Male 
//         };

//     db.add(adam);
//     db.add(maciek);
//     // check adding the same person twice

//     auto content = db.show();
//     auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nAdam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\n";
//     EXPECT_EQ(content,expected);

// }

// TEST(FindLastName, SerchLastNameWhenIsMoreThan1)
// {
//     Database db;
//     Student adam{
//         "Adam",
//         "Maruda",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "99110103633",
//         Gender::Male 
//         };
//     Student maciek{
//         "Maciek",
//         "Maruda",
//         "ul. cos 134, 00-200 Krakow",
//         234567,
//         "99110103633",
//         Gender::Male 
//         };
//     Student Kacper{
//         "Kacper",
//         "Kacperski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "99110103633",
//         Gender::Male 
//         };

//     db.add(adam);
//     db.add(maciek);
//     db.add(Kacper);

    
//     auto content = db.findLastName("Maruda");
//     auto expected = "Adam Maruda; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nMaciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 99110103633; Male\n";
//     EXPECT_EQ(content,expected);
// }

// TEST(FindPesel, SerchForPesel)
// {
//      Database db;
//     Student adam{
//         "Adam",
//         "Maruda",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "11111111111",
//         Gender::Male 
//         };
//     Student maciek{
//         "Maciek",
//         "Maruda",
//         "ul. cos 134, 00-200 Krakow",
//         234567,
//         "99110103633",
//         Gender::Male 
//         };
//     Student Kacper{
//         "Kacper",
//         "Kacperski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "333333333333",
//         Gender::Male 
//         };

//     db.add(adam);
//     db.add(maciek);
//     db.add(Kacper);

//     auto content = db.findPesel("99110103633");
//     auto expected = "Maciek Maruda; ul. cos 134, 00-200 Krakow; 234567; 99110103633; Male\n";
//     EXPECT_EQ(content,expected);
// }

// TEST(SortLastName, SortByLastName)
// {
//      Database db;

//     Student adam{
//         "Adam",
//         "Bwulski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "99110103633",
//         Gender::Male 
//         };
//         Student maciek{
//         "Maciek",
//         "Asinski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "99110103633",
//         Gender::Male 
//         };

//     db.add(adam);
//     db.add(maciek);
//     // check adding the same person twice
//     db.sortBySurname();
//     auto content = db.show();
//     auto expected = "Maciek Asinski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nAdam Bwulski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\n";
//     EXPECT_EQ(content,expected);

    
// }

// TEST(SortPesel, SortByPesel)
// {
//      Database db;

//     Student adam{
//         "Adam",
//         "Bwulski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "99110103633",
//         Gender::Male 
//         };
//         Student maciek{
//         "Maciek",
//         "Asinski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "99110103633",
//         Gender::Male 
//         };

//     db.add(adam);
//     db.add(maciek);
    
//     db.sortByPesel();
//     auto content = db.show();
//     auto expected = "Adam Bwulski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\nMaciek Asinski; ul. Dobra 134, 00-200 Warszawa; 123456; 99110103633; Male\n";
//     EXPECT_EQ(content,expected);

    
// }

// TEST(Eraseing, DeleteStudentByIndexNumber)
// {
//      Database db;

//     Student adam{
//         "Adam",
//         "Bwulski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "01",
//         Gender::Male 
//         };
//         Student maciek{
//         "Maciek",
//         "Asinski",
//         "ul. Dobra 134, 00-200 Warszawa",
//         1234567,
//         "00110103031",
//         Gender::Male 
//         };

//     db.add(adam);
//     db.add(maciek);
    
//     db.deleteByIndexNumber(123456);
//     auto content = db.show();
//     auto expected = "Maciek Asinski; ul. Dobra 134, 00-200 Warszawa; 1234567; 00110103031; Male\n";
//     EXPECT_EQ(content,expected);

    
// }

// TEST(Gender, ShowingProperlyGender)
// {
//      Database db;

//     Student Kasia{
//         "Kasia",
//         "Markowska",
//         "ul. Dobra 134, 00-200 Warszawa",
//         123456,
//         "01010101011",
//         Gender::Female 
//         };
        

//     db.add(Kasia);

//     auto content = db.show();
//     auto expected = "Kasia Markowska; ul. Dobra 134, 00-200 Warszawa; 123456; 01010101011; Female\n";
//     EXPECT_EQ(content,expected);

    
// }

// TEST(Pesel, validatePeselSize)
// {
//     PESELvalidation pesel1;

//     EXPECT_TRUE(pesel1.validatePESEL("99110103633"));
//     EXPECT_FALSE(pesel1.validatePESEL("1234"));

// }
