
// ------------------------------------------------ CDLList.cpp -------------------------------------------------------

// Giselle McNeill CSS343 - 11AM T/TH with Wooyoung Kim

// Creation Date 4/5/26

// Date of Last Modification 4/8/26

// --------------------------------------------------------------------------------------------------------------------

// Purpose: Implements a circular doubly linked list with a dummy header node
//          Standard Linked List operations are included: insert(), remove(), retrieve(), find(), size(), isEmpty()
//          ,clear() along with a constructor, destructor, copy constructor and assignment operator
//          It is designed to allow for efficient addition/removal anywhere in the list by having nodes with pointers
//          in both directions, also being circular which allows for edge cases to be removed for insertion/removal
//          at the head or tail.
// --------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------

#include "CDLList.h"


// ------------------------------------Constructor-----------------------------------------------
// Description:

// Constructor: Constructs an empty circular doubly linked list with a dummy header node
// preconditions: None
// postconditions: List is initialized, header's next and prev point to itself
//isEmpty will return true and size will be 0
// --------------------------------------------------------------------------------------------
template<class Object>
CDLList<Object>::CDLList() {
    header = new DLListNode<Object>;
    header -> next = header;
    header -> prev = header;
}
//end of constructor


// ------------------------------------ Copy Constructor-----------------------------------------------
// Description:

// Copy Constructor: Creates a deep copy of another CDLList
// preconditions: rhs is a valid CDLList
// postconditions: This list contains the same elements as rhs in the same order
// two lists now exist the original (rhs) and the newly created one
// --------------------------------------------------------------------------------------------
template<class Object>
CDLList<Object>::CDLList(const CDLList& rhs) {

    header = new DLListNode<Object>;
    header -> next = header;
    header -> prev = header;

    int index = 0;
    DLListNode<Object>* curr = rhs.header -> next;
    while (curr != rhs.header) {
        insert(curr -> item, index);
        index++;
        curr = curr -> next;
    }
}
//End of copy constructor


// ------------------------------------Destructor-----------------------------------------------
// Description:

// Destructor: Deallocates all nodes and deletes the list safely by calling clear()
// preconditions: List is initialized and contains nodes
// postconditions: All nodes are deleted, list no longer exists/can be used
// --------------------------------------------------------------------------------------------
template<class Object>
CDLList<Object>::~CDLList() {
    clear();
    delete header;
}
//end of destructor


// ------------------------------------isEmpty()-----------------------------------------------
// Description:

// isEmpty(): Checks whether the list has any elements
// preconditions: List is initialized
// postconditions: Returns false if there are no nodes in the list, otherwise returns true

// --------------------------------------------------------------------------------------------
template<class Object>
bool CDLList<Object>::isEmpty() const {
    return header -> next == header;
}
//end of isEmpty()


// ------------------------------------size()-----------------------------------------------
// Description:

// size(): Counts number of nodes in the list (excluding the dummy node)
// preconditions: List is initialized
// postconditions: Returns the number of nodes currently in the list
// --------------------------------------------------------------------------------------------
template<class Object>
int CDLList<Object>::size()const {

    int size = 0;

    DLListNode<Object>* curr = header -> next;
    while (curr != header) {
        size++;
        curr = curr -> next;
    }
    return size;
}
//end of size()


// ------------------------------------clear()-----------------------------------------------
// Description:

// clear(): delete all nodes in the list
// preconditions: List is initialized and contains nodes
// postconditions: List is empty, all nodes are delete,
// dummy header next and prev point to self
// --------------------------------------------------------------------------------------------
template<class Object>
void CDLList<Object>::clear(){

    DLListNode<Object>* curr = header -> next;
    while (curr != header) {
        DLListNode<Object>* temp = curr;
        curr = curr -> next;
        delete temp;
    }

    header -> next = header;
    header -> prev = header;
}
//end of size()


// ------------------------------------insert()-----------------------------------------------
// Description:

// insert(): Insert new node containing the passed in object at the specified index(0-based)
// preconditions: 0 <= index <= size(), and list is initialized
// postconditions: A new node is inserted at index, nodes following are shifted right
// Size will also increase by 1
// --------------------------------------------------------------------------------------------
template<class Object>
void CDLList<Object>::insert(const Object& obj, int index) {

    if (index < 0 || index > size()) {
        return;
    }

    DLListNode<Object>* curr = header -> next;
    for (int i = 0; i < index; i++) {
        curr = curr -> next;
    }

    DLListNode<Object>* newNode = new DLListNode<Object>;
    newNode -> item = obj;
    newNode -> next = curr;
    newNode -> prev = curr -> prev;

    (curr -> prev) -> next = newNode;
    curr -> prev = newNode;
}
//end of insert()


// ------------------------------------find()-----------------------------------------------
// Description:

// find(): Searches for passed in obj(Object) in the list and returns index
// preconditions: List is initialized, may find obj
// postconditions: Returns index (0-based) of the first occurrence of obj,
// otherwise returns -1 if obj not found, list is unchanged
// --------------------------------------------------------------------------------------------
template<class Object>
int CDLList<Object>::find(const Object& obj) const {

    int index = 0;

    DLListNode<Object>* curr = header -> next;
    while (curr != header) {
        if (curr -> item == obj) {
            return index;
        }
        curr = curr -> next;
        index++;
    }
    return -1;
}
//end of find()


// ------------------------------------remove()-----------------------------------------------
// Description:

// remove(): Removes first occurrence of the node containing obj
// preconditions: List is initialized, may contain obj
// postconditions: Deletes first occurrence of node containing obj from the list,
// size decreases by one, list remains intact
// --------------------------------------------------------------------------------------------
template<class Object>
void CDLList<Object>::remove(const Object& obj) {

    if (header -> next == header) {
        return;
    }

    DLListNode<Object>* curr = header -> next;
    while (curr != header) {
        if (curr -> item == obj) {
            (curr -> prev) -> next = curr -> next;
            (curr -> next) -> prev = curr -> prev;
            delete curr;
            return;
        }
        curr = curr -> next;
    }
}
//end of remove()


// ------------------------------------retrieve()-----------------------------------------------
// Description:

// retrieve(): Returns the object stored at the passed in index (0-based)
// preconditions: 0 <= index <= size(), list is initialized
// postconditions: Returns the object at specified index, list remains unchanged
// --------------------------------------------------------------------------------------------
template<class Object>
Object CDLList<Object>::retrieve(int index) const {

    if (index < 0 || index >= size()) {
        return Object();
    }

    DLListNode<Object>* curr = header -> next;
    for (int i = 0; i < index; i++) {
        curr = curr -> next;
    }

    if (curr == header) {
        return Object(); //out of bounds
    }

    return curr -> item;
}
//end of retrieve()


// ------------------------------------Assignment Operator-----------------------------------------------
// Description:

// Assignment Operator: Assigns contents of list rhs to this list using a deep copy
// preconditions: rhs is a valid CDLList, list is initalized
// postconditions: this list contains a deep copy of rhs; previous data nodes in this list are deleted
// --------------------------------------------------------------------------------------------
template<class Object>
const CDLList<Object>& CDLList<Object>::operator=(const CDLList& rhs) {

    if (this == &rhs) { //Self assignment check
        return *this;
    }

    clear();

    int index = 0;
    DLListNode<Object>* curr = rhs.header -> next;
    while (curr != rhs.header) {
        insert(curr -> item , index);
        index++;
        curr = curr -> next;
    }
    return *this;
}
//end of assignment operator