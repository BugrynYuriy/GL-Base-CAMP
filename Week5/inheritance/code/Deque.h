#pragma once

#ifndef _INC_DEQUE_
#define _INC_DEQUE_

#include "Main.h"


class Deque : private List
{
	
	public :
		
		Deque();
		~Deque();
	
		using List::pushB;
		using List::popB;
		using List::isEmpty;
		using List::clear;
		using List::Size;

		bool pushF(Word_& word);
		Word_& at(unsigned int index); // return element by index
		Word_& popF ();
		void delAt(unsigned int index); // delete element by index
		void printDeque(); // print all elements of deque
		void printChecked(); // printf elements, which are marked
		void deleteChecked(); // delete elements, which are marked
		
		class BadIndex{};
		

};

#endif