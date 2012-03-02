#include <iostream>
#include <conio.h>


/*

З клавіатури ввести послідовність даних з результатами роботи бригади за тиждень: <День>, <План>, <Фактичний виробіток>. 
Роздрукувати введені дані у вигляді таблиці, відсортувавши їх у порядку зростання плану. Визначити дні з найвищим і найменшим 
відсотком виконання плану.  

*/
 
struct WORK // структура для опису робочого дня
{
	int day;
	int plan;
	int actual_output;

};


int main18 ()
{
	WORK *wk,TMP; // вказівник на масив структур
	int size,best_day,worst_day;
	double work1,work2,tmp;
	
	std::cout<<"Enter size of array : ";
	std::cin>>size; // введення розмірності масиву

	wk= (WORK *) malloc(sizeof(WORK)*size);

	for(int i=0;i<size;i++) // ввід даних
	{
		std::cout<<"Enter day : ";
		std::cin>>wk[i].day;
		std::cout<<"Enter plan : ";
		std::cin>>wk[i].plan;
		std::cout<<"Enter actual output : ";
		std::cin>>wk[i].actual_output;

		if(!i) // припускаємо що перший день є найгіршим і найкращим
		{
			work1=work2=((double)wk[i].actual_output/(double)wk[i].plan)*100;
			best_day=0;
			worst_day=0;
		}
		else
		{	
			tmp=((double)wk[i].actual_output/(double)wk[i].plan)*100;

			if(work1<tmp) // знаходимо найгірший день
			{
				work1=tmp;
				worst_day=i;
			}

			if(work2>tmp) // знаходим найкрашій день
			{
				work2=tmp;
				best_day=i;
			}
		}

	}

	for(int i=0;i<size-1;i++) // сортування за планом
		for(int j=i+1;j<size;j++)
		{
			if(wk[i].plan>wk[j].plan)
			{
				TMP=wk[i];
				wk[i]=wk[j];
				wk[j]=TMP;
			}
		}

	std::cout<<"\nAfter sorting : \n";

	for(int i=0;i<size;i++) // вивід даних
	{
		std::cout<<"day : ";
		std::cout<<wk[i].day;
		std::cout<<" plan : ";
		std::cout<<wk[i].plan;
		std::cout<<" actual output : ";
		std::cout<<wk[i].actual_output<<"\n";
	}


	std::cout<<"best : "<<wk[best_day].day<<" worst : "<<wk[worst_day].day;
	_getch();
	free(wk); // очишення виділеної памяті
	return 0 ;
}