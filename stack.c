#include <string.h>
#include <stdio.h>
#include "stack.h"

#define STACK_SIZE 50
char _stack[STACK_SIZE];
int _idx;

void stack_init(void)
{
    memset(_stack, 0, sizeof(_stack));
    _idx = 0;
}

void stack_push(char c) {
    _stack[_idx++] = c;
}

char stack_pop(void) {
    return _stack[--_idx];
}

char stack_peek(void) { return 0; }