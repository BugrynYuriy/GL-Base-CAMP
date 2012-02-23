#include <iostream>
#include <conio.h>

/*
	� ��������� ������ ����������� �������� � ������ � ����  <�������� ���>, <�����������>. 
	³���������� ������ ������ � ������� �������� ���� � ������������ ������������ �����. 
	��������� ������� ����������, � ����� ���� � ����� �� ������� �����.
*/


int CMP (long long int value ) // ������� ��� ��������� ����� , �� ��� ��������� �������� �����
{
	long long int i=(long long int)0,tmp1,tmp2;

	if(value<10)
		return 0;

	while(value != 0)
		{
			tmp1=value%10; // ����� ����� �� 10 , ������ ������ �� ������
			value=value/10; // ����� ����� �� 10 ������ ���� �������
			
			if(value==0) 
				return 0;
			
			tmp2=value%10; // ����� ����� �� 10 ������ ������ �� ������
			
			if(tmp1==tmp2) // ���������� �� ����� �������
				return 1;

		}

	return 0;
}


struct MESSAGE // ��������� ��� ����� ����������� 
{
	long long int code ;
	char message [20];
};


int main19 ()
{
	MESSAGE *log , tmp; // �������� �� ����� ��������
	int size,code_count=0;

	
	std::cout<<"enter size of messages array : ";
	std::cin>>size; // ��������� ������ ��������

	log= (MESSAGE *)malloc(sizeof(MESSAGE)*size);

	for (int i=0 ;i<size;i++) // ��� �����
	{
		std::cout<<"Enter code : ";
		std::cin>>log[i].code;
		std::cout<<"Enter message : ";
		std::cin>>log[i].message;
		if(CMP(log[i].code)) // �������� �� ����� �� �� ����� �����
		{
			code_count++;
		}

	}


	for(int i=0;i<size-1;i++) // ���������� �� ������
		for(int j=i+1;j<size;j++)
		{
			if(log[i].code>log[j].code)
			{
				tmp=log[i];
				log[i]=log[j];
				log[j]=tmp;
			}
		}

	std::cout<<"\nArray after sorting : \n";

	for (int i=0 ;i<size;i++) // ���� �����
	{
		std::cout<<"CODE : "<<log[i].code<<" MESSAGE : "<<log[i].message<<"\n";
	}
		
	std::cout<<"COde with the same digits : "<<code_count;

	_getch();
	free(log); // �������� ������� �����
	return 0;
}
