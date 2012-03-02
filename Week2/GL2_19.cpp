#include <iostream>
#include <conio.h>

/*
	З клавіатури ввести послідовність структур з даними у формі  <Числовий код>, <Повідомлення>. 
	Відсортувати введені записи в порядку спадання кодів і роздрукувати відсортований масив. 
	Визначити кількість повідомлень, в кодах яких є поруч дві однакові цифри.
*/


int CMP (long long int value ) // функцыя для перевырки числа , на двы однакових сусыдных чифри
{
	long long int i=(long long int)0,tmp1,tmp2;

	if(value<10)
		return 0;

	while(value != 0)
		{
			tmp1=value%10; // ділимо число на 10 , беремо остачу від ділення
			value=value/10; // ділимо число на 10 беремо цілу частину
			
			if(value==0) 
				return 0;
			
			tmp2=value%10; // ділимо число на 10 беремо остачу від ділення
			
			if(tmp1==tmp2) // перевіряємо чи числа однакові
				return 1;

		}

	return 0;
}


struct MESSAGE // структура яка описує повідомлення 
{
	long long int code ;
	char message [20];
};


int main19 ()
{
	MESSAGE *log , tmp; // вказівник на масив структур
	int size,code_count=0;

	
	std::cout<<"enter size of messages array : ";
	std::cin>>size; // розмірність масиву структур

	log= (MESSAGE *)malloc(sizeof(MESSAGE)*size);

	for (int i=0 ;i<size;i++) // ввід даних
	{
		std::cout<<"Enter code : ";
		std::cin>>log[i].code;
		std::cout<<"Enter message : ";
		std::cin>>log[i].message;
		if(CMP(log[i].code)) // перевірка чи число має дві цифри підряд
		{
			code_count++;
		}

	}


	for(int i=0;i<size-1;i++) // сортування за планом
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

	for (int i=0 ;i<size;i++) // вивід даних
	{
		std::cout<<"CODE : "<<log[i].code<<" MESSAGE : "<<log[i].message<<"\n";
	}
		
	std::cout<<"COde with the same digits : "<<code_count;

	_getch();
	free(log); // очишення виділеної памяті
	return 0;
}
