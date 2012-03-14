#include "Main.h"


//---------- default constructor ----------------------

Word_ :: Word_()
{
	word = NULL;
	size = 0;
	mark = false;
}

// ----------------------------------------------------
		
//------------- constructor with parameters -----------

Word_ :: Word_( unsigned int size , char* word)
{
	setW(size,word); // initialize class by char buffer
}

//-----------------------------------------------------
		
//------------copy constructor ------------------------
Word_ :: Word_(const Word_& Word)
{	
	errno_t err;
	
	this->size = Word.size;
	this->mark = Word.mark;
			
	if(Word.size != 0 )
	{
		word = new char [size];

		err = memcpy_s( this->word , this->size , Word.word , size );

		if(err)
		{
			delete []word;
			this->size = 0;
			this->word = NULL;
		}
	}
	
	else
	{
		this->word = NULL;
	}
}

//-----------------------------------------------------
		
// ---------- Destructor ------------------------------

Word_ :: ~Word_ ()
{
	if(word != NULL)
	{
		delete word;
		word = NULL;
	}
}

// -----------------------------------------------------
		

// ----------- overload assignment operator -----------

Word_& Word_ :: operator = (const Word_& Word)
{
	errno_t err;
	
	if( this != &Word)
	{
		if(word != NULL) 
		{
			delete []word;
		}

		this->size = Word.size;
		this->mark = Word.mark;
		word = new char [size];

		err = memcpy_s( this->word , this->size , Word.word , size );

		if(err) // check result of copy process
		{
			delete []word;
			this->size = 0;
			this->word = NULL;
		}

	}
		return *this;
}

// ------------------------------------------------------

// ----------- overload comparison operator------------

bool Word_ :: operator == (Word_& Word)
{
	if( size != Word.size )
	{
		return false;
	}
		
	else
	{
		for( unsigned int i =0 ; i<size ; i++)
			if( word[i] != Word.word[i] )
				return false;
	}
	
	return true;
}

// ------------------------------------------------------
		
// initialize input buffer by character array from Word_ class

bool Word_ :: getW(int& size , char **word)
{
	if(this->size != 0 )
	{
		errno_t err;
		size = this->size;
		
		*word = new char [size];
		err = memcpy_s( *word , this->size , this->word , size );
		
		if(err)
		{
			delete [] word;
			return false;
		}
		
		else
		{
			return true;
		}
	}
	
	else
	{
		size = 0;
		*word = NULL;
		return true;
	}

}

// -------------------------------------------------------------
		
// initialize character array from Word_ class by input buffer
		
bool Word_ :: setW(int size , char *word)
{
	errno_t err;
			
	if(isW(size,word) ==false )
	{
		return false;
	}
			
	if(this->word != NULL)
	{
		delete [] this->word;
	}

	this->size = size;
	this->word = new char [size];
			
	err = memcpy_s(this->word , this->size , word , size );
			
	if(err)
	{
		delete [] word;
		return false;
	}

	else
	{
		return true;
	}
}

// ---------------------------------------------------------------
		
// checked if a input array is the word (haven't spaces)

bool Word_ :: isW(unsigned int size , char * word)
{
	if(size != 0 )
	{
		for( unsigned int i = 0; i < size ; i++ )
		{
			if( word[i] == ' ')
				return false;
		}
	}
	
	else
	{
		return false;
	}

	return true;
}

//-------------------------------------------------------

bool Word_ :: Mark ()
{
	return this->mark;
}

// printf word
void Word_ :: printW()
{
	printf("%s",word);
}
		
void Word_ :: checked ()
{
	mark = true;
}

void Word_ :: unchecked()
{
	mark = false;
}

