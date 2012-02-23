#include <iostream>
#include <conio.h>


/* 
	�������������� ����� ���� ��������, �������� �������, ��� ���� ������ 
	�� ����� ����� � 2-� ��� � �������� ������������ ������� ������ ����. 
*/

long int changeBits (unsigned long int digit)
{
	
	// ��������� �� ����� , ��� ��������� ���� �� ����� �������� �������� ������ �������� ����� ������ ��� ���
	// � �������� ������ ��� ���
	// ������� �������� �������� ������� �� 2 ������� ���� ��� ������ ���
	// � �� ������ ������ ��� ������ ���
	// � ���� �������� �������� ��� ��� ���������� ������������ � �������� ����� �� ���� �� ��������� ������
	
	unsigned long int maskOne = (long int) 0x33333333;
	unsigned long int maskTwo = (long int) 0xCCCCCCCC;

	return ((digit&maskOne)<<2)|((digit&maskTwo)>>2);
	
}

int main ()
{
	long int digit;
	char out[100];
	int i=(int)0;
	while(i<3)
	{
		std::cout<<"Enter digit : ";
		std::cin>>digit;
		std::cout<<"\nDigit in binary : "<<itoa(digit,out,2);
		std::cout<<"\nDigit after changing bits :"<<itoa(changeBits(digit),out,2)<<"\n\n";
		i++;
	}
	getch();
	
}