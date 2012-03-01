#pragma once


struct STACK ; 

typedef STACK* (*STACKF)(int);
typedef void (*DELETE_STACK)(STACK **stack);
typedef void (*PUSH) (STACK ** stack,char value);
typedef char (*POP)(STACK ** stack);