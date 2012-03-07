// STACK_DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"


STACK * createStack(unsigned int size)
{
	
	STACK *stack;

	try
	{
		stack = new STACK();
	}

	catch( std::bad_alloc &e )
		{
			std::cout<<"Can't allocate memory for stack";
			return NULL;
		}
	
	if( size != 0 )
	{
		try
		{
			stack->stack = new char [size];
		}
		
		catch( std::bad_alloc &e )
		{
			std::cout<<"Can't allocate memory for elemnts of stack";
			return stack;
		}
	}
	
	stack->size = size;
	return stack;
}

void deleteStack(STACK ** stack)
{	
	
	if( *stack != NULL )
	{
	
		delete *stack;

	}
	
	
}

void push( STACK ** stack , char value )
{
	
	
	if( *stack != NULL )
	{ 
		if( ( *stack )->stack == NULL || ( *stack )->top+1>( *stack )->size )
		{
			return;
		}	
		
		else
		{
			( *stack )->stack[ ( *stack )->top ] = value;
			( *stack )-> top++;
				
			return ;
		}
	}

}

char getTop(STACK ** stack)
{
	int top;
	
	if( ( *stack )->size == 0 || isEmpty( stack ) )
	{
		throw "\nStak is empty";
	}

	else
	{
		top = ( *stack )->top-1;
		
		if( top < 0 )
			top = 0;
		
		return ( *stack )->stack[ top ];

	}
}

char pop( STACK ** stack )
{

	if( *stack != NULL ){
		if( ( *stack )->stack == NULL || isEmpty( stack ) )
			throw "\nstack is empty";
		
		else
			{
				
				(*stack)-> top--;

				if((*stack)-> top<0)
					(*stack)-> top = 0;

				return (*stack)->stack[(*stack)->top];
			}
	}
}

int isEmpty(STACK ** stack)
{
	if( (*stack) -> top == 0)
		
		return 1;
	
	else
		
		return 0;
}

void clean(STACK ** stack)
{
	(*stack)->top = 0;
}

