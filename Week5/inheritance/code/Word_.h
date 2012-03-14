#pragma once

#ifndef _INC_WORD_
#define _INC_WORD_

// class that describes the character array which contains no spaces (ie, one word)
class Word_ 
{
	private :

		char * word;
		unsigned int size;
		bool mark;

	public :
 
		Word_(); // default constructor
		Word_( unsigned int size , char* word); // constructor with parameters
		Word_(const Word_& Word); //copy constructor
		~Word_ ();//Destructor
		Word_& operator = (const Word_& Word); // overload assignment operator 
		bool operator == (Word_& Word); // overload comparison operator
		
		// initialize input buffer by character array from Word_ class
		bool getW(int& size , char **word);
		
		// initialize character array from Word_ class by input buffer
		bool setW(int size , char *word);
		
		// checked if a input array is the word (haven't spaces)
		bool isW(unsigned int size , char * word);
		void printW(); // printf word
		
		bool Mark();
		void checked ();
		void unchecked();
		
};

#endif // _INC_WORD_ 