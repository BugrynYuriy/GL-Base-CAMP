#include <iostream>
#include <conio.h>


struct Book // ��������� ��� ����� �����
{
	char author [20];
	char note [20];
	int year;
	char name [20];
};

int CMP1 (char one[20] , char two[20]) // ������� ��� ��������� ��������� ���
{
	int i=0;
	
	while (two[i]!='\0')
		
		{
			if(two[i]<one[i])
				return 1; // ����� ����� �����
			if(two[i]>one[i])
				return 0; // ����� ����� �����
			i++;
		}

	return 0;
}

int main1(){

Book *libary,tmp; // �������� �� ����� ������
	int size; // ����� ������ ��������

	std::cout<<"Enter size of libary : ";
	std::cin>>size;

	libary = (Book *) malloc(sizeof(Book)*size); // �������� ����� ��� ������ ��������

	
	// ��� �����
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

	
	// ���������� ��������
	for(int i=0;i<size-1;i++)
		for(int j=i+1;j<size;j++)
			if(CMP1(libary[i].author,libary[j].author))
			{
				tmp = libary[i];
				libary[i]=libary[j];
				libary[j]=tmp;
			}

	std::cout<<"\nLibary after sorting :\n";
	
	// ���� �����
	for(register int i=0;i<size;i++)
	{
		std::cout<<"Author :"<<libary[i].author<<" NOTE : "<<libary[i].note<<" Year : "<<libary[i].year
			<<" NAME : "<<libary[i].name<<"\n";
	}

	std::cout<<"\n1970 :\n";
	
	// ���� �����
	for(register int i=0;i<size;i++)
	{
		if(libary[i].year==1970)
		std::cout<<"Author :"<<libary[i].author<<" NOTE : "<<libary[i].note<<" Year : "<<libary[i].year
			<<" NAME : "<<libary[i].name<<"\n";
	}

	// �������� ������� �����
	free(libary);
	_getch();
	return 0;
}