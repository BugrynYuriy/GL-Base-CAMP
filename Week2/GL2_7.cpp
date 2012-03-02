#include <iostream>
#include <conio.h>

struct Book // ��������� ��� ����� �����
{
	char author [20];
	char name [20];
	int year;
	char edition [20];
};

int main7 ()
{

	Book *libary,tmp; // �������� �� ����� ������
	int size; // ����� ������ ��������

	std::cout<<"Enter size of libary : ";
	std::cin>>size;

	libary = (Book*)malloc(sizeof(Book)*size); // �������� ����� ��� ������ ��������

	
	// ��� �����
	for(register int i=0;i<size;i++)
	{
		std::cout<<"Enter name of author :";
		std::cin>>libary[i].author;
		std::cout<<"Enter name of book :";
		std::cin>>libary[i].name;
		std::cout<<"Enter year of book :";
		std::cin>>libary[i].year;
		std::cout<<"Enter name of edition :";
		std::cin>>libary[i].edition;
	}

	
	// ���������� ��������
	for(int i=0;i<size-1;i++)
		for(int j=i+1;j<size;j++)
			if(libary[i].year<libary[j].year)
			{
				tmp = libary[i];
				libary[i]=libary[j];
				libary[j]=tmp;
			}

	std::cout<<"\nLibary after sorting :\n";
	
	// ���� �����
	for(register int i=0;i<size;i++)
	{
		std::cout<<"Author :"<<libary[i].author<<" Name : "<<libary[i].name<<" Year : "<<libary[i].year
			<<" Edition : "<<libary[i].edition<<"\n";
	}

	// �������� ������� �����
	free(libary);
	_getch();
	return 0;
}