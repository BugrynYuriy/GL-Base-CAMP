#include <iostream>
#include <conio.h>

/*
  
  �������������� ����� ���� ��������, �������� �������, ��� ���������� � 1 ����������� �������� (������������ � 0) �� � 
  �������� ������������ ������� ������ ����.

*/

long int setInOneYoungestNullBit (unsigned long int digit)
{
	// �������� ������� eyfhybq vsyec  ��� ����������� ������ �����
	// ���� �� ���� ����������� �� digit+1
	// ���� ��������� �������� ��� , ��� ����� ����������� ���� , ������� ��������� ��
	// � ���������� ������� ������ ���� �� 1 � ���� � �������� ����������� �� � ��� ����� ��������
	
	return -(~digit)|digit;
}

int main ()
{
	long int digit;
	char out [100];
	int i=0;

	while(i<3)
	{
		std::cout<<"Enter digit : ";
		std::cin>>digit;
		std::cout<<"\nDigit in binary :"<<itoa(digit,out,2);
		std::cout<<"\nDigit after seting youngest null bit in one :"<<itoa(setInOneYoungestNullBit(digit),out,2)<<"\n\n";
		i++;
	}
	getch();

}
