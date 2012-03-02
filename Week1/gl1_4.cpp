#include <iostream>
#include <conio.h>


int get_bit_value (unsigned long int digit,unsigned int bit)
{
	/* 
	   1<<bit - �������� ����� , ��� ������� �������� ������� bit
	   
	   digit&(1<<bit) - �������� ���������� ����� �� ��������� ��������� AND 
	   ��� ����������� �������� ������� bit		
	   
	   (digit&(1<<bit))>>bit - �� ��������� ������� ����� ���������� �������� 
	   ������� � �������� ����
	
	*/
	
	return (digit&(1<<bit))>>bit;
}

void change_bits (unsigned long int &digit,unsigned int bit1,unsigned int bit2)
{
	unsigned int cbit1=get_bit_value(digit,bit1); // �������� �������� ��� ������� bit1
	unsigned int cbit2=get_bit_value(digit,bit2); // �������� �������� ��� ������� bit2

	/*
		��������� �������� ������� , ���� ���� ��� �� res = 0 ������
		res = 1
	*/
	
	unsigned int res = cbit1!=cbit2; 
	
	/*
		���� �������� ������� ��� , �� ���������� �� �� 1 ������ �� 0
	*/

	cbit1=(cbit1|res)&res; 
	cbit2=(cbit2|res)&res;

	cbit1=cbit1<<bit2; // ������� �������� ������� bit1 � ������� bit2
	cbit2=cbit2<<bit1; // ������� �������� ������� bit2 � ������� bit1
	
	/*
		�������� ������� ���������� ��� � ������ �� ����������� 
	    ��������� ��� ��� cbit1 � cbit2, ��� ���� ��� �� ���������
		� ������� ���� �������� ��� cbit1 � cbit2 � ������
	*/

	digit = digit ^(cbit1|cbit2); 


}


int main ()
{
	unsigned long int digit,bit1,bit2;
	char out_in_binary[100];
	int i=0;
	while(i<3)
	{
		std::cout<<"\nEnter digit : ";
			std::cin>>digit;
			std::cout<<"\nDigit in binary befor replacement = "<<itoa(digit,out_in_binary,2);
			std::cout<<"\n\nEnter the bits for replacement : ";
			std::cin>>bit1>>bit2;
			change_bits(digit,bit1,bit2);
			std::cout<<"\nDigit in binary after replacement = "<<itoa(digit,out_in_binary,2)<<"\n";
	
		i++;
	}
	getch();
}