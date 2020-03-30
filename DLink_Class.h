// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef DLINK_H
#define DLINK_H

// Singly linked list node
template <typename E> class dLink {
public:
  E element;      // Value for this node
  dLink *next;        // Pointer to next node in list
  dLink* prev;         // Pointer to previous node

    // Constructors
  dLink(const E& it, dLink* prevp, dLink* nextp) {
    element = it;
    prev = prevp;
    next = nextp;
  }
  dLink(dLink* prevp =NULL, dLink* nextp =NULL) {
    prev = prevp;
    next = nextp;
  }

};

#endif