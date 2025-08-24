//Assignment Create Stack Data structure from scratch

#include<stdio.h>

#define MAX 10

struct Stack {
	int items[10];
	int length;
	int top;
};

void push(struct Stack* s, int value);
void init_stack(struct Stack* s);
int pop(struct Stack* s);
int peek(struct Stack* s);

int main() {
	struct Stack s;

    init_stack(&s);

	for (int i = 0; i < MAX; i++) {
		push(&s, i);
	}

	for (int i = 0; i < s.length; i++) {
		printf("%d\n", s.items[i]);
	}

	push(&s, 11);

	printf("pop operation %d\n", pop(&s));

	printf("top %d\n", s.top);
	printf("length %d\n", s.length);

	return 0;
}

void push(struct Stack* s, int value) {
	if (s->length >= MAX) {
		printf("Stack overflow!\n");
		return;
	}
	s->items[++s->top] = value;
	s->length++;
}

void init_stack(struct Stack* s) {
	s->top = -1;
	s->length = 0;
}

int pop(struct Stack* s) {
	if (s->length <= 0) {
		printf("Stack underflow\n");
		return -1;
	}

	s->length--;
	int popValue = s->items[s->top];
	s->items[s->top--] = 0;

	return popValue;
}

int peek(struct Stack* s) {
	if (s->top >= 0) {
		return s->items[s->top];
	}
	return -1; // or error
}
