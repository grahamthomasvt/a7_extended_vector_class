#include "catch2/catch.hpp"
#include "array/vector.hpp"

TEST_CASE("copy assignment", "[copy][assignment]") {
    dsac::array::Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    dsac::array::Vector<int> v2;
    v2 = v;
    REQUIRE(v.at(1) == v2.at(1));
}

TEST_CASE("copy constructor", "[copy][constructor") {
    dsac::array::Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    auto v2 = v;
    REQUIRE(v.at(1) == v2.at(1));
}

TEST_CASE("move assignment", "[move][assignment]") {
    dsac::array::Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    dsac::array::Vector<int> v2;
    v2 = std::move(v);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v2.at(1) == 2);
}

TEST_CASE("move constructor", "[move][constructor") {
    dsac::array::Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    auto v2 = std::move(v);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v2.at(1) == 2);
}

TEST_CASE("iterator constructor", "[iterator][constructor]") {
    dsac::array::Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    dsac::array::Vector<int>::iterator iter = v.begin();
    REQUIRE(*iter == 1);
}

TEST_CASE("iterator increment", "[iterator][increment]") {
    dsac::array::Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    dsac::array::Vector<int>::iterator iter = v.begin();
    ++iter;
    REQUIRE(*iter == 2);
}

TEST_CASE("iterator decrement", "[iterator][decrement]") {
    dsac::array::Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    dsac::array::Vector<int>::iterator iter = v.end();
    --iter;
    REQUIRE(*iter == 3);
}

TEST_CASE("iterator insert", "[iterator][insert]") {
    dsac::array::Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    dsac::array::Vector<int>::iterator iter = v.begin();
    ++iter;
    v.dsac::array::Vector<int>::insert(iter, 33);
    REQUIRE(*iter == 33);
    REQUIRE(*(++iter) == 2);
}

TEST_CASE("iterator erase", "[iterator][erase]") {
    dsac::array::Vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    dsac::array::Vector<int>::iterator iter = v.begin();
    ++iter;
    v.dsac::array::Vector<int>::insert(iter, 33);
    v.dsac::array::Vector<int>::erase(iter);
    REQUIRE(*iter == 2);
    REQUIRE(*(++iter) == 3);
}
