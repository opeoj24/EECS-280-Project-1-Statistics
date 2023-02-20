/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();

void  test_summarize();
void test_summarize1();

void test_count();
void test_count1();
void test_count2();
void test_count3();
void test_sum();
void test_sum1();
void test_sum_large();
void test_mean();
void test_mean1();
void test_median();
void test_median1();
void test_median2();
void test_mode();
void test_mode();
void test_mode1();
void test_min();
void test_min1();
void test_max();
void test_max1();
void test_stdev();
void test_stdev1();
void test_percentile();
void test_percentile1();

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
    
//    test_summarize();
    test_summarize1();
    test_count();
//    test_count1();
    test_count2();
    test_count3();
    test_sum();
    test_sum_large();
    test_sum1();
    test_mean();
    test_mean1();
    test_median();
    test_median1();
    test_median2();
    test_mode();
    test_mode1();
    test_min();
    test_min1();
    test_max();
    test_max1();
    test_stdev();
    test_stdev1();
    test_percentile();
    test_percentile1();
  // Call your test functions here

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "Pass" << endl;
}

// Add the test function implementations here.
void test_summarize() {
    cout << "test_summarize" << endl;
    vector<double> data;
    data.push_back(15);
    vector<vector<double>> vex {
        {15, 1}
    };
    assert(summarize(data) == vex);
    cout << "Pass" << endl;
}

void test_summarize1(){
cout << "test_summarize1" << endl;
    vector<double> data;
    data.push_back(1);
    data.push_back(3);
    data.push_back(3);
    data.push_back(6);
    data.push_back(9);
    data.push_back(1);
    vector<vector<double>> vex {
    {1, 2},
    {3, 2},
    {6, 1},
    {9, 1},
};
assert(summarize(data) == vex);
cout << "Pass" << endl;
}

void test_count() {
     cout << "test_count" << endl;
     vector<double> data = {1,2,54,55,6,7};

     assert(count(data) == 6);
     cout << "Pass" << endl;
    }
void test_count2(){
     cout << "test_count2" << endl;
     vector<double> data = {};
     assert(count(data) == 0);
     cout << "Pass"<< endl;
}
void test_count3() {
 cout <<"test_count3" << endl;
 vector<double> data = {-1,-2,-3};
 assert(count(data) == 3);
 cout <<"Pass" << endl;
}

void test_sum() {
 cout << "test_sum" << endl;
 vector<double> data;
 data.push_back(3);
 data.push_back(5);
 data.push_back(5);
 data.push_back(1);
 data.push_back(0);
 data.push_back(15);
 assert(sum(data) == 29);
 cout << "Pass" << endl;
}
    
void test_sum_large() {
 cout <<"test_sum_large" << endl;
 vector<double> data =
    {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,50};
 assert(sum(data) == 470);
 cout << "Pass" << endl;
}
    
void test_sum1() {
 cout <<"test_sum1" << endl;
 vector<double> data = {1};
 assert(sum(data) == 1);
 cout << "Pass" << endl;
}

void test_mean() {
 cout << " test_mean" << endl;
 vector<double> data;
 data.push_back(7);
 data.push_back(4);
 data.push_back(2);
 data.push_back(1);
 data.push_back(2);
 data.push_back(10);
 assert(mean(data) == 4.3);
 cout << "Pass" << endl;
}

void test_mean1() {
 cout << "test_mean1" << endl;
 vector<double> data = {-7, -2, -10, -2, 4};
 assert(mean(data) == -3.4);
 cout << "Pass" << endl;
}
    
void test_median() {
     cout << "test_median" << endl;
     vector<double> data;
     data.push_back(3);
     data.push_back(5);
     data.push_back(2);
     data.push_back(1);
     data.push_back(0);
     data.push_back(10);
     assert(median(data) == 2.5);
     cout << "Pass" << endl;
}

void test_median1() {
     cout << "test_median1" << endl;
     vector<double> data = {-2,2,-2,2};
     assert(median(data) == 0);
     cout <<"Pass" << endl;
    }
    
void test_median2() {
     cout <<"test_median2" << endl;
     vector<double> data = {2};
     assert(median(data) == 2);
     cout << "Pass" << endl;
    }

void test_mode() {
 cout << "test_mode" << endl;
 vector<double> data;
 data.push_back(0);
 data.push_back(2);
 data.push_back(3);
 data.push_back(5);
 data.push_back(10);
 data.push_back(0);
 data.push_back(0);
 assert(mode(data) == 0);
 cout << "Pass " << endl;
}

void test_mode1() {
    cout << "test_mode1" << endl;
     vector<double> data = {-2,-1,-3,0,5,2,-2,4};
     assert(mode(data) == -2);
     cout << "Pass" << endl;
}
void test_min() {
 cout << "test_min" << endl;
 vector<double> data;
 data.push_back(1);
 data.push_back(2);
 data.push_back(3);
 data.push_back(1);
 data.push_back(0);
 data.push_back(12);
 assert(min(data) == 0);
 cout << "Pass" << endl;
}

void test_min1() {
    cout <<"test_min1" << endl;
     vector<double> data = {2,3,4,5,6,1,7,8,9,1,1,1};
     assert(min(data) == 1);
     cout << "Pass" << endl;
}
void test_max() {
     cout << "test_max" << endl;
     vector<double> data = {3,5,4,0,20,7,10};
    
     assert(max(data) == 20);
     cout << "Pass" << endl;
}

void test_max1(){
     cout << "test_max1" << endl;
     vector<double> data = {-1,-2,-3,0,-20,-7,-10};

     assert(max(data) == 0);
     cout << "Pass" << endl;
}

void test_stdev() {
     cout << "test_stdev" << endl;
     vector<double> data;
     data.push_back(3);
     data.push_back(6);
     data.push_back(5);
     data.push_back(6);
    assert(abs(stdev(data))-sqrt(2) < 0.000005);
    cout << "Pass" << endl;
}

void test_stdev1() {
cout << "test_stdev1" << endl;
    vector<double> data;
    data.push_back(-2);
    data.push_back(-3);
    data.push_back(-4);
    data.push_back(-5);
    assert((stdev(data) - 1.1180339887499) < 0.0001);
    cout << "Pass" << endl;
}

void test_percentile() {
 cout << "test_percentile" << endl;
 vector<double> data = {3,5,2,1,0,10,0,10};
 cout << percentile(data,0.75) << endl;
}
void test_percentile1() {
    cout << "test_percentile1" << endl;
    vector<double> data;
    data.push_back(3);
    data.push_back(3);
    data.push_back(3);
    data.push_back(3);
    double difference = abs(percentile(data, 0.7) - 3);
    assert (difference < 0.000005);
    cout << "Pass" << endl;
}

