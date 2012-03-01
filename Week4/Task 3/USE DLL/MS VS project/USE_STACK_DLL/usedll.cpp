#include <iostream>
#include <windows.h> 
#include <conio.h>
#include "STACK.h"



int main ()
{
	STACKF createStack;
	DELETE_STACK deleteStack;
	DELETE_STACK clean;
	PUSH pushToStack;
	POP popToStack;
	POP getTop;
	POP isEmpty;
	
	HINSTANCE mydll;
	//mydll = LoadLibrary(TEXT("C:/Users/yura/Documents/Visual Studio 2010/Projects/STACK_DLL/Release/STACK_DLL")); 
	mydll = LoadLibrary(TEXT("STACK_DLL"));
	if (mydll ) 
	{
		std::cout<<"Dynamic library:\n";
		(FARPROC&)createStack = GetProcAddress(mydll, LPCSTR("createStack"));
		(FARPROC&)deleteStack = GetProcAddress(mydll, LPCSTR("deleteStack"));
		(FARPROC&)clean = GetProcAddress(mydll, LPCSTR("clean"));
		(FARPROC&)pushToStack = GetProcAddress(mydll, LPCSTR("push"));
		(FARPROC&)popToStack = GetProcAddress(mydll, LPCSTR("pop"));
		(FARPROC&)getTop = GetProcAddress(mydll, LPCSTR("getTop"));
		(FARPROC&)isEmpty = GetProcAddress(mydll, LPCSTR("isEmpty"));
		
		
		
		if(createStack)
		{
			STACK *mystack=NULL;
			
			char str [100];
			int size,i=0;

			std::cout<<"\nEnter string (Q - end): ";
			while((str[i]=_getch())!='Q')
			{
				std::cout<<str[i];
				i++;
			}
			
			size = i;
			mystack = createStack(size);
			
			for(int i=0 ;i<size;i++)
				pushToStack(&mystack,str[i]);

			for(int i=0 ;i<size;i++)
				str[i]=popToStack(&mystack);
			
			std::cout<<"\nRevers string : ";
			str[size]='\0';
			std::cout<<str;
			
			deleteStack(&mystack);				
		}
		
		else
		{
			std::cout<<"Can't get of function - createStack";
		}
	}

	else

		std::cout<<"Can't load of DLL";

	
	_getch();
	FreeLibrary(mydll);
	return 0;
}