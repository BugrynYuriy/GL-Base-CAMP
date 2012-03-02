#include <iostream>
#include <conio.h>


unsigned long int setInNullEldestOneBit (unsigned long int digit)
{
	unsigned long int mask=digit ;
	
	// ��� ���������� � 0 ���������� �� � ������� 
	// �� ��������� ����� ��� ���� ��������� ���� ��������� ���� ���������
	// ����� ����� �������� �������� � ��������� �������� ��� � ����������
	// ��� ������ |= ������ >> �������� �� 1,2,4,8,16,32
	// ���� ����� ���� 00100000 �� ����� ���� ���� 00111111
	// ���� ����� �� �������� ���������� �� mask^(mask>>1)
	// ��������� 001000000
	// � ���� ����� �������� �������� XOR ����� � �����
	
	mask |= mask >> (unsigned long int)1;
    mask |= mask >> (unsigned long int)2;
    mask |= mask >> (unsigned long int)4;
    mask |= mask >> (unsigned long int)8;
    mask |= mask >> (unsigned long int)16;
	mask |= mask >> (unsigned long int)32;

	return  digit^(mask^(mask>>1));

}

int main ()
{
	unsigned long int digit;
	char out [100];
	int i=(int)0;

	while(i<3)
	{
		std::cout<<"Enter digit : ";
		std::cin>>digit;
		std::cout<<"\nDigit in binary :"<<itoa(digit,out,2);
		std::cout<<"\nDigit after cleaning eldest binary :"<<itoa(setInNullEldestOneBit(digit),out,2)<<"\n\n";
		i++;
	}
	getch();

}