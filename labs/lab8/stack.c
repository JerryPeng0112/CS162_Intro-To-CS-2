#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *contents; //dynamic array of ints
    int top; //stores the top of the stack
};

void init(struct stack *); //initialize stack members
void push(struct stack *, int); //grow contents to store int
int pop(struct stack *); //shrink contents and return top int
int peek(struct stack); //Returns the top element in the stack
void destroy(struct stack *); //destroy all elements in stack
int empty(struct stack); //return true if the stack is empty
int size(struct stack); //return the number of elements in stack

void init(struct stack * a){
    a->contents = (int *) malloc (1);
    a->contents[0] = 0;
    a->top = 1;
}

void push(struct stack * a, int b){
    int *temp = (int*) malloc (a->top + 1);
    int i;
    for(i = 0; i < a->top; i++){
        temp[i] = a->contents[i];
    }
    free (a->contents);
    a->contents = temp;
    temp[a->top] = b;
    a->top++;
}

int pop(struct stack * a){
    if(!empty(*a)){
        int b = a->contents[a->top-1];
        int *temp = (int *) malloc (a->top - 1);
        int i;
        for(i = 0; i < a->top - 1; i++){
            temp[i] = a->contents[i];
        }
        free (a->contents);
        a->contents = temp;
        a->top--;
        return b;
    }else{
        printf("The array is empty \n");
        return 0;
    }
}

int peek(struct stack a){
    return a.contents[a.top - 1];
}

void destroy (struct stack * a){
    free (a->contents);
    a->top = 0;
}

int empty(struct stack a){
    if(!(a.top)){
        return 1;
    }
    return 0;
}

int size(struct stack a){
    return a.top;
}

int main(){
    struct stack s;
    int choice;
    int put;

    init(&s);
    while(1){
        printf("Would you like to put on (1), take off (2) peek (3), or exit (0)?: ");
        scanf("%i", &choice);
        if(choice == 1){
            printf("Enter the integer you'd like to put on: ");
            scanf("%i", &put);
            push(&s, put);
        }else if(choice == 2){
            printf("You popped: ");
            printf("%i \n", pop(&s));
        }else if(choice == 3){
            printf("You peek: ");
            printf("%i \n", peek(s));
        }else{
            break;
        }
        printf("Current stack:\n");
        int i;
        for(i = 0; i < s.top; ++i){
            printf("%i ", s.contents[i]);
        }
        printf("\n");
    }
    destroy(&s);
    return 0;
}
