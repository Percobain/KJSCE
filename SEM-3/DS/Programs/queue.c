#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int d[MAX];
    int t;
} S;

typedef struct {
    S s1;
    S s2;
} Q;

void initS(S* s) {
    s->t = -1;
}

int isFull(S* s) {
    return s->t == MAX - 1;
}

int isEmpty(S* s) {
    return s->t == -1;
}

void push(S* s, int x) {
    if (!isFull(s)) {
        s->d[++(s->t)] = x;
    } else {
        printf("Stack is full.\n");
    }
}

int pop(S* s) {
    if (!isEmpty(s)) {
        return s->d[(s->t)--];
    }
    printf("Stack is empty.\n");
    return -1;
}

void initQ(Q* q) {
    initS(&q->s1);
    initS(&q->s2);
}

void enq(Q* q, int x) {
    push(&q->s1, x);
}

int deq(Q* q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

void dispQ(Q* q) {
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }

    if (isEmpty(&q->s2)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->s2.t; i >= 0; i--) {
        printf("%d ", q->s2.d[i]);
    }
    printf("\n");
}

int main() {
    Q q;
    initQ(&q);

    enq(&q, 10);
    enq(&q, 20);
    enq(&q, 30);
    dispQ(&q);

    printf("Dequeued: %d\n", deq(&q));
    dispQ(&q);

    enq(&q, 40);
    dispQ(&q);

    printf("Dequeued: %d\n", deq(&q));
    dispQ(&q);

    return 0;
}