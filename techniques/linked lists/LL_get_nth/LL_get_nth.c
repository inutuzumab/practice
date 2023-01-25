#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 15
#define N 2

typedef struct node {
    int val;
    struct node *next;
}node;

// I can't figure out how to parametise this, so we'll set to 2;
// Get the node 1/2 way through the LL.
int get_nth(int n, struct node *head) {

    // The idea here is that we have an extra pointer;
    // Fast travels n times faster than slow (normal 1-by-1 iteration speed);
    // When fast gets to the end, then slow will only be 1/n-way through the LL;
		// So this extra pointer is like an indicator, that is calibrated to get us to 1/n-way.
    if (!(head->next) | !(head->next->next)) return -1;
    struct node *fast = head;
    struct node *slow = head;

    // If it is even, then 'fast' will end on null; and if even, on the last node
    // Moderate this for each 1/n.
    while (fast && fast->next) {
        // fast and slow speed;
        slow = slow->next;
        fast = fast->next->next;
    }
    // We want the lower of the middle ones if it is even.
    int return_val = n % 2 != 0 ? slow->val : slow->val - 1;
    return return_val;

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

int main(void) {
    struct node *head = initialise();
    int val = get_nth(LIST_SIZE, head);
    printf("1/%d way through the list is: %d.\n", N, val);
    return 0;
}