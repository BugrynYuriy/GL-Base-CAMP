// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <iostream>



// TODO: reference additional headers your program requires here

#define DllExport __declspec( dllexport)

extern "C"
{
	// structure that describes the limited stack
	struct DllExport STACK
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
	
	DllExport STACK * createStack(unsigned int size); // return pointer to struct type STACK
	DllExport void deleteStack(STACK ** stack);  // call destructor of struct type STACK
	DllExport void push(STACK ** stack,char value); // add element to STACK
	DllExport void clean(STACK ** stack); // clean the STACK
	DllExport char getTop(STACK ** stack); // return top of STACK
	DllExport char pop(STACK ** stack); // return top of STACK and delete it 
	DllExport int isEmpty(STACK ** stack); // return 1 if STACK is empty else return 0

}

