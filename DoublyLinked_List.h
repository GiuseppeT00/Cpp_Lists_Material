// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete DList template class

#ifndef DLIST_H
#define DLIST_H

#include <string>
using namespace std;

// First, get the declaration for the base list class
#include "list.h"
#include "dlink.h"

inline void Assert(bool val, string s);

// This is the declaration for DList. 
template <typename E> class DList: public List<E> {
private:
  dLink<E>* head;       // Pointer to list header
  dLink<E>* tail;       // Pointer to list tailer
  dLink<E>* curr;       // Pointer ahead of current element
  int cnt;             // Size of list

  void init() {        // Intialization helper method
    curr = head = new dLink<E>;
    head->next = tail = new dLink<E>(head, NULL);
    cnt = 0;
  }

  void removeall() {   // Return link nodes to free store
    while(head != NULL) {
      curr = head;
      head = head->next;
      delete curr;
    }
  }

public:
  DList() { init(); } // Constructor
  ~DList() { removeall(); }  // Destructor    // Destructor
  void clear() { removeall(); init(); }       // Clear list

  void moveToStart() // Place curr at list start
    { curr = head; }

  void moveToEnd()   // Place curr at list end
    { curr = tail->prev; }

  void next()
    { 
	 if (curr != tail->prev) curr = curr->next; 
    }

  int length() const  { return cnt; }

  // Return the position of the current element
  int currPos() const {
    dLink<E>* temp = head;
    int i;
    for (i=0; curr != temp; i++)
      temp = temp->next;
    return i;
  }

  // Move down list to "pos" position
  void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
    curr = head;
    for(int i=0; i<pos; i++) curr = curr->next;
  }

  const E& getValue() const { // Return current element
	Assert(curr->next != tail, "No value"); //oss: non è possibile fare una moveToEnd() e poi una getValue()
    return curr->next->element;
  }

// Include those  methods that are different from singly linked list
// Insert "it" at current position
void insert(const E& it) {
  curr->next = curr->next->prev =
    new dLink<E>(it, curr, curr->next);  
  cnt++;
}

// Append "it" to the end of the list.
void append(const E& it) {
  tail->prev = tail->prev->next =
    new dLink<E>(it, tail->prev, tail);
  cnt++;
}

// Remove and return current element
E remove() {
  //if (curr->next == tail)        // Nothing to remove
  //  return NULL;
  Assert(curr->next != tail, "No element");
  E it = curr->next->element;    // Remember value
  dLink<E>* ltemp = curr->next;   // Remember link node
  curr->next->next->prev = curr;
  curr->next = curr->next->next; // Remove from list
  delete ltemp;                  // Reclaim space
  cnt--;                         // Decrement cnt
  return it;
}

// Move curr one step left; no change if left is empty
void prev() {
  if (curr != head)  // Can't back up from list head
    curr = curr->prev;
}
};

#endif