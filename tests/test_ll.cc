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

TEST_CASE("Empty", "[push_back][empty]") {
    LinkedList<int> list;

    SECTION("Empty list") {
        REQUIRE(list.empty() == true);
    }

    SECTION("Not empty list") {
        list.push_back(99);
        REQUIRE(list.empty() == false);
    }
}

TEST_CASE("Size") {
    LinkedList<int> list;

    SECTION("Empty list") {
        REQUIRE(list.size() == 0);
    }

    SECTION("Not empty list") {
        list.push_back(99);
        list.push_back(99);
        REQUIRE(list.size() == 2);
    }
}

TEST_CASE("Clear", "[clear][push_back][size]") {
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

TEST_CASE("Front and Back methods", "[front][back][push_back]") {
    LinkedList<int> list;

    SECTION("Tests empty list") {
        REQUIRE_THROWS_AS(list.front(), std::exception);
        REQUIRE_THROWS_AS(list.back(), std::exception);
    }
    SECTION("Tests front()") {
        list.push_back(99);
        list.push_back(100);

        REQUIRE(list.front() == 99);
    }

    SECTION("Tests back()") {
        list.push_back(99);
        list.push_back(100);

        REQUIRE(list.back() == 100);
    }
}

TEST_CASE("RemoveOdd", "[size][RemoveOdd][push_back][front][back]") {
    LinkedList<int> list;

    SECTION("Tests empty list") {
        list.RemoveOdd();
        REQUIRE(list.size() == 0);
    }

    SECTION("Tests size 1 list") {
        list.push_back(99);
        list.RemoveOdd();
        REQUIRE(list.size() == 1);
    }

    SECTION("Tests sized 2 list") {
        list.push_back(5);
        list.push_back(4);

        list.RemoveOdd();
        REQUIRE(list.size() == 1);
        REQUIRE(list.front() == 5);
    }

    SECTION("Tests odd sized list") {
        list.push_back(5);
        list.push_back(4);
        list.push_back(2);

        list.RemoveOdd();
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 5);
        REQUIRE(list.back() == 2);
    }

    SECTION("Tests even sized list") {
        list.push_back(6);
        list.push_back(4);
        list.push_back(55);
        list.push_back(99);

        list.RemoveOdd();
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 6);
        REQUIRE(list.back() == 55);
    }
}

TEST_CASE("Remove Nth method") {
    LinkedList<int> list;

    SECTION("Test empty list") {
        list.RemoveNth(4);
        REQUIRE(list.size() == 0);
    }

    SECTION("Tests list of size 1") {
        list.push_back(5);
        list.RemoveNth(1);
        REQUIRE(list.size() == 0);
    }

    SECTION("Tests invalid position passed into method", "[push_back][size][front][back][RemoveNth]") {
        list.push_back(5);
        list.push_back(5);
        list.push_back(5);

        list.RemoveNth(4);
        REQUIRE(list.size() == 3);
    }

    SECTION("Removes 1st position from list") {
        list.push_back(6);
        list.push_back(7);
        list.push_back(8);

        list.RemoveNth(1);
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 7);
        REQUIRE(list.back() == 8);
    }

    SECTION("Removes last position from list") {
        list.push_back(6);
        list.push_back(7);
        list.push_back(8);

        list.RemoveNth(3);
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 6);
        REQUIRE(list.back() == 7);
    }

    SECTION("Passes 0 into RemoveNth parameter") {
        list.push_back(6);
        list.push_back(7);
        list.push_back(8);

        list.RemoveNth(0);
        REQUIRE(list.size() == 3);
        REQUIRE(list.front() == 6);
        REQUIRE(list.back() == 8);
    }

    SECTION("Removes odd node from list") {
        list.push_back(6);
        list.push_back(7);
        list.push_back(8);
        list.push_back(9);
        list.push_back(10);

        list.RemoveNth(3);
        REQUIRE(list.size() == 4);
        REQUIRE(list.front() == 6);
        REQUIRE(list.back() == 10);
    }

    SECTION("Removes even node from list") {
        list.push_back(6);
        list.push_back(7);
        list.push_back(8);
        list.push_back(9);
        list.push_back(10);

        list.RemoveNth(4);
        REQUIRE(list.size() == 4);
        REQUIRE(list.front() == 6);
        REQUIRE(list.back() == 10);
    }
}

TEST_CASE("operator!=", "[push_back]") {
    LinkedList<int> *list = new LinkedList<int>();
    LinkedList<int> *list2 = new LinkedList<int>();

    SECTION("Test empty lists") {
         REQUIRE((*list != *list2) == false);
    }

    SECTION("Tests different size lists") {
        list->push_back(5);

        list2->push_back(5);
        list2->push_back(10);
        REQUIRE((*list != *list2));
    }

    SECTION("Tests same size lists with different values") {
        list->push_back(5);
        list->push_back(7);

        list2->push_back(5);
        list2->push_back(10);
        REQUIRE((*list != *list2));
    }

    SECTION("Tests same size lists with same values") {
        list->push_back(5);
        list->push_back(10);
        list->push_back(8);

        list2->push_back(5);
        list2->push_back(10);
        list2->push_back(8);
        REQUIRE(!(*list != *list2));
    }

    SECTION("Tests same string values") {
        LinkedList<std::string> *list3 = new LinkedList<std::string>();
        LinkedList<std::string> *list4 = new LinkedList<std::string>();

        list3->push_back("Hello");
        list3->push_back("World");

        list4->push_back("Hello");
        list4->push_back("World");

        REQUIRE(!(*list3 != *list4));
    }

    SECTION("Tests different string values") {
        LinkedList<std::string> *list3 = new LinkedList<std::string>();
        LinkedList<std::string> *list4 = new LinkedList<std::string>();

        list3->push_back("Hello");
        list3->push_back("World");

        list4->push_back("Bye");
        list4->push_back("World");

        REQUIRE(*list3 != *list4);
    }
}

TEST_CASE("operator==", "[push_back]") {
    LinkedList<int> *list = new LinkedList<int>();
    LinkedList<int> *list2 = new LinkedList<int>();

    SECTION("Test empty lists") {
        REQUIRE(*list == *list2);
    }

    SECTION("Tests different size lists") {
        list->push_back(5);

        list2->push_back(5);
        list2->push_back(10);
        REQUIRE(!(*list == *list2));
    }

    SECTION("Tests same size lists with different values") {
        list->push_back(5);
        list->push_back(7);

        list2->push_back(5);
        list2->push_back(10);
        REQUIRE(!(*list == *list2));
    }

    SECTION("Tests same size lists with same values") {
        list->push_back(5);
        list->push_back(10);
        list->push_back(8);

        list2->push_back(5);
        list2->push_back(10);
        list2->push_back(8);
        REQUIRE(*list == *list2);
    }

    SECTION("Tests same string values") {
        LinkedList<std::string> *list3 = new LinkedList<std::string>();
        LinkedList<std::string> *list4 = new LinkedList<std::string>();

        list3->push_back("Hello");
        list3->push_back("World");

        list4->push_back("Hello");
        list4->push_back("World");

        REQUIRE(*list3 == *list4);
    }

    SECTION("Tests different string values") {
        LinkedList<std::string> *list3 = new LinkedList<std::string>();
        LinkedList<std::string> *list4 = new LinkedList<std::string>();

        list3->push_back("Hello");
        list3->push_back("World");

        list4->push_back("Bye");
        list4->push_back("World");

        REQUIRE(!(*list3 == *list4));
    }
}



// TODO(you): Add more tests below.
