#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

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
    // not implemented. Please visit p3V.c 
}

void swapRef(elem_t *pointerA, elem_t *pointerB){
  // printf("%s\n", "STARTED SWAP METHOD");

  // if one of the element is null
  if(pointerA == NULL || pointerB == NULL) return;

  // if there is two elemenets
  else if(pointerA->prev == NULL && pointerB->next == NULL){
    printf("%s\n", "DEBUG1");
    pointerB->next = pointerA; 
    pointerA->next = NULL;
    pointerB->prev = NULL; 
    pointerA->prev = pointerB;
    printf("%s\n", "DEBUG1");
    return ;
  }

  // if the first two elements are being swapped
  else if(pointerA->prev == NULL && pointerB->next != NULL){
    // printf("%s\n", "DEBUG2");
    pointerB->prev = NULL;
    pointerA->next = pointerB->next;
    pointerA->prev = pointerB;
    pointerB->next->prev = pointerA; 
    pointerB->next = pointerA; 
    // printf("%s %d, %d\n", "SWAP DONE BETWEEN: ", pointerA->value, pointerB->value);
    // printf("%s\n", "TESTTEST");
    // printf("%d->%d->%d->%d\n", pointerA->prev->value, pointerA->value, pointerA->next->value, pointerA->next->next->value);
    // printf("%s\n", "DEBUG2");
    return ; 
  }
  
  // if the last two elements are being swapped
  else if(pointerA->prev != NULL && pointerB->next == NULL){
    // printf("%s\n", "DEBUG3");

    // printf("%s\n", "DEBUG3");
    return  ;
  }

  // if the elements being swapped are surrounded by non null nodes. 
  else if(pointerA->prev != NULL && pointerB->next != NULL) {
    // printf("%s\n", "DEBUG4");

    // pointerA->prev->next = pointerB;
    // pointerB->prev = pointerA->prev;

    // pointerA->prev = pointerB;
    // pointerA->next = pointerB->next;

    // pointerB->next = pointerA;
    // pointerA->next->prev = pointerA;
    
    // printf("%d, %d, %d, %d\n", pointerA->prev->value, pointerA->value, pointerA->next->value, pointerA->next->next->value);
    // printf("%s\n", "DEBUG4");
    return ;
  }
  return ;
}

elem_t* swap(elem_t *pointer1, elem_t *pointer2){
    elem_t *temp1 = pointer2->next; 
    elem_t *temp2 = pointer1->prev; 

    pointer2->next = pointer1; 
    pointer1->next = temp1; 
    return pointer2; 
}

// void bubble_sort_copy_ref(elem_t **head) {
//     elem_t ** temp = head;
//     int done;
//     elem_t *p1, *p2, *randomCounter1, *randomCounter2; 
//     randomCounter1 = *head; 
//     randomCounter2 = *head; 
    
//     while(randomCounter1->next != NULL){
//         temp = head; 
//         done = 0;
//         while(randomCounter2->next != NULL){
//             p1 = *temp;
//             p2 = p1->next;
//             if(p1->value > p2->value){
//                 *temp = swap(p1, p2);
//                 done = 1; 
//             }
//             temp = &(*temp)->next;
//         }
//         if(!done) break;
//     }
// }

void bubble_sort_copy_ref(elem_t **head){
    bool swapped;
    elem_t *pointer;
    elem_t *pointer2 = NULL;
    
    if(*head == NULL) return;
    
    do{
        swapped = false;
        pointer = *head;
        
        while(pointer->next != pointer2){
            if(pointer->value > pointer->next->value){
                swapRef(pointer, pointer->next);              
              swapped = true;
            }
            pointer = pointer->next;
        }
        pointer2 = pointer;
    } while(swapped);
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
    elem_t *head = build_list(2);

    print_list(head);
    printf("==================================\n");
    // bubble_sort_copy_value(&head);
    bubble_sort_copy_ref(&head);
    print_list(head);
}