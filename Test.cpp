#include "Notebook.hpp"
#include <iostream>
#include "doctest.h"
#include <string>
using namespace std;
using namespace ariel;

TEST_CASE("Notebook Horizontal - Same Row and Same Column"){
    Notebook test;
    //test for the same row and same column at the first page
    test.write(1, 0, 0, Direction::Horizontal, "Hi");
    test.write(1, 1, 1, Direction::Horizontal, "Im");
    test.write(1, 2, 2, Direction::Horizontal, "A");
    test.write(1, 3, 3, Direction::Horizontal, "Computer");
    test.write(1, 4, 4, Direction::Horizontal, "Science");
    test.write(1, 5, 5, Direction::Horizontal, "And");
    test.write(1, 6, 6, Direction::Horizontal, "Mathmatics");
    test.write(1, 7, 7, Direction::Horizontal, "Student");
    test.write(1, 8, 8, Direction::Horizontal, "At");
    test.write(1, 9, 9, Direction::Horizontal, "Ariel");
    test.write(1, 10, 10, Direction::Horizontal, "University");
    //To erase from page 1, row 10, column 10 the word university and replace it with ~
    test.erase(1, 10, 10, Direction::Horizontal, 10);

    CHECK(test.read(1, 0, 0, Direction::Horizontal, 2)== "Hi");
    CHECK(test.read(1, 1, 1, Direction::Horizontal, 2)== "Im");
    CHECK(test.read(1, 2, 2, Direction::Horizontal, 1)== "A");
    CHECK(test.read(1, 3, 3, Direction::Horizontal, 8)== "Computer");
    CHECK(test.read(1, 4, 4, Direction::Horizontal, 7)== "Science");
    CHECK(test.read(1, 5, 5, Direction::Horizontal, 3)== "And");
    CHECK(test.read(1, 6, 6, Direction::Horizontal, 10)== "Mathmatics");
    CHECK(test.read(1, 7, 7, Direction::Horizontal, 7)== "Student");
    CHECK(test.read(1, 8, 8, Direction::Horizontal, 2)== "At");
    CHECK(test.read(1, 9, 9, Direction::Horizontal, 5)== "Ariel");
    CHECK(test.read(1, 10, 10, Direction::Horizontal, 1)== "~");
}

TEST_CASE("Notebook Vertical - Same Row and Same Column"){
    Notebook test;
    //test for the same row and same column at the first page
    test.write(1, 0, 0, Direction::Vertical, "Hi");
    test.write(1, 1, 1, Direction::Vertical, "Im");
    test.write(1, 2, 2, Direction::Vertical, "A");
    test.write(1, 3, 3, Direction::Vertical, "Computer");
    test.write(1, 4, 4, Direction::Vertical, "Science");
    test.write(1, 5, 5, Direction::Vertical, "And");
    test.write(1, 6, 6, Direction::Vertical, "Mathmatics");
    test.write(1, 7, 7, Direction::Vertical, "Student");
    test.write(1, 8, 8, Direction::Vertical, "At");
    test.write(1, 9, 9, Direction::Vertical, "Ariel");
    test.write(1, 10, 10, Direction::Vertical, "University");
    //To erase from page 1, row 10, column 10 the word university and replace it with ~
    test.erase(1, 10, 10, Direction::Vertical, 10);

    CHECK(test.read(1, 0, 0, Direction::Vertical, 2)== "Hi");
    CHECK(test.read(1, 1, 1, Direction::Vertical, 2)== "Im");
    CHECK(test.read(1, 2, 2, Direction::Vertical, 1)== "A");
    CHECK(test.read(1, 3, 3, Direction::Vertical, 8)== "Computer");
    CHECK(test.read(1, 4, 4, Direction::Vertical, 7)== "Science");
    CHECK(test.read(1, 5, 5, Direction::Vertical, 3)== "And");
    CHECK(test.read(1, 6, 6, Direction::Vertical, 10)== "Mathmatics");
    CHECK(test.read(1, 7, 7, Direction::Vertical, 7)== "Student");
    CHECK(test.read(1, 8, 8, Direction::Vertical, 2)== "At");
    CHECK(test.read(1, 9, 9, Direction::Vertical, 5)== "Ariel");
    CHECK(test.read(1, 10, 10, Direction::Vertical, 10)== "~");
}

TEST_CASE("Notebook Horizontal- To erase"){
    Notebook test;
    // 1.Horizontal Direction- to erase a completly wroten word from a correct row,column,page
    // 2.Horizontal Direction- to erase a wroten word but not all the letters from a correct row,column,page
    // 3.Horizontal Direction- Try to erase wroten word from incorrect page, but a correct row and column
    // 4.Horizontal Direction- Try to erase wroten word from incorrect row, but a correct page and column
    // 5.Horizontal Direction- Try to erase wroten word from incorrect column, but a correct page and row
    // 6.Horizontal Direction- Try to erase wroten word from incorrect page and row but a correct column
    // 7.Horizontal Direction- Try to erase wroten word from incorrect page and column, but a correct row
    // 8.Horizontal Direction- Try to erase wroten word from incorrect row and column, but a correct page
    // 9.Horizontal Direction- Try to erase wroten word from incorrect page and row and column
    // 10.Horizontal Direction- Try to erase incorrect word 
    // 11.Horizontal Direction- Try to erase empty! (there isn't word in this column and row)
    // 12.Horizontal Direction- Try to erase from row>100

    test.write(2, 5, 7, Direction::Horizontal, "CPP");
    test.erase(2, 5, 7, Direction::Horizontal, 3); //1
    CHECK(test.read(2, 5, 7, Direction::Horizontal, 3)== "~"); //1
    
    test.write(2, 5, 8, Direction::Horizontal, "Course");
    test.erase(2, 5, 8, Direction::Horizontal, 5); //2
    CHECK(test.read(2, 5, 8, Direction::Horizontal, 5)== "~e"); 

    test.write(4, 6, 1, Direction::Horizontal, "Software");
    test.erase(5, 6, 1, Direction::Horizontal, 8); //3
    CHECK_THROWS(test.erase(5, 6, 1, Direction::Horizontal, 8));//3 

    test.write(4, 6, 2, Direction::Horizontal, "Engineering");
    test.erase(4, 7, 2, Direction::Horizontal, 11); //4
    CHECK_THROWS(test.erase(4, 7, 2, Direction::Horizontal, 11));

    test.write(4, 6, 3, Direction::Horizontal, "Student");
    test.erase(4, 6, 8, Direction::Horizontal, 7);//5
    CHECK_THROWS(test.erase(4, 6, 8, Direction::Horizontal, 7));

    test.write(4, 6, 4, Direction::Horizontal, "At");
    test.erase(5, 7, 4, Direction::Horizontal, 2); //6
    CHECK_THROWS(test.erase(5, 7, 4, Direction::Horizontal, 2));

    test.write(4, 6, 5, Direction::Horizontal, "Ariel");
    test.erase(5, 6, 6, Direction::Horizontal, 5); //7
    CHECK_THROWS(test.erase(5, 6, 6, Direction::Horizontal, 5));

    test.write(4, 6, 6, Direction::Horizontal, "University");
    test.erase(4, 7, 7, Direction::Horizontal, 10); //8
    CHECK_THROWS(test.erase(4, 7, 7, Direction::Horizontal, 10));

    test.write(4, 6, 7, Direction::Horizontal, "!!!");
    test.erase(4, 7, 8, Direction::Horizontal, 3); //9
    CHECK_THROWS(test.erase(4, 7, 8, Direction::Horizontal, 3));

    test.write(4, 6, 9, Direction::Horizontal, "Finally");
    test.erase(4, 6, 9, Direction::Horizontal, 7); //10
    CHECK_THROWS(test.erase(4, 6, 9, Direction::Horizontal, 9));

    test.write(4, 6, 20, Direction::Horizontal, "_");
    test.erase(4, 6, 20, Direction::Horizontal, 8); //11
    CHECK_THROWS(test.erase(4, 6, 20, Direction::Horizontal, 8));

    test.write(4, 100, 7, Direction::Horizontal, "OK");
    test.erase(4, 102, 7, Direction::Horizontal, 2);//12
    CHECK_THROWS(test.erase(4, 102, 7, Direction::Horizontal, 2));

}

TEST_CASE("Notebook Vertical- To erase"){
    Notebook test;
    // 1.Vertical Direction- to erase wroten word from a correct row,column,page
    // 2.Vertical Direction- to erase wroten word from a correct row,column,page
    // 3.Vertical Direction- Try to erase wroten word from incorrect page, but a correct row and column
    // 4.Vertical Direction- Try to erase wroten word from incorrect row, but a correct page and column
    // 5.Vertical Direction- Try to erase wroten word from incorrect column, but a correct page and row
    // 6.Vertical Direction- Try to erase wroten word from incorrect page and row but a correct column
    // 7.Vertical Direction- Try to erase wroten word from incorrect page and column, but a correct row
    // 8.Vertical Direction- Try to erase wroten word from incorrect row and column, but a correct page
    // 9.Vertical Direction- Try to erase wroten word from incorrect page and row and column
    // 10.Vertical Direction- Try to erase incorrect word 
    // 11.Vertical Direction- Try to erase empty! (there isn't word in this column and row)
    // 12.Vertical Direction- Try to erase from row>100

    test.write(2, 5, 7, Direction::Vertical, "CPP");
    test.erase(2, 5, 7, Direction::Vertical, 3); //1
    CHECK(test.read(2, 5, 7, Direction::Vertical, 3)== "~"); //1
    
    test.write(2, 5, 8, Direction::Vertical, "Course");
    test.erase(2, 5, 8, Direction::Vertical, 5); //2
    CHECK(test.read(2, 5, 8, Direction::Vertical, 5)== "~e"); 

    test.write(4, 6, 1, Direction::Vertical, "Software");
    test.erase(5, 6, 1, Direction::Vertical, 8); //3
    CHECK_THROWS(test.erase(5, 6, 1, Direction::Vertical, 8));//3 

    test.write(4, 6, 2, Direction::Vertical, "Engineering");
    test.erase(4, 7, 2, Direction::Vertical, 11); //4
    CHECK_THROWS(test.erase(4, 7, 2, Direction::Vertical, 11));

    test.write(4, 6, 3, Direction::Vertical, "Student");
    test.erase(4, 6, 8, Direction::Vertical, 7);//5
    CHECK_THROWS(test.erase(4, 6, 8, Direction::Vertical, 7));

    test.write(4, 6, 4, Direction::Vertical, "At");
    test.erase(5, 7, 4, Direction::Vertical, 2); //6
    CHECK_THROWS(test.erase(5, 7, 4, Direction::Vertical, 2));

    test.write(4, 6, 5, Direction::Vertical, "Ariel");
    test.erase(5, 6, 6, Direction::Vertical, 5); //7
    CHECK_THROWS(test.erase(5, 6, 6, Direction::Vertical, 5));

    test.write(4, 6, 6, Direction::Vertical, "University");
    test.erase(4, 7, 7, Direction::Vertical, 10); //8
    CHECK_THROWS(test.erase(4, 7, 7, Direction::Vertical, 10));

    test.write(4, 6, 7, Direction::Vertical, "!!!");
    test.erase(4, 7, 8, Direction::Vertical, 3); //9
    CHECK_THROWS(test.erase(4, 7, 8, Direction::Vertical, 3));

    test.write(4, 6, 9, Direction::Vertical, "Finally");
    test.erase(4, 6, 9, Direction::Vertical, 7); //10
    CHECK_THROWS(test.erase(4, 6, 9, Direction::Vertical, 9));

    test.write(4, 6, 20, Direction::Horizontal, "_");
    test.erase(4, 6, 20, Direction::Vertical, 8); //11
    CHECK_THROWS(test.erase(4, 6, 20, Direction::Vertical, 8));

    test.write(4, 100, 7, Direction::Vertical, "OK");
    test.erase(4, 102, 7, Direction::Vertical, 2);//12
    CHECK_THROWS(test.erase(4, 102, 7, Direction::Vertical, 2));

}

TEST_CASE("Notebook Horizontal And Vertical -Some More Errors!"){
    Notebook test;
    //1. Horizontal Direction: Try to add a word when we have already written in it
    //2. Horizontal Direction: Try to add a word when we have already deleted it and there's ~ 
    //3. Horizontal Direction: Try to add a word in row > 100
    //4. Horizontal Direction: Try to read a word in row > 100
    //5. Horizontal Direction: Try to erase a word in row > 100
    //6. Vertical Direction: Try to add a word when we have already written in it
    //7. Vertical Direction: Try to add a word when we have already deleted it and there's ~ 
    //8. Vertical Direction: Try to add a word in row > 100
    //9. Vertical Direction: Try to read a word in row > 100
    //10. Vertical Direction: Try to erase a word in row > 100

    test.write(2, 5, 7, Direction::Horizontal, "CPP");
    CHECK_THROWS(test.write(2, 5, 7, Direction::Horizontal, "TT")); //1

    test.write(9, 0, 3, Direction::Horizontal, "OOP");
    test.erase(9, 0, 3, Direction::Horizontal, 3);
    CHECK_THROWS(test.write(9, 0, 3, Direction::Horizontal, "OC")); //2

    CHECK_THROWS(test.write(4, 105, 5, Direction::Horizontal, "vv"));//3
    CHECK_THROWS(test.read(4, 105, 8, Direction::Horizontal, 2)); //4
    CHECK_THROWS(test.erase(6, 105, 7, Direction::Horizontal, 9)); //5

    test.write(3, 6, 7, Direction::Vertical, "C++");
    CHECK_THROWS(test.write(3, 6, 7, Direction::Vertical, "AUDI")); //6

    test.write(8, 0, 3, Direction::Vertical, "RT");
    test.erase(8, 0, 3, Direction::Vertical, 3);
    CHECK_THROWS(test.write(8, 0, 3, Direction::Vertical, "OO")); //7

    CHECK_THROWS(test.write(8, 105, 5, Direction::Vertical, "CC"));//8
    CHECK_THROWS(test.read(9, 105, 8, Direction::Vertical, 12)); //9
    CHECK_THROWS(test.erase(10, 105, 7, Direction::Vertical, 11)); //10

}



