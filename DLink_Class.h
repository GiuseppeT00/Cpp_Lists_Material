// Trimigno Giuseppe , Computer Engineering at Univeristy of Parma, Italy
// Doubly Linked class for DList Data Structure


#ifndef DLINK_H
#define DLINK_H

// Doubly linked list node
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