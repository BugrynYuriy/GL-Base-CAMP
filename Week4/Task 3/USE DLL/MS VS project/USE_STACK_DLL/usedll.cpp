#include <iostream>
#include <windows.h> 
#include <conio.h>
#include "STACK.h"
#include <time.h>


//----------- load libary and download functions from libary --------------------------- //

bool initFunctions ( HINSTANCE *dll , LPCWSTR libary)
{
	// Loads the specified module into the address space of the calling process.
	*dll = LoadLibrary ( libary ); 

	if (*dll ) 
	{
		// -------------- download functions from library ------------------------------ //
			
			(FARPROC&) createStack = GetProcAddress( *dll, LPCSTR("createStack") );
			(FARPROC&) deleteStack = GetProcAddress( *dll, LPCSTR("deleteStack") );
			(FARPROC&) clean = GetProcAddress( *dll, LPCSTR("clean") );
			(FARPROC&) pushToStack = GetProcAddress( *dll, LPCSTR("push") );
			(FARPROC&) popToStack = GetProcAddress( *dll, LPCSTR("pop") );
			(FARPROC&) getTop = GetProcAddress( *dll, LPCSTR("getTop") );
			(FARPROC&) isEmpty = GetProcAddress( *dll, LPCSTR("isEmpty"));

		// ---------------------------------------------------------------------------- //
		
		// checking whether all the functions from the library were downloaded
		if( !( createStack && deleteStack && clean && pushToStack && popToStack && getTop && isEmpty ) )
		{
			return 0;
		}
		
		else
		{
			return 1;
		}
	}

	else

		return 0;
}

//--------------------------------------------------------------------------------------- //


int main ()
{
	
	HINSTANCE mydll; 
	
	// load library and check result of downloading
	
	if( initFunctions ( &mydll , TEXT ( "STACK_DLL" ) ) )
	{
		
		FillStackAndGetAllElements(); // use some unit test
		
		STACK *mystack = NULL; // pointer to struct ,  as described in dll
		
		char str [100];
		int size , i = 0;

			std::cout<< "\n\nEnter string (Q - end): ";
			
			//read characters , while they don't equal Q  //
			while( ( str [i] = _getch() ) != 'Q') 
			{
				std::cout<<str[i];
				i++;
			}
			
			size = i;
			
			// create stack and check result
			if( ( mystack = createStack ( size ) ) == NULL )
			{
				std::cout<<"\nCan't create stack ";
				_getch();
				return 0;
			}
			
			// fill stack by elements from characters array
			for( int i=0 ; i < size ; i++ )
			{
				try
				{
					pushToStack ( &mystack , str[i] );
				}

				catch(const char *exception )
				{
					std::cout<<exception;
					_getch();
					return 0;
				}
			}

			// reverse  of character array
			for( int i=0 ; i < size ; i++ )
			{
				try
				{
					// fill character array by elements from stack
					str[i] = popToStack ( &mystack );
				}

				catch(const char *exception )
				{
					std::cout<<exception;
					_getch();
					return 0;
				}
			}
			
			std::cout<< "\nRevers string : ";
			str[size] = '\0';
			std::cout<< str;
			
			// Deallocate memory
			deleteStack ( &mystack );				
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
	{
		initarr[i] = rand ()%100;
	}

	return initarr;
}

bool initStackFromArr(unsigned int size ,char * arr,STACK **stack )
{
	for(unsigned int i = 0 ;i < size ; i++ )
	{
		try
		{
			pushToStack( stack , arr[i] );
		}

		catch(...)
		{
			if( size != 0 )
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
			
			pushToStack( stack, popToStack ( initstack ) );
		}

		catch (...)
		{
			if( !isEmpty ( initstack ) )
				return false;
			else 
				return true;
		}
	}
	while ( !isEmpty ( initstack ) );
	return true;
}

bool FillStackAndGetAllElements (int size)
{
	srand ( time( NULL ) ); // initialize random seed

	if( size < 0 )
		size = rand() %100;
	

	char *initarr = getRandomArr( size );
	
	STACK *mystack = NULL , *mystackTest = NULL;

	mystack = createStack( size );
	mystackTest = createStack( size );

	if( !( initStackFromArr( (unsigned)size, initarr, &mystack ) && initStackFromStack( &mystackTest, &mystack ) ) )
	{
		std::cout<<"\nInit stack test failed with size = "<<size;

		delete [] initarr;
		deleteStack( &mystack );
		deleteStack( &mystackTest );
		return false;
	}
	
	std::cout<<"\nInit stack test passed with size = "<<size;
	
	for( unsigned int i = 0; i < (unsigned) size; i++)
	{
		if( initarr[i] != popToStack ( &mystackTest ) )
		{
			std::cout<<"\nFill and get test failed with size = "<<size;
			delete [] initarr;
			deleteStack( &mystack );
			deleteStack( &mystackTest );
			return false;
		}
	}

	std::cout<<"\nFill and get test passed with size = "<<size;
	delete [] initarr;
	deleteStack( &mystack );
	deleteStack( &mystackTest );
	return true;
}