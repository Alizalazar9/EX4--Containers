// alizalazar9@gmail.com
// This file has all the tests for the container and the different iterators we implemented.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/MyContainer.hpp"

using namespace mycontainers;

// Just checking that adding, removing, and printing works normally
TEST_CASE("Basic operations: add, remove, size, print") {
    MyContainer<int> c;

    CHECK(c.size() == 0); // Should be empty at the beginning

    // Add a few elements (some are duplicates)
    c.add(3);
    c.add(5);
    c.add(3);
    c.add(1);
    CHECK(c.size() == 4);

    // Remove 3 → should remove both
    c.remove(3);
    CHECK(c.size() == 2);

    // Try to remove something that doesn't exist → should throw
    CHECK_THROWS(c.remove(999));

    // Make sure printing shows the remaining values correctly
    std::ostringstream oss;
    oss << c;
    std::string printed = oss.str();
    CHECK((printed == "[5, 1]" || printed == "[1, 5]")); // Order might vary
}

// Test for ascending order (smallest to largest)
TEST_CASE("AscendingOrderIterator returns sorted elements") {
    MyContainer<int> c;
    c.add(5); c.add(2); c.add(8); c.add(1);

    std::vector<int> expected = {1, 2, 5, 8}; // Sorted manually
    std::vector<int> actual;
    for (auto it = c.begin_ascending_order(); it != c.end_ascending_order(); ++it) {
        actual.push_back(*it);
    }

    CHECK(actual == expected);
}

// Test for descending order (largest to smallest)
TEST_CASE("DescendingOrderIterator returns reverse sorted elements") {
    MyContainer<int> c;
    c.add(3); c.add(7); c.add(1);

    std::vector<int> expected = {7, 3, 1};
    std::vector<int> actual;
    for (auto it = c.begin_descending_order(); it != c.end_descending_order(); ++it) {
        actual.push_back(*it);
    }

    CHECK(actual == expected);
}

// This one does the small-big pattern: smallest, largest, 2nd smallest, etc.
TEST_CASE("SideCrossOrderIterator alternates small-big") {
    MyContainer<int> c;
    c.add(1); c.add(2); c.add(3); c.add(4); c.add(5);

    std::vector<int> expected = {1, 5, 2, 4, 3};
    std::vector<int> actual;
    for (auto it = c.begin_side_cross_order(); it != c.end_side_cross_order(); ++it) {
        actual.push_back(*it);
    }

    CHECK(actual == expected);
}

// Reverse the order the values were added in (insertion order)
TEST_CASE("ReverseOrderIterator returns elements in reverse of insertion order") {
    MyContainer<int> c;
    c.add(10); c.add(20); c.add(30); // Will be reversed

    std::vector<int> expected = {30, 20, 10};
    std::vector<int> actual;
    for (auto it = c.begin_reverse_order(); it != c.end_reverse_order(); ++it) {
        actual.push_back(*it);
    }

    CHECK(actual == expected);
}

// Just returns the values in the order they were added
TEST_CASE("OrderIterator returns elements in insertion order") {
    MyContainer<int> c;
    c.add(5); c.add(10); c.add(15);

    std::vector<int> expected = {5, 10, 15};
    std::vector<int> actual;
    for (auto it = c.begin_order(); it != c.end_order(); ++it) {
        actual.push_back(*it);
    }

    CHECK(actual == expected);
}

// This one starts from the middle and goes outwards (middle-out)
TEST_CASE("MiddleOutOrderIterator starts from middle") {
    MyContainer<int> c;
    c.add(1); c.add(2); c.add(3); c.add(4); c.add(5); // Sorted would be 1..5

    std::vector<int> expected = {3, 4, 2, 5, 1};
    std::vector<int> actual;
    for (auto it = c.begin_middle_out_order(); it != c.end_middle_out_order(); ++it) {
        actual.push_back(*it);
    }

    CHECK(actual == expected);
}

// Try edge cases: empty and single-element container
TEST_CASE("Edge cases: empty container and single element") {
    MyContainer<int> empty;
    CHECK(empty.size() == 0);

    // Should not run at all; if it does — FAIL
    for (auto it = empty.begin_order(); it != empty.end_order(); ++it) {
        FAIL("Empty container should not iterate");
    }

    // Single value → should give that one value
    MyContainer<int> single;
    single.add(42);

    int count = 0;
    for (auto it = single.begin_order(); it != single.end_order(); ++it) {
        CHECK(*it == 42);
        ++count;
    }
    CHECK(count == 1);
}
