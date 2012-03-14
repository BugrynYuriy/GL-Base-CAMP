#include "Main.h"

	
List :: List ()
{
	size = 0;
	begin = NULL;
	current = begin;
}

List :: ~List()
{
	clear();
}

bool List :: pushB (Word_& word)
{
	NODE *add;
			
	if(Size() == 0)
	{
		try
		{
			begin = new NODE(word);
		}

		catch (std::bad_alloc)
		{
			return false;
		}

		current = begin;
		size++;
				
	}

	else
	{
		try
		{
			add = new NODE(word);
		}

		catch (std::bad_alloc)
		{
			return false;
		}

		current->next = add;
		add->prev = current;
		current = add;
		size++;
	}
	
	return true;
}

Word_& List :: popB ()
{
			
	if( isEmpty() )
	{
		throw ListIsEmpty();
	}

	else
	{
		NODE *tmp = begin;
				
		for(unsigned int i =1 ; i <Size()-1 ; i++)
		{
			tmp = tmp->next;
		}

		Word_ &ret = current->value;
		delete current;
		size--;

		if(Size() != 0)
		{
			current = tmp;
			current->next = NULL;
		}
				
		return ret;
	}
}

inline bool List :: isEmpty()
{
	return size == 0;
}

inline unsigned int List :: Size()
{
	return size;
}
		
void List :: clear()
{
	NODE *tmp = begin;
			
	for(unsigned int i =0 ; i <Size() ; i++)
	{
		tmp = tmp->next;
		delete begin;
		begin = tmp;
	}
}
