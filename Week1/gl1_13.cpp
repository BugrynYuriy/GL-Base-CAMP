#include <iostream>
#include <conio.h>


int pop (unsigned digit)
{
	// розбиваємо слово на  групи по 16 біт , в кожній виконуємо сумування і обєднуємо результат
	digit = (digit & 0x55555555)+((digit>>1)&0x55555555);
	// розбиваємо слово на  групи по 8 біт , в кожній виконуємо сумування і обєднуємо результат
	digit = (digit & 0x33333333)+((digit>>2)&0x33333333);
	// розбиваємо слово на  групи по 4 біт , в кожній виконуємо сумування і обєднуємо результат
	digit = (digit & 0x0F0F0F0F)+((digit>>4)&0x0F0F0F0F);
	// розбиваємо слово на  групи по 2 біт , в кожній виконуємо сумування і обєднуємо результат
	digit = (digit & 0x00FF00FF)+((digit>>8)&0x00FF00FF);
	
	digit = (digit & 0x000FFFF)+((digit>>16)&0x000FFFF);
	return digit;

}


int main ()
{

	unsigned int digit;
	char out[100];
	int i=(int)0;

	while(i<3)
	{
		std::cout<<"\nEnter digit :";
		std::cin>>digit;
		std::cout<<"Digit in binary "<<itoa(digit,out,2)<<" ";
		std::cout<<"Digit have "<<pop(digit)<<" bits in one\n";
		i++;
	}
	getch();

}