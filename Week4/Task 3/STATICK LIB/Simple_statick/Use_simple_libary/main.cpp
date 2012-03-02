#include "stdafx.h"
#include <conio.h>

int main ()
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
		push(&mystack,str[i]);

	for(int i=0 ;i<size;i++)
		str[i]=pop(&mystack);
			
	std::cout<<"\nRevers string : ";
	str[size]='\0';
	std::cout<<str;
			
	deleteStack(&mystack);	
	_getch();
	return 0;
}