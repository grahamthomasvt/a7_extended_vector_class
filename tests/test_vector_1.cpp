#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "array/vector.hpp"

TEST_CASE("empty", "[empty]") {
    dsac::array::Vector<int> v;
    v.push_back(12); v.push_back(15);
    v.pop_back(); v.pop_back();
    REQUIRE(v.empty());
}

TEST_CASE("size", "[size]") {
    dsac::array::Vector<int> v;
    v.push_back(12); v.push_back(15); v.push_back(22);
    v.pop_back(); v.pop_back();
    REQUIRE(v.size() == 1);
}

TEST_CASE("capacity", "[capacity]") {
    dsac::array::Vector<int> v;
    v.push_back(12); v.push_back(15); v.push_back(22); v.push_back(24);
    v.push_back(42); v.push_back(45); v.push_back(62); v.push_back(62);
    v.pop_back(); v.pop_back();
    REQUIRE(v.capacity() == 8);
}

TEST_CASE("bracket", "[bracket]") {
    dsac::array::Vector<int> v;
    v.push_back(12); v.push_back(15); v.push_back(22); v.push_back(24);
    v.push_back(42); v.push_back(45); v.push_back(62); v.push_back(62);
    v.pop_back(); v.pop_back();
    REQUIRE(v[3] == 24);
}

TEST_CASE("at", "[at]") {
    dsac::array::Vector<int> v;
    v.push_back(12); v.push_back(15); v.push_back(22); v.push_back(24);
    v.push_back(42); v.push_back(45); v.push_back(62); v.push_back(62);
    v.pop_back(); v.pop_back();
    REQUIRE(v.at(3) == 24);
}

TEST_CASE("shrink", "[shrink]") {
    dsac::array::Vector<int> v;
    v.push_back(12); v.push_back(15); v.push_back(22); v.push_back(24);
    v.push_back(42); v.push_back(45); v.push_back(62); v.push_back(62);
    v.pop_back(); v.pop_back(); v.pop_back(); v.pop_back(); v.pop_back(); v.pop_back();
    REQUIRE(v.capacity() == 4);
}

TEST_CASE("reallocate", "[reallocate]") {
    dsac::array::Vector<int> v;
    v.push_back(12); v.push_back(15); v.push_back(22); v.push_back(24);
    v.push_back(42); v.push_back(45); v.push_back(62); v.push_back(62);
    v.pop_back(); v.pop_back();
    v.reallocate(6);
    REQUIRE(v.capacity() == 6);
}

TEST_CASE("shrink to fit", "[shrink_to_fit]") {
    dsac::array::Vector<int> v;
    v.push_back(12); v.push_back(15); v.push_back(22); v.push_back(24);
    v.push_back(42); v.push_back(45); v.push_back(62); v.push_back(62);
    v.pop_back(); v.pop_back(); v.pop_back();
    v.shrink_to_fit();
    REQUIRE(v.capacity() == 5);
}
