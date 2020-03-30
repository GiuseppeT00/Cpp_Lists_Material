// Trimigno Giuseppe , Computer Engineering at Univeristy of Parma, Italy
// Link class for Linked Data Structures like Linked Lists, Stacks and Queues


#ifndef LINK_H
#define LINK_H

#include <cstddef>

// Singly linked list node
template <typename E> class Link {
public:
  E element;      // Value for this node
  Link *next;        // Pointer to next node in list
  // Constructors
  Link(const E& elemval, Link* nextval =NULL)
    { element = elemval;  next = nextval; }
  Link(Link* nextval =NULL) { next = nextval; }
};

#endif