#include "Main.h"


int main ()
{
	
	
	char arr[100];
	int i =0, j=0;
	Word_ word [5] ;
	
	// input words
	while(j<5)
	{
		i=0;
		
		while( ( arr[i] = _getch() ) != ' ' && arr[i]  != 13)
		{
			printf("%c",arr[i]);
			i++;
		}
		arr[i] = '\0';
		i++;
		printf(" ");
		word[j].setW(i,arr);
		j++;
	}
	
	
	
	Deque deq ;
	
	for(int i = 0; i < 5 ; i++)
	{
		deq.pushB(word[i]);
	}

	// mark elements which are equals
	for(unsigned int i = 0 ; i < deq.Size()-1; i++)
	{
		for(unsigned int j = i + 1 ; j < deq.Size() ; j++)
		{
			if(deq.at(i) == deq.at(j))
			{
				deq.at(i).checked();
				deq.at(j).checked();
			}
		}
	}


	printf("\n");
	deq.deleteChecked();
	
	try
	{
		deq.printDeque();
	}
	catch(Deque::ListIsEmpty)
	{
		printf("List is empty");
	}

	_getch();
	return 0;
}

