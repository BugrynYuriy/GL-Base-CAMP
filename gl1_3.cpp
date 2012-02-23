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

int compare_bits (unsigned long int digit , unsigned int bit1 , unsigned bit2)
{
	/* 
		�� ��������� ������� get_bit_value() �������� ������� �������� � ������� ��������
		bit1 � bit2 , ���� ������� ����� ���� �������� (�������� 0 � 1) �� ������� ������� 1
		������ 0
	*/
	return get_bit_value(digit,bit1)^get_bit_value(digit,bit2);
}


int main ()
{
	unsigned long int digit,bit1,bit2;
	char out_in_binary[100];
	int i=0;

	while(i<3)
	{
		std::cout<<"Enter digit : ";
		std::cin>>digit;
		std::cout<<"Digit in binary form : "<<itoa(digit,out_in_binary,2)<<"\n";
		std::cout<<"Enter the bits for comparison : ";
		std::cin>>bit1>>bit2;
		
		if(compare_bits(digit,bit1,bit2))
			std::cout<<"bit number : "<<bit1<<" and bit number "<<bit2<<" in digit "<<itoa(digit,out_in_binary,2)
			<<" are different \n\n";
		else 
			std::cout<<"bit number : "<<bit1<<" and bit number "<<bit2<<" in digit "<<itoa(digit,out_in_binary,2)
			<<" are the same \n\n";
	
		i++;
	}
	getch();
	return 0;
}