// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>


using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.
TEST_CASE("Push Back", "[constructor][push_back][size][empty][front][back]") {
    LinkedList<int> list;

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());

    SECTION("Push back one element") {
        list.push_back(1);
        REQUIRE(list.size() == 1);
        REQUIRE(list.front() == 1);
    }

    SECTION("Push back two elements") {
        list.push_back(-1);
        list.push_back(10000);
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == -1);
        REQUIRE(list.back() == 10000);
    }
}

TEST_CASE("Push Front", "[constructor][push_front][size][empty][front][back]") {
    LinkedList<int> list;

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());

    SECTION("Push front one element") {
        list.push_front(1);
        REQUIRE(list.size() == 1);
        REQUIRE(list.front() == 1);
    }

    SECTION("Push front two elements") {
        list.push_front(-1);
        list.push_front(10000);
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 10000);
        REQUIRE(list.back() == -1);
    }
}

TEST_CASE("Pop Front", "[constructor][pop_front][size][empty][front][back][push_back]") {
    LinkedList<int> list;

    SECTION("Empty list") {
        list.pop_front();
        REQUIRE(list.size() == 0);
    }

    SECTION("Deletes element of list size 1") {
        list.push_back(3);
        REQUIRE(list.size() == 1);

        list.pop_front();
        REQUIRE(list.size() == 0);
    }

    SECTION("Deletes element of list size 2") {
        list.push_back(3);
        list.push_back(99);
        REQUIRE(list.size() == 2);

        list.pop_front();
        REQUIRE(list.size() == 1);
        REQUIRE(list.front() == 99);
    }

    SECTION("Deletes element of list size 3") {
        list.push_back(99);
        list.push_back(4);
        list.push_back(100);
        REQUIRE(list.size() == 3);

        list.pop_front();
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 4);
        REQUIRE(list.back() == 100);
    }
}

TEST_CASE("Pop Back", "[constructor][pop_back][size][empty][front][back][push_back]") {
    LinkedList<int> list;

    SECTION("Empty list") {
        list.pop_back();
        REQUIRE(list.size() == 0);
    }

    SECTION("Deletes element of list size 1") {
        list.push_back(3);
        REQUIRE(list.size() == 1);

        list.pop_back();
        REQUIRE(list.size() == 0);
    }

    SECTION("Deletes element of list size 2") {
        list.push_back(3);
        list.push_back(99);
        REQUIRE(list.size() == 2);

        list.pop_back();
        REQUIRE(list.size() == 1);
        REQUIRE(list.front() == 3);
    }

    SECTION("Deletes element of list size 3") {
        list.push_back(99);
        list.push_back(4);
        list.push_back(100);
        REQUIRE(list.size() == 3);

        list.pop_back();
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 99);
        REQUIRE(list.back() == 4);
    }
}

TEST_CASE("Clear") {
    LinkedList<int> list;

    SECTION("Tests empty list")  {
        list.clear();

        REQUIRE(list.size() == 0);
    }

    SECTION("Tests non-empty list") {
        list.push_back(99);
        list.push_back(4);
        list.push_back(100);

        list.clear();
        REQUIRE(list.size() == 0);
    }

}


// TODO(you): Add more tests below.
