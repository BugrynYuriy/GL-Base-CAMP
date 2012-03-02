#include <iostream>
#include <conio.h>


int get_bit_value (unsigned long int digit,unsigned int bit)
{
	/* 
	   1<<bit - виділяємо маску , яка відповідає заданому розряду bit
	   
	   digit&(1<<bit) - виконуємо накладання маски за допомогою побітового AND 
	   для знаходження значення розряду bit		
	   
	   (digit&(1<<bit))>>bit - за допомогою бітового зсуву переносимо значення 
	   розряду у молодший байт
	
	*/
	
	return (digit&(1<<bit))>>bit;
}

void change_bits (unsigned long int &digit,unsigned int bit1,unsigned int bit2)
{
	unsigned int cbit1=get_bit_value(digit,bit1); // отримуємо значення біта розряду bit1
	unsigned int cbit2=get_bit_value(digit,bit2); // отримуємо значення біта розряду bit2

	/*
		Порівнюємо значення розрядів , якщо вони рівні то res = 0 інакше
		res = 1
	*/
	
	unsigned int res = cbit1!=cbit2; 
	
	/*
		Якщо значення розрядів різні , то прирівнюємо їх до 1 інакше до 0
	*/

	cbit1=(cbit1|res)&res; 
	cbit2=(cbit2|res)&res;

	cbit1=cbit1<<bit2; // ставимо значення розряду bit1 в позицію bit2
	cbit2=cbit2<<bit1; // ставимо значення розряду bit2 в позицію bit1
	
	/*
		Виконуємо побітове виключення або з числом та результатом 
	    побітового або над cbit1 і cbit2, для зміни бітів на протилежні
		у випадку якщо значення бітів cbit1 і cbit2 є різними
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