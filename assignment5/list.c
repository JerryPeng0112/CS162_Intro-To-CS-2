/*********************************************************************
** Program Filename: list.c
** Author: Tsewei Peng
** Date: 05/30/2016
** Description: All the functions to fiddle with doubly linked list
** Input: usually a struct of list, and various integers
** Output: Nothing much, except for some printing
*********************************************************************/
#include "list.h"

/*********************************************************************
** Function: int length
** Description: Return the length of the list
** Parameters: struct list
** Pre-Conditions: A list created
** Post-Conditions: the length of the list returned
*********************************************************************/
int length(struct list a){
    int n;
    struct node* temp = a.head;
    if(temp == NULL) return 0; // if the head is NULL that means its empty
    n = 0;
    while(temp != NULL){
        // if the temp is not NULL, keep moving it through the lsit
        n++;
        temp = temp->next;
    }
    return n;
}

/*********************************************************************
** Function: void print
** Description: print the content of the list
** Parameters: struct list
** Pre-Conditions: A list created
** Post-Conditions: the content of the list printed
*********************************************************************/
void print(struct list a){
    int n;
    struct node* temp = a.head;
    printf("Contents of the list: \n");
    if(temp != NULL){
        n = 0;
        while(temp != NULL){
            // While it is not NULL, make it move through the list
            if(n == 15){
                // Every 15 numbers, will have a new line
                printf("\n");
                n = 0;
            }
            n++;
            printf("%d ", temp->val);
            temp = temp->next;
        }
    }
    printf("\n");
}

/*********************************************************************
** Function: void push_front
** Description: Push a new node to the front (head) with user's value
** Parameters: struct list*, int
** Pre-Conditions: A list created, and a value for the node
** Post-Conditions: The list have a new node in the front
*********************************************************************/
void push_front(struct list* a, int b){
    if(a->head == NULL){
        // If the head is NULL, make head and tail point to the new node
        a->head = (struct node *) malloc (sizeof(struct node));
        a->tail = a->head;
        a->tail->val = b;
        a->head->prev = a->head->next = NULL;
    }else{
        // Make the head's prev point to the new node
        a->head->prev = (struct node *) malloc (sizeof(struct node));
        a->head->prev->next = a->head;
        a->head = a->head->prev;
        a->head->val = b;
        a->head->prev = NULL;
    }
}

/*********************************************************************
** Function: void push_back
** Description: Push a new node in the back (tail) with user's value
** Parameters: struct list*, int
** Pre-Conditions: a list created, and a value for the node
** Post-Conditions: The list have a new node in the back
*********************************************************************/
void push_back(struct list* a, int b){
    if(a->tail == NULL){
        // If the tail is NULL, make head and tail point to the new node
        a->head = (struct node *) malloc (sizeof(struct node));
        a->tail = a->head;
        a->head->val = b;
        a->head->prev = a->head->next = NULL;
    }else{
        // Make the tail's next point to the new node
        a->tail->next = (struct node *) malloc (sizeof(struct node));
        a->tail->next->prev = a->tail;
        a->tail = a->tail->next;
        a->tail->val = b;
        a->tail->next = NULL;
    }
}

/*********************************************************************
** Function: void clear
** Description: Free all the nodes in the list
** Parameters: struct list*
** Pre-Conditions: A list created
** Post-Conditions: Free all memory, and set head and tail to NULL
*********************************************************************/
void clear(struct list* a){
    // Run throught the list and delete its prev until end of list
    if(a->head == NULL) return;
    struct node* temp = a->head;
    while(temp != a->tail){
        temp = temp->next;
        free(temp->prev);
    }
    // delete tail
    free(a->tail);
    a->head = a->tail = NULL;
    printf("List cleared !\n");
}

/*********************************************************************
** Function: void remove_val
** Description: Remove all nodes with user's value from the list
** Parameters: struct list*, int
** Pre-Conditions: A list created, an integer to remove nodes
** Post-Conditions: All the nodes with the specified value freed and cleared
*********************************************************************/
void remove_val(struct list* a, int b){
    // If the list empty, return
    if(a->head == NULL) return;
    // If the list has only one item, and it has the value, free it and set head and tail to NULL
    if(a->head == a->tail){
        if(a->head->val == b){
            free(a->head);
            a->head = NULL;
            a->tail = NULL;
        }
        return;
    }
    struct node* temp = a->head;
    // Run the temp through the list
    while(temp != NULL){
        if(temp->val == b){

            if(temp->prev != NULL){
                // If it is not the head
                temp->prev->next = temp->next;
            }else{
                // If it is the head, point the head to next node
                a->head = temp->next;
            }
            if(temp->next != NULL){
                // If it is not the tail
                temp->next->prev = temp->prev;
            }else{
                // If it is the tail, point the tail to prev node
                a->tail = temp->prev;
            }
            free(temp);
        }
        temp = temp->next;
    }
}

/*********************************************************************
** Function: void sort_ascending
** Description: Sort the nodes by ascending value
** Parameters: struct list*
** Pre-Conditions: A list created
** Post-Conditions: All the nodes are sorted in ascending order
*********************************************************************/
void sort_ascending(struct list* a){
    // If the list empty, return
    if(a->head == NULL) return;
    struct node* temp1 = a->head;
    struct node* temp2 = a->head->next;
    int temp;
    // Run through the 2 temp node, and if value is not satisfied, switch the value
    while(temp1->next != NULL){
        while(temp2 != NULL){
            if(temp1->val > temp2->val){
                temp = temp1->val;
                temp1->val = temp2->val;
                temp2->val = temp;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        temp2 = temp1->next;
    }
}

/*********************************************************************
** Function: void sort_descending
** Description: Sort all the nodes by descending order
** Parameters: struct list*
** Pre-Conditions: A list created
** Post-Conditions: All the nodes are sorted in descending order
*********************************************************************/
void sort_descending(struct list* a){
    // If the list empty, return
    if(a->head == NULL) return;
    struct node* temp1 = a->head;
    struct node* temp2 = a->head->next;
    int temp;
    // Run through the 2 temp node, and if value is not satisfied, switch the value
    while(temp1->next != NULL){
        while(temp2 != NULL){
            if(temp1->val < temp2->val){
                temp = temp1->val;
                temp1->val = temp2->val;
                temp2->val = temp;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        temp2 = temp1->next;
    }
}

/*********************************************************************
** Function: void insert
** Description: Insert a node with specified value to specified location
** Parameters: struct list*, int, int
** Pre-Conditions: A list created, int values for value and location
** Post-Conditions: A value is inserted to the list to the specific location
*********************************************************************/
void insert(struct list* a, int b, int loc){
    // Get the length of the list
    int n = length(*a);
    int i;
    struct node* point = a->head;
    struct node* temp;
    // If the location out of bound, reject it
    if(loc > n){
        printf("Location out of bound\n");
        return;
    }
    // If list empty
    if(n == 0){
        push_back(a, b);
        return;
    }
    // allocate the temp node
    temp = (struct node*) malloc (sizeof(struct node));
    temp->val = b;
    // If the temp node is to be inserted in the middle
    if(loc > 0 && loc < n){
        for(i = 1; i < loc; i++){
            point = point->next;
        }
        temp->next = point->next;
        temp->prev = point;
        point->next->prev = temp;
        point->next = temp;
    }
    // If the temp node is to be inserted at the beginning
    if(loc == 0){
        temp->next = a->head;
        a->head->prev = temp;
        temp->prev = NULL;
        a->head = temp;
    }
    // If the temp node is to be inserted at the end
    if(loc == n){
        temp->prev = a->tail;
        a->tail->next = temp;
        temp->next = NULL;
        a->tail = temp;
    }
}
