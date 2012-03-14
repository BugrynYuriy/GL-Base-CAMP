#include "Main.h"
		
Deque :: Deque() : List()
{
}

Deque :: ~Deque()
		{
		
		}
	
bool Deque :: pushF(Word_& word)
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
				
				begin->prev = add;
				add->next = begin;
				begin = add;
				size++;
			}

			return true;
		}

Word_& Deque :: at(unsigned int index)
		{
			if(index >= Size())
			{
				if( isEmpty() )
				{
					throw ListIsEmpty();
				}
				else
				{
					throw BadIndex() ;
				}
			}

			else
			{
				NODE *tmp = begin;
				

				for(unsigned int i =0 ; i <index ; i++)
				{
					tmp = tmp->next;
				}

				return tmp->value;
				
			}
		}

Word_& Deque :: popF ()
		{
			if( isEmpty() )
			{
				throw ListIsEmpty();
			}

			else
			{
				size--;
				NODE *tmp = begin;
				Word_ &res = begin->value;
				
				if(Size() != 1)
				{
					begin=begin->next;
				}
				
				delete tmp;
				return res;
			}
		}

void Deque :: delAt(unsigned int index)
		{
			if(index >= Size())
			{
				if( isEmpty() )
				{
					throw ListIsEmpty();
				}
				else
				{
					throw BadIndex() ;
				}
			}

			else
			{
				NODE *tmp = begin;
				
				if(Size() == 1 )
				{
					popB();
					return;

				}
				
				for(unsigned int i =0 ; i <index ; i++)
				{
					tmp = tmp->next;
					
				}

				if(index == Size()-1 )
				{
					popB();
					return;
				}

				if(index == 0 )
				{
					popF();
					return;
				}
				
				else
				{
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					delete tmp;
					size--;
					return ;
				}
				
			}
		} 

void Deque :: printDeque()
		{
			if(isEmpty())
			{
				throw ListIsEmpty();
			}

			else
			{
				NODE *tmp = begin;
				

				for(unsigned int i =0 ; i <Size() ; i++)
				{
					tmp->value.printW();
					printf(" ");
					tmp = tmp->next;
				}
			}
		}

void Deque :: printChecked()
		{
			if(isEmpty())
			{
				throw ListIsEmpty();
			}

			else
			{
				NODE *tmp = begin;
				

				for(unsigned int i =0 ; i <Size() ; i++)
				{
					if( tmp->value.Mark() == true )
					{
						tmp->value.printW();
						printf(" ");
					}

					tmp = tmp->next;
				}
			}
		}

void Deque :: deleteChecked()
		{
			NODE *tmp = begin;
			NODE * deleted ;
				
			for(unsigned int i =0 ; i <Size() ; i++)
			{
				if( tmp->value.Mark() == true )
				{
					
					if(i != 0 )
					{
						tmp->prev->next = tmp->next;
						if(i != size-1)
						{
							tmp->next->prev = tmp->prev;
						}
						deleted = tmp;
						tmp = tmp->next;
						i--;
						size--;
						delete deleted;
						
					}

					else 
					{
						if(i == 0 )
						{
							if(i != size-1)
							{
								begin = tmp->next;
								begin->prev = NULL;
							}
							deleted = tmp;
							tmp=begin;
							delete deleted;
							size--;
							i--;
						}
					}
				}

				else
				{
					tmp = tmp->next;
				}
			}
		}
		
	
		
