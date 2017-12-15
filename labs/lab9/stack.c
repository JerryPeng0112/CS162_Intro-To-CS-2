#include <stdio.h>  // printf, scanf
#include <stdlib.h> // malloc, free, NULL

struct node {
	int val;
	struct node *next;
};

struct stack {
	struct node *head;
	struct node *tail;
};

void init(struct stack*); //initialize stack members
void push(struct stack*, int); //grow contents to store int
int pop(struct stack*); //shrink contents and return top int

int main()
{
	struct stack s;
	int inp;
	init(&s);
	printf("ooga booga\n");
	printf("Enter a number to push: ");
	scanf("%i", &inp);
	push(&s, inp);
	push(&s, 666);
	push(&s, 777);
	printf("%i\n", pop(&s));
	printf("%i\n", pop(&s));
	printf("%i\n", pop(&s));
	printf("%i\n", pop(&s));
	return 0;
}

void init(struct stack* s)
{
	s->tail = NULL;
	s->head = NULL;
	s->tail = s->head;
}

void push(struct stack* s, int v)
{
	if(s->head == NULL){
		s->head = (struct node*) malloc(sizeof(struct node));
		s->head->val = v;
		s->tail = s->head;
	}
	else{
		s->tail->next = (struct node*) malloc(sizeof(struct node));
		s->tail = s->tail->next;
		s->tail->val = v;
		s->tail->next = NULL;
	}
}

int pop(struct stack* s)
{
	if (s->head->next == NULL) {
		if(!s->head->val){
			printf("No more items to pop!\n");
		}
		int oldval = s->head->val;
		s->head->val = 0;
		return oldval;
	}
	int val = s->tail->val;
	free(s->tail);
	struct node* newtail = s->head;
	while (newtail->next != s->tail) {
		newtail = newtail->next;
	}
	s->tail = newtail;
	s->tail->next = NULL;
	return val;
}