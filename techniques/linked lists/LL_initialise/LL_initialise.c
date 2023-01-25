#include <stdio.h>

struct ListNode {
		
    // Linked Lists are sort of artificial;
    // They are structs that contain a pointer to another struct;
    // And so are discontiguous in memory and of an unspecified size.
    int val;
    struct ListNode *next;

    // Below are constructors. They can be used to initialise a struct.
    // I don't know how to use it in C, though. It is OOP; C++.
    // ListNode() : val(0), next(nullptr) {}
    // ListNode(int x) : val(x), next(nullptr) {}
	// ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main(void) {
		
    // We declare a new instance of the sListNode struct, called new_linked_list
    struct ListNode *new_linked_list;
    
    // Give it a value
    new_linked_list->val = 1;

    // Since it is the first node, it is the head and it points to nothing; NULL.
    new_linked_list->next = NULL;
    
    return 0;
}