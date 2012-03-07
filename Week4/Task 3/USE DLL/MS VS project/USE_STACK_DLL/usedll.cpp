#include <iostream>
#include <windows.h> 
#include <conio.h>
#include "STACK.h"
#include <time.h>



bool initFunctions ( HINSTANCE *dll , LPCWSTR libary)
{
	*dll = LoadLibrary ( libary );

	if (*dll ) 
	{
		(FARPROC&) createStack = GetProcAddress( *dll, LPCSTR("createStack") );
		(FARPROC&) deleteStack = GetProcAddress( *dll, LPCSTR("deleteStack") );
		(FARPROC&) clean = GetProcAddress( *dll, LPCSTR("clean") );
		(FARPROC&) pushToStack = GetProcAddress( *dll, LPCSTR("push") );
		(FARPROC&) popToStack = GetProcAddress( *dll, LPCSTR("pop") );
		(FARPROC&) getTop = GetProcAddress( *dll, LPCSTR("getTop") );
		(FARPROC&) isEmpty = GetProcAddress( *dll, LPCSTR("isEmpty"));

		return 1;
	}

	else

		return 0;
}


int main ()
{
	
	HINSTANCE mydll; 
	
	if( initFunctions ( &mydll , TEXT ( "STACK_DLL" ) ) )
	{
		
		FillStackAndGetAllElements(-2);
		
		
		if( createStack )
		{
			STACK *mystack = NULL;
			
			char str [100];
			int size , i=0;

			std::cout<< "\n\nEnter string (Q - end): ";
			
			while( ( str [i] = _getch() ) != 'Q')
			{
				std::cout<<str[i];
				i++;
			}
			
			size = i;
			mystack = createStack ( size ) ;
			
			for( int i=0 ; i < size ; i++ )
				pushToStack ( &mystack , str[i] );

			for( int i=0 ; i < size ; i++ )
				str[i] = popToStack ( &mystack );
			
			std::cout<< "\nRevers string : ";
			str[size] = '\0';
			std::cout<< str;
			
			deleteStack ( &mystack );				
		}
		
		else
		{
			std::cout<<"Can't get of function - createStack";
		}
	}

	else

		std::cout<<"Can't load of DLL";

	
	_getch();
	FreeLibrary ( mydll );
	return 0;
}

char * getRandomArr(unsigned int size)
{
	char *initarr ;

	try
	{
		initarr = new char [size];
	}

	catch(std::bad_alloc)
	
	{
		return NULL;
	}

	for(unsigned int i = 0 ; i < size ; i++)
		initarr[i] = rand ()%100;

	return initarr;
}

bool initStackFromArr(unsigned int size ,char * arr,STACK **stack )
{
	for(unsigned int i = 0 ;i < size ; i++)
	{
		try
		{
			pushToStack(stack,arr[i]);
		}

		catch(...)
		{
			if(size != 0)
				return false;
			else
				return true;
		}
	}

	return true;
}

bool initStackFromStack(STACK **stack , STACK **initstack)
{
	
	do
	{
		try
		{
			
			pushToStack(stack, popToStack(initstack));
		}

		catch (...)
		{
			if(!isEmpty(initstack))
				return false;
			else 
				return true;
		}
	}
	while (!isEmpty(initstack));
	return true;
}

bool FillStackAndGetAllElements (int size)
{
	srand ( time(NULL) ); // initialize random seed

	if(size < 0)
		size = rand() %100;
	

	char *initarr = getRandomArr(size);
	
	STACK *mystack = NULL , *mystackTest = NULL;

	mystack = createStack(size);
	mystackTest = createStack(size);

	if( !(initStackFromArr((unsigned)size,initarr,&mystack) && initStackFromStack(&mystackTest,&mystack)) )
	{
		std::cout<<"\nInit stack test failed with size = "<<size;

		delete [] initarr;
		deleteStack(&mystack);
		deleteStack(&mystackTest);
		return false;
	}
	
	std::cout<<"\nInit stack test passed with size = "<<size;
	for(unsigned int i = 0; i<(unsigned)size; i++)
		if( initarr[i] != popToStack(&mystackTest) )
		{
			std::cout<<"\nFill and get test failed with size = "<<size;
			delete [] initarr;
			deleteStack(&mystack);
			deleteStack(&mystackTest);
			return false;
		}

	std::cout<<"\nFill and get test passed with size = "<<size;
	delete [] initarr;
	deleteStack(&mystack);
	deleteStack(&mystackTest);
	return true;
}