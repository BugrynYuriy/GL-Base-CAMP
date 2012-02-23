#include <iostream>
#include <conio.h>
#include <string.h>


struct STUDENT // структура для опису студента
{
	char last_name [20];
	char sex[6];
	int year;
	double height;
	double weight;
};

int CMP (char one[20] , char two[20]) // функція для лексичног порівняння слів
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

int main13 ()
{
	STUDENT *students,tmp; // вказівник на масив структур
	int size,male=0,fmale=0;
	double s_male_h=(double)0,s_male_w=(double)0,s_fmale_h=(double)0,s_fmale_w=(double)0;

	std::cout<<"Enter count of students :";
	std::cin>>size; // розмірність масиву

	students=(STUDENT *) malloc(sizeof(STUDENT)*size); // виідлення памяті

	for(int i=0;i<size;i++) // ввід даних
	{
		std::cout<<"Enter last name : ";
		std::cin>>students[i].last_name;
		std::cout<<"Enter sex : ";
		std::cin>>students[i].sex;
		std::cout<<"Enter year : ";
		std::cin>>students[i].year;
		std::cout<<"Enter height : ";
		std::cin>>students[i].height;
		std::cout<<"Enter weight : ";
		std::cin>>students[i].weight;
		
		if(!strcmp(students[i].sex,"male")) // перевірка на стать
		{
			s_male_h+=students[i].height; // підрахунок параметрів чоловіків
			s_male_w+=students[i].weight;
			male++;
		}

		else 
		{
			s_fmale_h+=students[i].height; // підрахунок параметрів жінок
			s_fmale_w+=students[i].weight;
			fmale++;
		}
		
	}


	for(int i=0;i<size-1;i++) // сортування в абетвокому порядку

		for(int j=i+1;j<size;j++)
		{
			if(CMP(students[i].last_name,students[j].last_name))
			{
				tmp=students[i];
				students[i]=students[j];
				students[j]=tmp;
			}
		}

		std::cout<<"\nAfter sorting : \n";
		
		for(int i=0;i<size;i++) // вивід даних
		{
			std::cout<<"LAST NAME : "<<students[i].last_name<<"\n";
				
		}

		std::cout<<"\nMiddle-weight : male ( "<<s_male_w/(double)male<<" ) , fmale ( "<<
			s_fmale_w/(double)fmale<<" ) ";
		std::cout<<"\nMiddle-height : male ( "<<s_male_h/(double)male<<" ) , fmale ( "<<
			s_fmale_h/(double)fmale<<" ) ";

		free(students); // очишення динамічної памяті
		_getch();
		return 0;
}