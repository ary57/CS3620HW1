#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct elem {
    int value;
    struct elem *next;
    struct elem *prev;
} elem_t;

void print_list(elem_t *head) {
    elem_t *elem = head;
    while(elem != NULL) {
        printf("%d ", elem->value);
        elem = elem->next;
    }

    printf("\n");
}

void bubble_sort_copy_value(elem_t **head) {
    bool swapped;
    elem_t *pointer;
    elem_t *pointer2 = NULL;
    
    if(*head == NULL) return;
    
    do{
        swapped = false;
        pointer = *head;
        
        while(pointer->next != pointer2){
            if(pointer->value > pointer->next->value){
              int temp = pointer->value;
              pointer->value = pointer->next->value;
              pointer->next->value = temp;                
              swapped = true;
            }
            pointer = pointer->next;
        }
        pointer2 = pointer;
    } while(swapped);
    free(pointer);
    free(pointer2);
}

void bubble_sort_copy_ref(elem_t **head) {
  // not implemented. Please look at p3R.c
}

elem_t *build_list(int num_elements) {
    srand(1234);

    elem_t *head = NULL;
    for (int i = 0; i < num_elements; i++) {
        elem_t *e = (elem_t *) malloc(sizeof(elem_t));
        
        e->value = random() % 100;
        e->next = NULL;
        e->prev = NULL;

        if (head == NULL) {
            head = e;
        } else {
            e->next = head;
            head->prev = e;
            head = e;
        }
        free(e);
    }
    return head;
}


int main() {
    elem_t *head = build_list(100);

    print_list(head);
    printf("==================================\n");
    bubble_sort_copy_value(&head);
    // bubble_sort_copy_ref(&head);
    print_list(head);
}