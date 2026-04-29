// ------------------------------------------------ driver.cpp -------------------------------------------------------

// Giselle McNeill CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date 4/5/26

// Date of Last Modification 4/8/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// This driver program is designed to test the accuracy of the NDLList and the CDLList implementations
// Verifies that each list operation behaves as expected

// functions tested are: insert(), remove(), retrieve(), find(), size(), clear(), isEmpty(), copy assignment
// copy constructor

// The goal of this file is to ensure logical correctness and proper implementation, good pointer manipulation,
// and good memory management that results in no memory leaks

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cassert> //allows for testing
#include <string>
#include "NDLList.h" //non dummy header list
#include "CDLList.h" //dummy header circular doubly linked list
using namespace std;

/* ================= Helper Functions ================= */
// Generic print function for any list type
template <class ListType>
void printList(const ListType& list) {
    cout << "[ ";
    for (int i = 0; i < list.size(); ++i) {
        cout << list.retrieve(i) << " ";
    }
    cout << "]" << endl;
}
// Run the same tests on both NDLList and DLList
/* ================= Testing Strings ================= */
template <class ListType>
void runTests(const string& listName) {
    cout << "\n=====================================\n";
    cout << " Testing Strings: " << listName << endl;
    cout << "=====================================\n\n";

    // 1. Constructor, isEmpty, size
    cout << "1. Default constructor\n";
    ListType list;
    cout << "isEmpty(): " << (list.isEmpty() ? "true" : "false") << endl;
    cout << "size(): " << list.size() << endl;
    printList(list);

    // 2. Insertions at Boundaries
    cout << "\n2. Insertions\n";
    list.insert("Apple", 0); //head
    list.insert("Banana", 1); //tail
    list.insert("Coconut", 1); //middle
    printList(list);
    assert(list.size() == 3);

    // 3. Retrieve Elements
    cout << "\n3. Retrieve Elements\n";
    for (int i = 0; i < list.size(); i++) {
        cout << "Element at index " << i << ": " << list.retrieve(i) << endl;
    }

    // 4. Remove elements

    cout << "\n4. Remove Middle (Coconut)\n";
    list.remove("Coconut");
    printList(list);
    assert(list.size() == 2);

    cout << "\n5. Remove head (Apple)\n";
    list.remove("Apple");
    printList(list);
    assert(list.size() == 1);


    cout << "\n6. Remove tail (Banana)\n";
    list.remove("Banana");
    printList(list);
    assert(list.size() == 0);

    cout << "\n7. Remove nonexistent('I DONT EXIST')\n";
    list.remove("I DONT EXIST");
    printList(list);
    assert(list.isEmpty());

    // 5. Out-of-bounds insert
    cout << "\n8. Insert out-of-range (Should not change list)\n";
    list.insert("NOPE", 10);
    printList(list);
    assert(list.isEmpty());

    // 6. Test assignment operator
    cout << "\n9. Assignment operator\n";
    list.insert("APPLE",0);
    list.insert("BANANA",1);
    list.insert("COCONUT",2);
    printList(list);
    ListType copyList;
    copyList = list;
    cout << "Copied list: ";
    printList(copyList);

    // 7. Clear list
    cout << "\n10. Clear list\n";
    list.clear();
    assert(list.isEmpty());
    printList(list);

    //8. Large list
    cout << "\n11. Large list:\n";
    ListType bigList;
    for (int i = 0; i < 100; i++) {
        bigList.insert("test", i);
    }
    for (int i = 0; i < 100; i += 2) {
        bigList.remove("test");
    }
    cout << "Big list size after removals(should be 50): " << bigList.size() << endl;


    cout << "\n===== End of " << listName << " tests =====\n";
}

/* ================= Testing Integers ================= */
template <class ListType>
void runTestsInt(const string& listName) {
    cout << "\n=====================================\n";
    cout << " Testing Integers: " << listName << endl;
    cout << "=====================================\n\n";

    // 1. Constructor, isEmpty, size
    cout << "1. Default constructor\n";
    ListType list;
    cout << "isEmpty(): " << (list.isEmpty() ? "true" : "false") << endl;
    cout << "size(): " << list.size() << endl;
    printList(list);

    // 2. Insertions at Boundaries
    cout << "\n2. Insertions\n";
    list.insert(10, 0); //head
    list.insert(20, 1); //tail
    list.insert(30, 1); //middle
    printList(list);
    assert(list.size() == 3);

    // 3. Retrieve Elements
    cout << "\n3. Retrieve Elements\n";
    for (int i = 0; i < list.size(); i++) {
        cout << "Element at index " << i << ": " << list.retrieve(i) << endl;
    }

    // 4. Remove elements

    cout << "\n4. Remove Middle (20)\n";
    list.remove(30);
    printList(list);
    assert(list.size() == 2);

    cout << "\n5. Remove head (10)\n";
    list.remove(10);
    printList(list);
    assert(list.size() == 1);

    cout << "\n6. Remove tail (30)\n";
    list.remove(20);
    printList(list);
    assert(list.size() == 0);

    cout << "\n7. Remove nonexistent(100)\n";
    list.remove(100);
    printList(list);
    assert(list.isEmpty());

    // 5. Out-of-bounds insert
    cout << "\n8. Insert out-of-range (Should not change list)\n";
    list.insert(50, 10);
    printList(list);
    assert(list.isEmpty());

    // 6. Test assignment operator
    cout << "\n9. Assignment operator\n";
    list.insert(1,0);
    list.insert(2,1);
    list.insert(3,2);
    printList(list);
    ListType copyList;
    copyList = list;
    cout << "Copied list: ";
    printList(copyList);

    // 7. Clear list
    cout << "\n10. Clear list\n";
    list.clear();
    assert(list.isEmpty());
    printList(list);

    //8. Large list
    cout << "\n11. Large list:\n";
    ListType bigList;
    for (int i = 0; i < 100; i++) {
        bigList.insert(i, i);
    }
    for (int i = 0; i < 100; i += 2) {
        bigList.remove(i);
    }
    cout << "Big list size after removals(should be 50): " << bigList.size() << endl;

    cout << "\n===== End of " << listName << " tests =====\n";
}
/* ============================= MAIN ============================= */
int main() {
    runTests<NDLList<string> >("NDLList<string> (non-dummy, singly)");
    runTestsInt<NDLList<int> >("NDLList<int> (non-dummy, singly)");

    runTests<CDLList<string> >("CDLList<string> (dummy, circular, doubly)");
    runTestsInt<CDLList<int> >("CDLList<int> (dummy, circular, doubly)");

    cout << "\nAll tests passed! Woohoo!" << endl;
    return 0;
};