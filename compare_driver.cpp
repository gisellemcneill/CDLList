
// ------------------------------------------------ NDLList.cpp -------------------------------------------------------

// Giselle McNeill CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date 4/8/26

// Date of Last Modification 4/8/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:

// Run g++ -std=c++11 -Wall -Wextra -o compare compare_driver.cpp followed by ./compare to run tests

// This driver program benchmarks and compares the performance of a DLList (a circular doubly linked list
// with a dummy header) and NDLList, which represents a standard singly linked list with a head pointer

// This program measures the execution time for each key function by using large inputs
// and measuring the output in milliseconds, comparing both ints and strings
// Used to analyze the differences in runtime between the two Linked List implementations
// This file is used to compare efficiency after correctness has been tested using the driver file

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <chrono>
#include "NDLList.h"
#include "CDLList.h"

using namespace std;
using namespace std::chrono;

constexpr int N = 20000;   // number of operations per test

/* ================= Timing Utility ================= */

template <typename Func>
long long timeOperation(Func op) {
    auto start = high_resolution_clock::now();
    op();
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

/* ================= Benchmark Function ================= */

template <class ListType>
void benchmark(const string& name) {
    cout << "\n=============================================\n";
    cout << " Benchmarking (STRING TEST)" << name << "\n";
    cout << "=============================================\n";

    ListType list;

    // 1. Insertion test
    auto t1=timeOperation([&]() {
        for (int i = 0; i < N; i += 2) {
            list.insert("x", list.size()); //insert at end
            list.insert("y", 0); //insert at head
        }
    });
    cout << "Insert time:   " << t1 << " ms" << endl;

    // 2. Retrieve Test
    auto t2=timeOperation([&]() {
        for (int i = 0; i < N; ++i)
            list.retrieve(i);
    });
    cout << "Retrieve time:     " << t2 << " ms" << endl;

    // 3. Size Test
    auto t3=timeOperation([&]() {
            list.size();

    });
    cout << "Size time:     " << t3 << " ms" << endl;

    // 4. Find Test
    auto t4=timeOperation([&]() {
        for (int i = 0; i < N; ++i)
            list.find("x");
    });
    cout << "Find time:         " << t4 << " ms" << endl;

    // 5. Remove Test
    auto t5=timeOperation([&] {
        while (!list.isEmpty()) {
            list.remove(list.retrieve(0)); //remove head
        }
    });
    cout << "Remove Time:      " << t5 << " ms" << endl;

    // 6. Empty Test
    auto t6=timeOperation([&]() {
        list.isEmpty();
    });
    cout << "isEmpty Time:      " << t6 << " ms" << endl;

    // 7. Inserting again Test for other tests
    auto t7=timeOperation([&]() {
        for (int i = 0; i < N; ++i)
            list.insert("z", list.size());
    });
    cout << "Insert Part2:   " << t7 << " ms" << endl;

    // 8. Copy Constructor Test
    auto t8=timeOperation([&]() {
        ListType copy = list;
    });
    cout << "Copy Constructor time:        " << t8 << " ms" << endl;

    // 9. Copy Assignment Test
    auto t9=timeOperation([&] {
        ListType assign_list = list;
    });
    cout << "Assignment Operator time:      " << t9 << " ms" << endl;

    // 10. Clear Test
    auto t10=timeOperation([&] {
        list.clear();
    });
    cout << "Clear time:      " << t10 << " ms" << endl;

}

//Integer test
template <class ListType>
void benchmarkInt(const string& name) {
    cout << "\n=============================================\n";
    cout << " Benchmarking (INT TEST)" << name << "\n";
    cout << "=============================================\n";

    ListType list;

    // 1. Insertion test
    auto t1=timeOperation([&]() {
        for (int i = 0; i < N; i += 2) {
            list.insert(1, list.size()); //insert at end
            list.insert(0, 0); //insert at head
        }
    });
    cout << "Insert time:   " << t1 << " ms" << endl;

    // 2. Retrieve Test
    auto t2=timeOperation([&]() {
        for (int i = 0; i < N; ++i)
            list.retrieve(i);
    });
    cout << "Retrieve time:     " << t2 << " ms" << endl;

    // 3. Size Test
    auto t3=timeOperation([&]() {
        list.size();
    });
    cout << "Size time:     " << t3 << " ms" << endl;

    // 4. Find Test
    auto t4=timeOperation([&]() {
        for (int i = 0; i < N; ++i)
            list.find(1);
    });
    cout << "Find time:         " << t4 << " ms" << endl;

    // 5. Remove Test
    auto t5=timeOperation([&] {
        while (!list.isEmpty()) {
            list.remove(list.retrieve(0)); //remove head
        }
    });
    cout << "Remove Time:      " << t5 << " ms" << endl;

    // 6. Empty Test
    auto t6=timeOperation([&]() {
        list.isEmpty();
    });
    cout << "isEmpty Time:      " << t6 << " ms" << endl;

    // 7. Inserting again Test for other tests
    auto t7=timeOperation([&]() {
        for (int i = 0; i < N; ++i)
            list.insert(3, list.size());
    });
    cout << "Insert Part2:   " << t7 << " ms" << endl;

    // 8. Copy Constructor Test
    auto t8=timeOperation([&]() {
        ListType copy = list;
    });
    cout << "Copy Constructor time:        " << t8 << " ms" << endl;

    // 9. Copy Assignment Test
    auto t9=timeOperation([&] {
        ListType assign_list = list;
    });
    cout << "Assignment Operator time:      " << t9 << " ms" << endl;

    // 10. Clear Test
    auto t10=timeOperation([&] {
        list.clear();
        list.isEmpty();
    });
    cout << "Clear time:      " << t10 << " ms" << endl;

}

/* ============================= MAIN ============================= */

int main() {
    cout << "===== Comparing List Implementations =====\n";
    cout << "Operations per test: " << N << "\n";

    benchmark<NDLList<string> >("NDLList<string>  (non-dummy, singly linked)");
    benchmarkInt<NDLList<int> >("NDLList<int>  (non-dummy, singly linked)");


    benchmark<CDLList<string> >("CDLList<string>   (dummy, circular, doubly linked)");
    benchmarkInt<CDLList<int> >("CDLList<int>   (dummy, circular, doubly linked)");

    cout << "\n===== End of Efficiency Comparison =====\n";
    return 0;
}
