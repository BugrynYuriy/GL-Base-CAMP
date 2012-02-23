#include <iostream>
#include <conio.h>


struct Book // структура для опису книги
{
	char author [20];
	char note [20];
	int year;
	char name [20];
};

int CMP1 (char one[20] , char two[20]) // функція для лексичног порівняння слів
{
	int i=0;
	
	while (two[i]!='\0')
		
		{
			if(two[i]<one[i])
				return 1; // перше слово більше
			if(two[i]>one[i])
				return 0; // друге слово більше
			i++;
		}

	return 0;
}

int main1(){

Book *libary,tmp; // вказівник на масив книжок
	int size; // розмір масиву структур

	std::cout<<"Enter size of libary : ";
	std::cin>>size;

	libary = (Book *) malloc(sizeof(Book)*size); // виділення памяті для масиву структур

	
	// ввід даних
	for(register int i=0;i<size;i++)
	{
		std::cout<<"Enter name of author :";
		std::cin>>libary[i].author;
		std::cout<<"Enter note :";
		std::cin>>libary[i].note;
		std::cout<<"Enter year of book :";
		std::cin>>libary[i].year;
		std::cout<<"Enter name of book :";
		std::cin>>libary[i].name;
	}

	
	// сортування структур
	for(int i=0;i<size-1;i++)
		for(int j=i+1;j<size;j++)
			if(CMP1(libary[i].author,libary[j].author))
			{
				tmp = libary[i];
				libary[i]=libary[j];
				libary[j]=tmp;
			}

	std::cout<<"\nLibary after sorting :\n";
	
	// вивід даних
	for(register int i=0;i<size;i++)
	{
		std::cout<<"Author :"<<libary[i].author<<" NOTE : "<<libary[i].note<<" Year : "<<libary[i].year
			<<" NAME : "<<libary[i].name<<"\n";
	}

	std::cout<<"\n1970 :\n";
	
	// вивід даних
	for(register int i=0;i<size;i++)
	{
		if(libary[i].year==1970)
		std::cout<<"Author :"<<libary[i].author<<" NOTE : "<<libary[i].note<<" Year : "<<libary[i].year
			<<" NAME : "<<libary[i].name<<"\n";
	}

	// очищення виділеної памяті
	free(libary);
	_getch();
	return 0;
}