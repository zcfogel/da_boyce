#include "p2.h"

#include  "test_helpers.h"

#include <iostream>
#include <cassert>

using namespace std;

// YOU MUST EXTEND THE MAIN FUNCTION IN THIS FILE SO THAT IT TESTS EVERY
// PUBLIC FUNCTION YOU IMPLEMENT IN P2.CPP!
//
// Protip #1: Write tests for the functions BEFORE you implement them!
// (i.e. Write tests for sum() first, and then write sum())
// It sounds like a pain, but it helps make sure that you are never under the
// illusion that your code works when it's actually full of bugs.
//
// Protip #2: Instead of putting all your tests in main() (and making life
// more difficult--especially for the graders), put each test case in a
// function!
//
//
// We recommend using the functions in test_helpers.h when
// writing your test cases.
//

int main()
{
    test_sum_basic();
    // ---- Call your test functions here ----
    return 0;
}

// Effects: Tests sum()
void test_sum_basic()
{
    // Here's a free test case! You can model your tests after this one.
    list_t listA = list_make();

    for (int i = 0; i < 5; ++i)
    {
        listA = list_make(i, listA);
    }

    const int EXPECTED_SUM = 10;
    int actual_sum = sum(listA);
    cout << "Expected sum: " << EXPECTED_SUM << endl;
    cout << "Actual sum: " << actual_sum << endl;
    assert(EXPECTED_SUM == actual_sum);

    cout << "PASS!" << endl;
}


// Effects: Tests sum()
void test_sum()
{
    cout << "Testing Sum" << endl;
    // create empty lists
    list_t list_all_pos = list_make();
    list_t list_all_0 = list_make();
    list_t list_all_same = list_make();
    list_t list_some_neg = list_make();
    list_t list_all_neg = list_make();
    list_t list_empty = list_make();
    list_t list_dec = list_make();

    // fill lists
    for (int i = 1; i <= 10; ++i)
    {
        list_make(i, list_all_pos);
        list_make(0, list_all_0);
        list_make(9, list_all_same);
        list_make(i - 5, list_some_neg);
        list_make(i - 11, list_all_neg);
        list_make((double) i / 10.0, list_dec);
    }
    
    // compare actual and expected values
    assert(sum(list_all_pos) == 55);
    assert(sum(list_all_0) == 0);
    assert(sum(list_all_same) == 90);
    assert(sum(list_some_neg) == 5);
    assert(sum(list_all_neg) == -55)
    assert(sum(list_empty) == 0);
    assert(sum(list_dec) == 5.5);

    cout << "PASS!!"

    return;
}

// Effects: Tests product()
void test_product()
{
    cout << "Testing Product" << endl;
    // create empty lists
    list_t list_all_pos = list_make();
    list_t list_all_0 = list_make();
    list_t list_all_same = list_make();
    list_t list_some_neg = list_make();
    list_t list_all_neg = list_make();
    list_t list_empty = list_make();
    list_t list_dec = list_make();

    // fill lists
    for (int i = 1; i <= 10; ++i)
    {
        list_make(i, list_all_pos);
        list_make(0, list_all_0);
        list_make(9, list_all_same);
        list_make(i - 5, list_some_neg);
        list_make(i - 11, list_all_neg);
        list_make((double) i / 10.0, list_dec);
    }

    // compare actual and expected values
    assert(test_product(list_all_pos) == 3628800);
    assert(test_product(list_all_0) == 0);
    assert(test_product(list_all_same) == 3486784401);
    assert(test_product(list_some_neg) == 0);
    assert(test_product(list_all_neg) == 3628800);
    assert(test_product(list_empty) == 1);
    assert(test_product(list_dec) == 0.00036288);

    cout << "PASS!!"
    
    return;
}

// Effects: Tests Accumulate()
void test_accumulate();

// Effects: Tests Reverse()
void test_reverse()
{
    cout << "Testing Reverse" << endl;
    // define lists to test
    list_t list_all_pos = list_make();
    list_t list_all_0 = list_make();
    list_t list_all_same = list_make();
    list_t list_some_neg = list_make();
    list_t list_all_neg = list_make();
    list_t list_empty = list_make();
    list_t list_dec = list_make();

    // fill lists for testing
    for (int i = 1; i <= 10; ++i)
    {
        list_make(i, list_all_pos);
        list_make(0, list_all_0);
        list_make(9, list_all_same);
        list_make(i - 5, list_some_neg);
        list_make(i - 11, list_all_neg);
        list_make(i / 10, list_dec);
    }

    // define expected lists that function returns
    list_t list_expected_all_pos = list_make();
    list_t list_expected_all_0 = list_make();
    list_t list_expected_all_same = list_make();
    list_t list_expected_some_neg = list_make();
    list_t list_expected_all_neg = list_make();
    list_t list_expected_empty = list_make();
    list_t list_expected_dec = list_make();

    // fill expected return lists
    for (int i = 0; i < 10; ++i)
    {
        list_make(10 - i, list_expected_all_pos);
        list_make(0, list_expected_all_0);
        list_make(9, list_expected_all_same);
        list_make(5 - i, list_expected_some_neg);
        list_make(-1 - i, list_expected_all_neg);
        list_make(1 - ((double) i / 10.0), list_expected_dec);
    }

    // compare actual and expected lists
    assert(reverse(list_all_pos) == list_expected_all_pos);
    assert(reverse(list_all_0) == list_expected_all_0);
    assert(reverse(list_all_same) == list_expected_all_same);
    assert(reverse(list_some_neg) == list_expected_some_neg);
    assert(reverse(list_all_neg) == list_expected_all_neg);
    assert(reverse(list_empty) == list_expected_empty);
    assert(reverse(list_dec) == list_expected_dec);

    cout << "PASS!!" << endl;
}

// Effects: Tests append()
void test_append();

// Effects: Tests filter_odd()
void test_filter_odd()
{
    cout << "Testing Filter_odd" << endl;
    // define lists to test
    list_t list_all_pos = list_make();
    list_t list_all_0 = list_make();
    list_t list_all_same = list_make();
    list_t list_some_neg = list_make();
    list_t list_all_neg = list_make();
    list_t list_empty = list_make();
    list_t list_dec = list_make();

    // fill lists for testing
    for (int i = 1; i <= 10; ++i)
    {
        list_make(i, list_all_pos);
        list_make(0, list_all_0);
        list_make(9, list_all_same);
        list_make(i - 5, list_some_neg);
        list_make(i - 11, list_all_neg);
        list_make((double) i / 10, list_dec);
    }

    // define expected lists that function returns
    list_t list_expected_all_pos = list_make();
    list_t list_expected_all_0 = list_make();
    list_t list_expected_all_same = list_make();
    list_t list_expected_some_neg = list_make();
    list_t list_expected_all_neg = list_make();
    list_t list_expected_empty = list_make();
    list_t list_expected_dec = list_make();

    // fill expected return lists
    for (int i = 1; i < 10; ++i)
    {
         if ((double) i % 2 != 0) list_make(i, list_expected_all_pos);
         list_make(9, list_expected_all_same);
         if ((double) (i - 5) % 2 != 0) list_make(i - 5, list_expected_some_neg);
         if ((double) (i - 11) % 2 != 0) list_make(i - 11, list_expected_all_neg);
    }
    list_make(1, list_expected_dec);

    // compare actual and expected lists
    assert(filter_odd(list_all_pos) == list_expected_all_pos);
    assert(filter_odd(list_all_0) == list_expected_all_0);
    assert(filter_odd(list_all_same) == list_expected_all_same);
    assert(filter_odd(list_some_neg) == list_expected_some_neg);
    assert(filter_odd(list_all_neg) == list_expected_all_neg);
    assert(filter_odd(list_empty) == list_expected_empty);
    assert(filter_odd(list_dec) == list_expected_dec);

    cout << "PASS!!" << endl;
}

// Effects: Tests filter_even()
void test_filter_even()
{
    cout << "Testing Filter_even" << endl;
    // define lists to test
    list_t list_all_pos = list_make();
    list_t list_all_0 = list_make();
    list_t list_all_same = list_make();
    list_t list_some_neg = list_make();
    list_t list_all_neg = list_make();
    list_t list_empty = list_make();
    list_t list_dec = list_make();

    // fill lists for testing
    for (int i = 1; i <= 10; ++i)
    {
        list_make(i, list_all_pos);
        list_make(0, list_all_0);
        list_make(9, list_all_same);
        list_make(i - 5, list_some_neg);
        list_make(i - 11, list_all_neg);
        list_make((double) i / 10, list_dec);
    }

    // define expected lists that function returns
    list_t list_expected_all_pos = list_make();
    list_t list_expected_all_0 = list_make();
    list_t list_expected_all_same = list_make();
    list_t list_expected_some_neg = list_make();
    list_t list_expected_all_neg = list_make();
    list_t list_expected_empty = list_make();
    list_t list_expected_dec = list_make();

    // fill expected return lists
    for (int i = 1; i < 10; ++i)
    {
         if ((double) i % 2 == 0) list_make(i, list_expected_all_pos);
         if ((double) (i - 5) % 2 == 0) list_make(i - 5, list_expected_some_neg);
         if ((double) (i - 11) % 2 == 0) list_make(i - 11, list_expected_all_neg);
    }

    // compare actual and expected lists
    assert(filter_even(list_all_pos) == list_expected_all_pos);
    assert(filter_even(list_all_0) == list_expected_all_0);
    assert(filter_even(list_all_same) == list_expected_all_same);
    assert(filter_even(list_some_neg) == list_expected_some_neg);
    assert(filter_even(list_all_neg) == list_expected_all_neg);
    assert(filter_even(list_empty) == list_expected_empty);
    assert(filter_even(list_dec) == list_expected_dec);

    cout << "PASS!!" << endl;
}

// Effects: Tests filter()
void test_filter();

// Effects: Tests rotate()
void test_rotate()
{
    cout << "Testing Rotate" << endl;
    // define lists to test
    list_t list_all_pos = list_make();
    list_t list_all_0 = list_make();
    list_t list_all_same = list_make();
    list_t list_some_neg = list_make();
    list_t list_all_neg = list_make();
    list_t list_empty = list_make();
    list_t list_dec = list_make();

    // fill lists for testing
    for (int i = 1; i <= 10; ++i)
    {
        list_make(i, list_all_pos);
        list_make(0, list_all_0);
        list_make(9, list_all_same);
        list_make(i - 5, list_some_neg);
        list_make(i - 11, list_all_neg);
        list_make((double) i / 10, list_dec);
    }

    // define expected lists that function returns
    list_t list_expected_all_pos = list_make();
    list_t list_expected_all_0 = list_make();
    list_t list_expected_all_same = list_make();
    list_t list_expected_some_neg = list_make();
    list_t list_expected_all_neg = list_make();
    list_t list_expected_empty = list_make();
    list_t list_expected_dec = list_make();

    // fill expected return lists
    // fill lists for testing
    for (int i = 10; i >= 1; --i)
    {
        list_make(i, list_all_pos);
        list_make(0, list_all_0);
        list_make(9, list_all_same);
        list_make(i - 5, list_some_neg);
        list_make(i - 11, list_all_neg);
        list_make((double) i / 10, list_dec);
    }

    assert(rotate(list_all_pos) == list_expected_all_pos);
    assert(rotate(list_all_0)) == list_expected_all_0);
    assert(rotate(list_all_same) == list_expected_all_same);
    assert(rotate(list_some_neg) == list_expected_some_neg);
    assert(rotate(list_all_neg) == list_expected_all_neg);
    assert(rotate(list_empty) == list_expected_empty);
    assert(rotate(list_dec) == list_expected_dec);
}

// Effects: Tests insert_list()
void test_insert_list();

// Effects: Tests chop()
void test_chop();