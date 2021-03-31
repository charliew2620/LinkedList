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

    SECTION("Deletes two element of list size 4") {
        list.push_back(99);
        list.push_back(4);
        list.push_back(100);
        list.push_back(15);
        REQUIRE(list.size() == 4);

        list.pop_front();
        list.pop_front();
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 100);
        REQUIRE(list.back() == 15);
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

    SECTION("Deletes 2 elements of list size 4") {
        list.push_back(99);
        list.push_back(4);
        list.push_back(100);
        list.push_back(18);
        REQUIRE(list.size() == 4);

        list.pop_back();
        list.pop_back();
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 99);
        REQUIRE(list.back() == 4);
    }
}

TEST_CASE("Empty", "[push_back][empty]") {
    LinkedList<int> list;

    SECTION("Empty list") {
        REQUIRE(list.empty());
    }

    SECTION("Not empty list") {
        list.push_back(99);
        REQUIRE_FALSE(list.empty());
    }
}

TEST_CASE("Size") {
    LinkedList<char> list;

    SECTION("Empty list") {
        REQUIRE(list.size() == 0);
    }

    SECTION("Not empty list") {
        list.push_back('1');
        list.push_back('r');
        REQUIRE(list.size() == 2);
    }
}

TEST_CASE("Clear", "[clear][push_back][size]") {
    LinkedList<int> list;

    SECTION("Tests empty list") {
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
        LinkedList<std::string> list2;
        list2.push_back("aa");
        list2.push_back("pain");
        list2.push_back("asdf");
        list2.push_back("cs126");

        list2.RemoveOdd();
        REQUIRE(list2.size() == 2);
        REQUIRE(list2.front() == "aa");
        REQUIRE(list2.back() == "asdf");
    }
}

TEST_CASE("Remove Nth method", "[push_back][size][front][back][RemoveNth]") {
    LinkedList<int> list;

    SECTION("Test empty list and pass n as 0") {
        list.RemoveNth(0);
        REQUIRE(list.size() == 0);
    }

    SECTION("Tests list of size 1") {
        list.push_back(5);
        list.RemoveNth(0);
        REQUIRE(list.size() == 0);
    }

    SECTION("Tests list of size 2") {
        list.push_back(5);
        list.push_back(2);
        list.RemoveNth(1);
        REQUIRE(list.size() == 1);
        REQUIRE(list.front() == 5);
    }

    SECTION("Tests too big of a position passed into method") {
        list.push_back(5);
        list.push_back(5);
        list.push_back(5);

        list.RemoveNth(3);
        REQUIRE(list.size() == 3);
    }

    SECTION("Removes 1st position from list") {
        list.push_back(6);
        list.push_back(7);
        list.push_back(8);

        list.RemoveNth(0);
        REQUIRE(list.size() == 2);
        REQUIRE(list.front() == 7);
        REQUIRE(list.back() == 8);
    }

    SECTION("Removes last position from list") {
        LinkedList<char> list2;
        list2.push_back('a');
        list2.push_back('b');
        list2.push_back('z');

        list2.RemoveNth(2);
        REQUIRE(list2.size() == 2);
        REQUIRE(list2.front() == 'a');
        REQUIRE(list2.back() == 'b');
    }

    SECTION("Passes negative number into RemoveNth parameter") {
        list.push_back(6);
        list.push_back(7);
        list.push_back(8);

        list.RemoveNth(-8);
        REQUIRE(list.size() == 3);
        REQUIRE(list.front() == 6);
        REQUIRE(list.back() == 8);
    }

    SECTION("Removes odd position from list") {
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

    SECTION("Removes even position from list") {
        LinkedList<float> list2;
        list2.push_back(6.1f);
        list2.push_back(7.1f);
        list2.push_back(8.1f);
        list2.push_back(9.2f);
        list2.push_back(10.8f);

        list2.RemoveNth(2);
        REQUIRE(list2.size() == 4);
        REQUIRE(list2.front() == 6.1f);
        REQUIRE(list2.back() == 10.8f);
    }
}

TEST_CASE("operator!=", "[push_back]") {
    LinkedList<int> list;
    LinkedList<int> list2;

    SECTION("Test empty lists") {
        REQUIRE_FALSE(list != list2);
    }

    SECTION("Tests with first list being smaller") {
        list.push_back(5);

        list2.push_back(5);
        list2.push_back(10);
        REQUIRE(list != list2);
    }

    SECTION("Tests with second list being smaller") {
        list.push_back(5);
        list.push_back(10);
        list.push_back(20);

        list2.push_back(5);
        list2.push_back(10);
        REQUIRE(list != list2);
    }

    SECTION("Tests same size lists with different values") {
        list.push_back(5);
        list.push_back(7);

        list2.push_back(5);
        list2.push_back(10);
        REQUIRE(list != list2);
    }

    SECTION("Tests same size lists with same values") {
        list.push_back(5);
        list.push_back(10);
        list.push_back(8);

        list2.push_back(5);
        list2.push_back(10);
        list2.push_back(8);
        REQUIRE_FALSE(list != list2);
    }

    SECTION("Tests same string values") {
        LinkedList<std::string> list3;
        LinkedList<std::string> list4;

        list3.push_back("Hello");
        list3.push_back("World");

        list4.push_back("Hello");
        list4.push_back("World");

        REQUIRE_FALSE(list3 != list4);
    }

    SECTION("Tests different string values") {
        LinkedList<std::string> list3;
        LinkedList<std::string> list4;

        list3.push_back("Hello");
        list3.push_back("World");

        list4.push_back("Bye");
        list4.push_back("World");

        REQUIRE(list3 != list4);
    }
}

TEST_CASE("operator==", "[push_back]") {
    LinkedList<int> list;
    LinkedList<int> list2;

    SECTION("Test empty lists") {
        REQUIRE(list == list2);
    }

    SECTION("Test 1 size lists of same values") {
        list.push_back(5);
        list2.push_back(5);
        REQUIRE(list == list2);
    }

    SECTION("Test 1 size lists of different values") {
        list.push_back(5);
        list2.push_back(6);
        REQUIRE_FALSE(list == list2);
    }

    SECTION("Tests with first list being smaller") {
        list.push_back(5);

        list2.push_back(5);
        list2.push_back(10);
        REQUIRE_FALSE(list == list2);
    }

    SECTION("Tests with second list being smaller") {
        list.push_back(5);
        list.push_back(10);
        list.push_back(20);

        list2.push_back(5);
        list2.push_back(10);
        REQUIRE_FALSE(list == list2);
    }

    SECTION("Tests same size lists with different values") {
        list.push_back(5);
        list.push_back(7);

        list2.push_back(5);
        list2.push_back(10);
        REQUIRE_FALSE(list == list2);
    }

    SECTION("Tests same size lists with same values") {
        list.push_back(5);
        list.push_back(10);
        list.push_back(8);

        list2.push_back(5);
        list2.push_back(10);
        list2.push_back(8);
        REQUIRE(list == list2);
    }

    SECTION("Tests same string values") {
        LinkedList<std::string> list3;
        LinkedList<std::string> list4;

        list3.push_back("Hello");
        list3.push_back("World");

        list4.push_back("Hello");
        list4.push_back("World");

        REQUIRE(list3 == list4);
    }

    SECTION("Tests different string values") {
        LinkedList<std::string> list3;
        LinkedList<std::string> list4;

        list3.push_back("Hello");
        list3.push_back("World");

        list4.push_back("Bye");
        list4.push_back("World");

        REQUIRE_FALSE(list3 == list4);
    }
}

TEST_CASE("begin()", "[begin][push_back]") {
    LinkedList<int> *list = new LinkedList<int>();

    SECTION("Tests valid begin() method") {
        list->push_back(5);
        list->push_back(10);

        REQUIRE(*list->begin() == 5);
    }
}

TEST_CASE("Tests creating list from vector", "[push_back][size][begin][end]") {
    std::vector<char> vector;

    SECTION("Tests empty vector") {
        LinkedList<char> *list = new LinkedList<char>(vector);
        REQUIRE(list->size() == 0);
    }

    SECTION("Tests valid vector") {
        vector.push_back('z');
        vector.push_back('o');
        vector.push_back('T');
        vector.push_back('G');
        vector.push_back('a');

        LinkedList<char> *list = new LinkedList<char>(vector);
        int count = 0;
        for (auto itr = list->begin(); itr != list->end(); ++itr) {
            REQUIRE(*itr == vector[count]);
            count++;
        }
    }
}

TEST_CASE("Copy Constructor", "[size][push_back]") {
    LinkedList<double> *list = new LinkedList<double>();

    SECTION("Tests pointer empty list") {
        LinkedList<double> *list1 = new LinkedList<double>(*list);
        REQUIRE(list1->size() == 0);
        REQUIRE(*list == *list1);
    }

    SECTION("Tests pointer valid list") {
        list->push_back(6.88);
        list->push_back(1.99);
        list->push_back(444.2);
        list->push_back(53.34563465);

        LinkedList<double> *list1 = new LinkedList<double>(*list);
        REQUIRE(list1->size() == 4);
        REQUIRE(*list == *list1);
    }
}

TEST_CASE("Copy Assignment Operator", "[size][push_back]") {
    LinkedList<int> *list2 = new LinkedList<int>();

    SECTION("Tests empty list") {
        LinkedList<int> list3;
        list3 = *list2;
        REQUIRE(list3.size() == 0);
        REQUIRE(*list2 == list3);
    }

    SECTION("Tests valid list") {
        list2->push_back(6);
        list2->push_back(1);
        list2->push_back(444);
        list2->push_back(53);

        LinkedList<int> list3;
        list3 = *list2;
        REQUIRE(list3.size() == 4);
        REQUIRE(*list2 == list3);
    }
}

TEST_CASE("Move Constructor", "[push_back][size]") {

    SECTION("Empty list") {
        LinkedList<int> *list = new LinkedList<int>();

        LinkedList<int> *list2 = new LinkedList<int>(*list);

        LinkedList<int> *list3 = new LinkedList<int>(std::move(*list));

        REQUIRE(list->size() == 0);
        REQUIRE(list3->size() == 0);
        REQUIRE(*list3 == *list2);
    }

    SECTION("Tests non-empty list") {
        LinkedList<int> *list = new LinkedList<int>();

        list->push_back(177);
        list->push_back(11);
        list->push_back(15);

        LinkedList<int> *list2 = new LinkedList<int>(*list);

        LinkedList<int> *list3 = new LinkedList<int>(std::move(*list));

        REQUIRE(list->size() == 0);
        REQUIRE(list3->size() == 3);
        REQUIRE(*list3 == *list2);
    }
}

TEST_CASE("Move Operator", "[size][push_back]") {

    SECTION("Empty list") {
        LinkedList<int> *list = new LinkedList<int>();

        LinkedList<int> list2;
        list2 = *list;

        LinkedList<int> list3 = std::move(*list);

        REQUIRE(list->size() == 0);
        REQUIRE(list3.size() == 0);
        REQUIRE(list3 == list2);
    }

    SECTION("Tests non-empty list") {
        LinkedList<int> *list = new LinkedList<int>();

        list->push_back(177);
        list->push_back(11);
        list->push_back(15);

        LinkedList<int> list2;
        list2 = *list;

        LinkedList<int> list3 = std::move(*list);

        REQUIRE(list->size() == 0);
        REQUIRE(list3.size() == 3);
        REQUIRE(list3 == list2);
    }
}

TEST_CASE("operator<<", "[push_back]") {
    LinkedList<int> *list = new LinkedList<int>();

    SECTION("Empty list") {
        std::cout << *list << std::endl;
    }

    SECTION("Valid list") {
        list->push_back(234);
        list->push_back(111);
        list->push_back(-77);

        std::cout << *list << std::endl;
    }
}

TEST_CASE("iterator operator !=", "[begin][push_back]") {
    LinkedList<float> list;

    SECTION("Comparing same values") {
        list.push_back(-77.0f);
        list.push_back(100.77f);
        REQUIRE_FALSE(list.begin() != list.begin());
    }

    SECTION("Comparing different values") {
        list.push_back(-77.5f);
        list.push_back(100.4f);
        REQUIRE(++list.begin() != list.begin());
    }
}

TEST_CASE("iterator operator ++", "[begin][push_back]") {
    LinkedList<double> list;

    list.push_back(-77.88);
    list.push_back(1004567.444444);
    auto itr = list.begin();
    ++itr;
    REQUIRE(list.begin() != itr);
    REQUIRE_FALSE(++list.begin() != itr);
}

TEST_CASE("iterator operator *", "[begin][push_back]") {
    LinkedList<std::string> list;

    list.push_back("I'm");
    list.push_back("finished!");
    REQUIRE(*list.begin() == "I'm");
}

TEST_CASE("const iterator operator !=", "[begin]") {

    SECTION("Comparing same values") {
        const LinkedList<char> list(std::vector<char>{'1', 'b'});
        REQUIRE_FALSE(list.begin() != list.begin());
    }

    SECTION("Comparing different values") {
        const LinkedList<char> list(std::vector<char>{'1', 'b'});
        REQUIRE(++list.begin() != list.begin());
    }
}

TEST_CASE("const iterator operator ++", "[begin]") {
    const LinkedList<double> list(std::vector<double>{77.88, 1004567.444444});
    auto itr = list.begin();
    ++itr;
    REQUIRE(list.begin() != itr);
    REQUIRE_FALSE(++list.begin() != itr);
}

TEST_CASE("const iterator operator *", "[begin]") {
    const LinkedList<std::string> list(std::vector<std::string>{"I'm", "finished!"});
    REQUIRE(*list.begin() == "I'm");
}