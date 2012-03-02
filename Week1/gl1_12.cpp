#include <iostream>
#include <conio.h>


/* 
	Використовуючи тільки бітові операції, написати функцію, яка міняє місцями 
	усі сусідні групи з 2-х бітів у заданому беззнаковому довгому цілому числі. 
*/

long int changeBits (unsigned long int digit)
{
	
	// оголошуємо дві маски , при накладанні яких на число отримаємо відповідно реальні значення кожно перших пар бітів
	// і кожноних других пар бітів
	// отримані значення відповідно зсуваємо на 2 позиції вліво для перших пар
	// і дві позиці вправо для других пар
	// в кінці виконуємо операцію АБО над отриманими результатами і отримуємо число де пари біт помінялися місцями
	
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