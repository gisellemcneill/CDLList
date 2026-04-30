# Circular Doubly Linked List (with Dummy Header) in C++

This project implements a circular doubly linked list using a dummy header node to simplify insertion and deletion logic. Each node contains pointers to both the next and previous nodes, and the structure is circular to eliminate special edge cases at the head and tail.

Compare driver is also included and will have to compile with NDLList.cpp to perform runtime 
analyze and determine efficiency.

## Features

- Doubly linked node structure (next and previous pointers)
- Circular linking (tail connects back to head)
- Dummy header node for simplified logic
- Core operations:
  - insert
  - remove
  - retrieve
  - find
  - size
  - isEmpty
  - clear
- Full copy constructor and assignment operator support
- Proper destructor for memory cleanup

## Design Highlights

The use of a dummy header node removes the need for special-case handling when inserting or deleting at the head or tail of the list. The circular structure ensures consistent traversal behavior in both directions.

## Testing

A `driver.cpp` file is included to validate all list operations. A `compare_driver.cpp` is also included to compare performance against a singly linked list implementation.

## Purpose

This project was built to demonstrate advanced linked list design, including circular structures, bidirectional traversal, and memory-safe C++ class implementation.
