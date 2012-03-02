#include <iostream>
#include <conio.h>

/*
  
  Використовуючи тільки бітові операції, написати функцію, яка встановлює в 1 наймолодший очищений (установлений в 0) біт у 
  заданому беззнаковому довгому цілому числі.

*/

long int setInOneYoungestNullBit (unsigned long int digit)
{
	// здійснюєм інверсію eyfhybq vsyec  над результатом інверсії числа
	// дана дія буде еквівалентна до digit+1
	// потім здійснюємо операцію АБО , яка затре наймолодший нуль , оскільки попередня дія
	// х додаванням одиниці посуне вліво всі 1 в числі і відповідне наймолодший біт в нулі стане одиницею
	
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
