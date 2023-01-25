#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LEN 23
struct ListNode {
		
    // Linked Lists are sort of artificial;
    // They are structs that contain a pointer to another struct;
    // Data 'boxes' that point to another data box, and so on... like a treasure hunt; 
    // And so are discontiguous in memory and of an unspecified size.
    int val;
    struct ListNode *next;
};

// This traverses the linked list
void print(struct ListNode *head) {
	struct ListNode *current_head = head;
    while (current_head != NULL) {
    
        printf("%d -> ", current_head->val);
        
		// This is the central idea:
		// We move along the current node by accessing the 'next' property each time
		current_head = current_head->next;
    
    }
    
    if (current_head == NULL) printf("X\n");
}

// Create a linked list from an array of strings
struct ListNode *strings_to_list(int len, int num_array[]) {
    struct ListNode *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct ListNode *n = malloc(sizeof (struct ListNode));
        assert(n != NULL);
        n->next = head;
        n->val = num_array[i];
        head = n;
    }
    return head;
}

int main(void) {
		
	// First initialise the Linked List
    int input_arr[MAX_LEN] = {0};
    int total_num = 0;
    int input_num;
    printf("Enter numbers: ");
    while (scanf(" %d", &input_num) == 1) {
        input_arr[total_num] = input_num;
        total_num++;
    }
    struct ListNode *head = strings_to_list(total_num, input_arr);

    print(head);

    return 0;
}