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
  int swapped; 
  elem_t *pointerA; 
  elem_t *pointerB = NULL;

  do{
    swapped = 0;
    pointerA = *head; 
    while(pointerA->next != pointerB){
      if(pointerA->value > pointerA->next->value){
        int temp = pointerA->value; 
        pointerA->value = pointerA->next->value; 
        pointerA->next->value = temp; 
        swapped = 1; 
      }
      pointerA = pointerA->next;
    }
    pointerB = pointerA;
  }while(swapped);
}

void swapRef(elem_t **pointer1, elem_t **pointer2){
  elem_t *pointerA = *pointer1; 
  elem_t *pointerB = *pointer2; 

  // if one of the element is null
  if(pointerA == NULL || pointerB == NULL) return;

  // if there is only two elemenets
  if(pointerA->prev == NULL && pointerB->next == NULL){
    pointerB->next = pointerA; 
    pointerA->next = NULL;
    pointerB->prev = NULL; 
    pointerA->next = pointerB; 
  }

  // if there is only three elemenets  
  if(pointerA->prev == NULL && pointerB->next != NULL){
    pointerA->next = pointerB->next;
    pointerB->next = pointerA; 
    pointerA->prev = pointerB;
    pointerB->prev = NULL; 
    pointerB->prev = pointerA;
    return; 
  }

  // if there is 4+ elements
  else{
    pointerA->prev->next = pointerA->next; 
    pointerB->prev = pointerA->prev;

    pointerA->prev = pointerB;
    pointerA->next = pointerB->next;

    pointerB->next->prev = pointerA; 
    pointerB->next = pointerA;
    return;
  }
}

void bubble_sort_copy_ref(elem_t **head) {
  int swapped; 
  elem_t *pointerA; 
  elem_t *pointerB = NULL;

  do{
    swapped = 0;
    pointerA = *head; 
    while(pointerA->next != pointerB){
      if(pointerA->value > pointerA->next->value){
        swapRef(&pointerA, &pointerA->next);
        swapped = 1; 
      }
      pointerA = pointerA->next;
    }
    pointerB = pointerA;
  }while(swapped);
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
    }

    return head;
}


int main() {
    elem_t *head = build_list(4);

    print_list(head);
    printf("==================================\n");
    // bubble_sort_copy_value(&head);
    bubble_sort_copy_ref(&head);
    print_list(head);
}