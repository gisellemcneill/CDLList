
// ------------------------------------------------ CDLList.cpp -------------------------------------------------------

// Giselle McNeill CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date 4/5/26

// Date of Last Modification 4/8/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose:
// Defines the CDDList template class, which implements a circular doubly linked list using a
// dummy header node. Each node contains two pointers, one for next and one for prev, which allows
// for traversal in both directions. There is no tail in this list, so the dummy header will mark
// the beginning and end of the list.

// This class supports all standard linked list operations: insert(), remove(), retrieve(), find()
// size(), clear(), isEmpty(), copy constructor, constructor, destructor, and an assignment operator

// Provides efficiency by using pointer manipulation and the circular aspect of the list to remove
// the need for special cases at the front or the end of the list for remove/insert

// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------


#ifndef CSS343PROGRAM1_CDLLIST_H
#define CSS343PROGRAM1_CDLLIST_H
#include <iostream>

using namespace std;

template <class Object>
struct DLListNode { //Declaring the node object that will be used
    Object item;
    DLListNode<Object>* prev;
    DLListNode<Object>* next;
};

template <class Object>
class CDLList {
public:
    CDLList(); //Constructor create a dummy header
    CDLList(const CDLList& rhs); //Copy Constructor
    ~CDLList(); //Destructor

    bool isEmpty() const; //Check if the list is empty
    int size()const; //Number of nodes in the list
    void clear(); // Remove all nodes in the list
    void insert(const Object& obj, int index); //Insert at index (0 = first node)
    int find(const Object& obj) const; //Return index or -1 if not found
    void remove(const Object& obj); //Remove first occurrence
    Object retrieve(int index) const; //Retrieve data at index
    const CDLList& operator=(const CDLList& rhs); //Assignment operator

private:
    DLListNode<Object>* header;
};

#include "CDLList.cpp"
#endif //CSS343PROGRAM1_CDLLIST_H