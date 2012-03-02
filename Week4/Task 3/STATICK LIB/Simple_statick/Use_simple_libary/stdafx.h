// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once


#include <iostream>
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

struct STACK
	{
		char * stack; // pointer to array of elements
		int size; // size of stack
		int top; // top of the stack
		
		STACK()
		{
			size=0;
			stack=NULL;
			top=0;
		}
		
		~STACK()
		{
			if(stack!=NULL)
				delete [] stack;

		}

		
	};
	
	extern STACK * createStack(unsigned int size); // return pointer to struct type STACK
	extern void deleteStack(STACK ** stack);  // call destructor of struct type STACK
	extern void push(STACK ** stack,char value); // add element to STACK
	extern void clean(STACK ** stack); // clean the STACK
	extern char getTop(STACK ** stack); // return top of STACK
	extern char pop(STACK ** stack); // return top of STACK and delete it 
	extern int isEmpty(STACK ** stack); // return 1 if STACK is empty else return 0

// TODO: reference additional headers your program requires here
