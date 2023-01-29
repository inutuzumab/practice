#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 15
#define N 2

typedef struct node {
    int val;
    struct node *next;
}node;

struct node* reverse_list(struct node *head) {
        
    struct node *curr = head;
    struct node *prev = NULL;
    while (curr) {
        
        // Store the next node
        struct node* temp = curr->next;
        
        // Reverses the current node to point to the previous node (first one = null)
        curr->next = prev;
        
        // Sets the previous node to be the current node, to use next iteration
        prev = curr;
        
        // Moves current node along
        curr = temp;
    }
    // Since curr ends on NULL, we want the one before NULL (the old tail); prev.
    return prev;
}

struct node* initialise() {
    struct node *head = NULL;
    for (int i = 0; i < LIST_SIZE; i++) {
        struct node *n = malloc(sizeof (struct node));
        n->val = LIST_SIZE - i;
        n->next = head;
        head = n;
    }
    return head;
}

// This traverses the linked list
void print(struct node *head) {
    struct node *current_head = head;
    while (current_head != NULL) {
    
        printf("%d -> ", current_head->val);
        
	// This is the central idea:
	// We move along the current node by accessing the next property each time
	current_head = current_head->next;
    
    }
    
    if (current_head == NULL) printf("X\n");
}

int main(void) {
    struct node *head = initialise();
    printf("Not reversed: ");
    print(head);
    printf("Reversed: ");
    head = reverse_list(head);
    print(head);
    return 0;
}
