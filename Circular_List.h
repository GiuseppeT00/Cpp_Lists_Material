// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// This is the file to include in your code if you want access to the
// complete CList template class

#ifndef CLIST_H
#define CLIST_H

#include <string>
using namespace std;

// First, get the declaration for the base list class
#include "list.h"

// Include linked node implementation
#include "link.h"

inline void Assert(bool val, string s);

// This is the declaration for CList. 
template <typename E> class CList: public List<E> {
private:
  Link<E>* head;       // Pointer to list header
  Link<E>* tail;       // Pointer to list tailer
  Link<E>* curr;       // Pointer ahead of current element
  int cnt;             // Size of list

  void init() {        // Intialization helper method
	head = tail = curr = new Link<E>; // Create header
	head->next = head;
    cnt = 0;
  }

 void removeall() {   // Return link nodes to free store
	  while (head->next != head) { // Return to free
		  curr = head->next; // (keep header)
		  head->next = curr->next;
		  delete curr;
	  }
	  delete head;
  }

public:
  CList() { init(); } // Constructor
  
  ~CList() { removeall(); }  // Destructor    // Destructor
  void clear() { removeall(); init(); }       // Clear list

  void moveToStart() // Place curr at list start
    { curr = head; }

  void moveToEnd()   // Place curr at list end
    { curr = tail; }

  int length() const  { return cnt; }

  // Return the position of the current element
  int currPos() const {
    Link<E>* temp = head;
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
	Assert(curr->next != NULL, "No value"); 
    return curr->next->element;
  }

 // Remove and return current element
 E remove() {
	 Assert(curr->next != head, "remove head");
	 E it = curr->next->element;      // Remember value
	 Link<E>* ltemp = curr->next;     // Remember link node
	 if (tail == curr->next) tail = curr; // Reset tail
	 curr->next = curr->next->next;   // Remove from list
	 delete ltemp;                    // Reclaim space
	 cnt--;			     // Decrement the count
	 return it;
 }



 // Insert Element at current position
 void insert(const E& item) {
	Assert(curr != NULL, "curr is NULL"); // Must be pointing to Element
	curr->next = new Link<E>(item, curr->next);
	if (tail->next != head) tail = tail->next;
	cnt++;
 } 
 

 void append(const E& item)
 { 
	tail = tail->next = new Link<E>(item, head);
	cnt++;
 }

 // Move curr to next position
 void next()
 { 
	curr = curr->next;
 }

 // Move curr to prev position
 void prev() {
	Link<E>* temp = curr;
	while (temp->next != curr) temp = temp->next;
	curr = temp;
 }
};

#endif