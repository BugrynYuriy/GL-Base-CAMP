#pragma once

#ifndef _STACK_
#define _STACK_

struct STACK ; 

typedef STACK* (*STACKF)(int);
typedef void (*DELETE_STACK)(STACK **stack);
typedef void (*PUSH) (STACK ** stack,char value);
typedef char (*POP)(STACK ** stack);

STACKF createStack;
DELETE_STACK deleteStack;
DELETE_STACK clean;
PUSH pushToStack;
POP popToStack;
POP getTop;
POP isEmpty;

char * getRandomArr(unsigned int size);
bool initStackFromArr(unsigned int size ,char * arr,STACK **stack );
bool initStackFromStack(STACK **stack , STACK **initstack);
bool FillStackAndGetAllElements (int size = -1);

#endif 