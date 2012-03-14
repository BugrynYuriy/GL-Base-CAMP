#pragma once

#ifndef _INC_LIST_
#define _INC_LIST_

#include "Main.h"

class List
{
    protected:
	
		NODE *begin;
		NODE *current;
		unsigned int size;

	public :
	
		List ();
		~List();

		bool pushB (Word_& word);
		Word_& popB ();
		inline bool isEmpty();
		inline unsigned int Size();
		void clear(); // clear the list
		
		class ListIsEmpty {}; // exception class

};

#endif