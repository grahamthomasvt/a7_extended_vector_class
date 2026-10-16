#include "catch2/catch.hpp"
#include "array/matrix.hpp"

TEST_CASE("Matrix construction", "[matrix][empty]") {
    dsac::array::Matrix temp = dsac::array::Matrix(2, 3);
    REQUIRE(temp(1, 1) == 0);
}

TEST_CASE("Matrix access", "[matrix][access]") {
    dsac::array::Matrix temp = dsac::array::Matrix(3, 4);
    temp(2, 2) = 3;
    REQUIRE(temp(2, 2) == 3);
}

TEST_CASE("Matrix addition", "[matrix][addition]") {
    dsac::array::Matrix temp1 = dsac::array::Matrix(3, 4);
    temp1(0, 0) = 3; temp1(1, 0) = 1; temp1(2, 0) = 32;
    temp1(0, 1) = 1; temp1(1, 1) = 2; temp1(2, 1) = 3;
    temp1(0, 2) = 2; temp1(1, 2) = 1; temp1(2, 2) = 2;
    temp1(0, 3) = 1; temp1(1, 3) = 2; temp1(2, 3) = 3;
    
    dsac::array::Matrix temp2 = dsac::array::Matrix(3, 4);
    temp2(0, 0) = 1; temp2(1, 0) = 3; temp2(2, 0) = 32;
    temp2(0, 1) = 3; temp2(1, 1) = 2; temp2(2, 1) = 1;
    temp2(0, 2) = 2; temp2(1, 2) = 3; temp2(2, 2) = 2;
    temp2(0, 3) = 3; temp2(1, 3) = 2; temp2(2, 3) = 1;
    
    auto temp3 = temp1 + temp2;
    
    REQUIRE(temp3(1, 1) == 4);
}
