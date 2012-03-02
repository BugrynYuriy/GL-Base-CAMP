#include <iostream>
#include <conio.h>
#include <stdarg.h>

// Create MAP and work with them .

union PassportSiries
{
	long long int hash;
	char siries [9];
};

typedef int COMPARE  (PassportSiries , PassportSiries );

int compare (PassportSiries obj1 , PassportSiries obj2)
{
	if(obj1.hash==obj2.hash)
		return 1;
	else return 0;
}

int operator > (PassportSiries obj1 , PassportSiries obj2)
{
	if(obj1.hash>obj2.hash)
		return 1;
	else return 0;
}

int operator < (PassportSiries obj1 , PassportSiries obj2)
{
	if(obj1.hash<obj2.hash)
		return 1;
	else return 0;
}

// series of passport checks on the validity

int isValidPassportSiries (int n,PassportSiries siries, ...) 
{

	va_list point ;
	va_start(point, n);
	PassportSiries tmp;
	
	while(n--)
	{
		tmp= va_arg(point,PassportSiries);
		// checks the first two letters , if characters aren't letters, return 0 else cheks other characters
		if( (tmp.siries[0]>=(char)65 && tmp.siries[0]<=(char)90) && (tmp.siries[1]>=(char)65 && tmp.siries[1]<=(char)90) )
		{	
			// if characters aren't digits , return 0 else return 1
			for(int i=2;i<8;i++)
				if(tmp.siries[i]<(char)48 || tmp.siries[i]>(char)57)
					return 0;
		}
		else return 0;
		point++;
	}
	

		return 1;
}

// Бінарний пошука
int BinSearch(PassportSiries *arr, int count, PassportSiries key , COMPARE *f) 
{
  int l = (int)0;            // нижняя граница
  int u = count - (int)1;    // верхняя граница
  int m;
 
  while (l <= u) {
    m = (l + u) / (int)2; // знаходимо середину масиву
	if (f(arr[m],key)) return m;  // якщо середній елемет дорівнюємо шуканий , повертаємо його індекс 
	if (arr[m]< key) l = m + (int)1;	// якщо середній елемент менший шуканого, початок переносимо  на середній + 1
	if (arr[m]> key) u = m - (int)1;	// якщо середній елемент більший шуканого, кінець переносимо   на середній - 1
  }
  return m; // якщо елементу нема , функція поверне індекс елементу , найближчого до шуканого
}



// Видалення елементу
PassportSiries * deleteElement (PassportSiries *arr, int &size, PassportSiries element)
{
	if(size==0) return NULL ;

	PassportSiries  *tmp=NULL,*cpy1=NULL,*cpy2=NULL;
	int index=0,c_buf=0,f_buf=0;
	errno_t err;

	index = BinSearch(arr,size,element,compare); // поршук елементу у масивы

	if(arr[index].hash==element.hash ) // перевірка чи елемент існує
	{
		tmp = new PassportSiries [size+(int)1]; // виділяємо память для нового масиву
		c_buf=sizeof(PassportSiries)*(size-(int)1); 
		f_buf=sizeof(PassportSiries)*index;

		// копіюємо з масиву в новий всі елементи до того , який потрібно видалити
		err= memcpy_s(tmp,c_buf,arr,f_buf); 

		if(err)
					return NULL;
		
			else
			{
				cpy1=tmp+(index); // посуваємо вказівник на новий елемент , щоб він вказував на перший елемент після останнього
				cpy2=arr+index+1; // посуваємо вказівник в заданому масиві так , щоб він став на перший елемент після того , який ми видалили
				f_buf = sizeof(PassportSiries)*(size-(index+(int)1));
				err = memcpy_s(cpy1,f_buf,cpy2,f_buf); // копіюємо в новий масив елементи з другого , які йдуть після видаленого

				if(err)
					{
						delete tmp;
						return arr;
					}
				
				else
				{
					size--;
					delete [] arr;
					return tmp;
				}
			
			}	
	}

	else
		return NULL;
}

// вставляє елемент у масив , так щоб зберігалась впорядкованість по зростанню
PassportSiries * insertElement (PassportSiries *arr, int &size, PassportSiries element)
{
	if(size==0) return NULL ;

	PassportSiries  *tmp=NULL,*cpy1=NULL,*cpy2=NULL;
	int index=0,c_buf=0,f_buf=0;
	errno_t err;

	index = BinSearch(arr,size,element,compare); // поршук елементу у масивы

	if(arr[index].hash!=element.hash) // перевірка чи елемент існує
	{
		if(arr[index].hash>=element.hash) // якщо елемент , на який вказує індекс більший за елемент , який потрібно вставити
		{
			tmp = new PassportSiries [size+1]; // виділяємо память для нового масиву
			c_buf=sizeof(PassportSiries)*(size+1); 
			f_buf=sizeof(PassportSiries)*index; 

			err= memcpy_s(tmp,c_buf,arr,f_buf); // копіюєм в новий масив всі елементи задоного , до елементу на який вказує індекс
		
			if(err)
				{
					delete tmp;
					return arr;
				}
		
			else

			{
				tmp[index].hash=element.hash; // в перший елемент після останнього записуємо елемент який потрібно додати
				tmp[index].siries[8]=(char)'\0';
				cpy1=tmp+(index+1); // вказівник на новий масив сунемо так , щоб він вказував на перший елемент після доданого
				cpy2=arr+index; // вказівник на поточний сунемо так , щоб він вказував на елемент , індекс якого повернула функція пошуку
				f_buf = sizeof(PassportSiries)*(size-index);

				err = memcpy_s(cpy1,f_buf,cpy2,f_buf); // дописуємо в новий масив елементи з заданого масиву

				if(err)
					{
						delete tmp;
						return arr;
					}
				
				else
				{
					size++;
					delete [] arr;
					tmp->siries[8]='\0';
					return tmp;
				}

			}

		}

		else // якщо елемент , на який вказує індекс менше заданого то ...
		{
			tmp = new PassportSiries [size+1]; // виділяємо память для нового масиву
			c_buf=sizeof(PassportSiries)*(size+1);
			f_buf=sizeof(PassportSiries)*(index+1);

			err= memcpy_s(tmp,c_buf,arr,f_buf); // копіюємо в новий масив елементи з заданого до елементу на який вказує індекс
		
			if(err)
				{
					delete tmp;
					return arr;
				}
		
			else

			{
				tmp[index+1].hash=element.hash; // вставляємо в позицію першого після останнього елементу в новому масиві заданий елемент
				tmp[index+1].siries[8]='\0';
				cpy1=tmp+(index+2); // посуваємо вказівник на новий масив , так щоб він вказував на перший елемент після доданого
				cpy2=arr+(index+1); // посуваємо вказівник на заданий масив , так щоб він вказував на елемент , на який перший елемент після того на який вказує індекс
				f_buf = sizeof(PassportSiries)*(size-(index+1));

				err = memcpy_s(cpy1,f_buf,cpy2,f_buf); // копіюємо з заданого в новий

				if(err)
				{
					delete tmp;
					return arr;
				}
			
				else
				{
					size++;
					delete [] arr;
					return tmp;
				}

			}
		}
	}
	
	return NULL;
}

// Додає елемент до карти
PassportSiries * addElementToMap (PassportSiries *old , PassportSiries element , int &size  )
{
	
	
	PassportSiries *tmp;
	if(size == 0) // якщо карта пуста , виділяє память і вставляє в неї значення елементу
	{
		old = new PassportSiries ();
		old->hash=element.hash;
		old->siries[8]='\0';
		size++;
		
		return old;
	}
	
	else // якщо карта має елементи , викорисовуємо функці вставки , зі збереженням впорядкованості за зростанням
	{
		tmp = insertElement(old,size,element);
		if(tmp==NULL)
			return NULL;
		else
		{
			old=tmp;
			return old;
		}
	}

}


int main ()
{
	PassportSiries *arr  =  new PassportSiries [1], key,*tmp ;
	int size=0,index;
	char variant;

	while(true) 
	{
		std::cout<<"Enter key : ";
		std::cin>>key.siries; // ввід даних з клавіатури
		if(isValidPassportSiries(1,key)&&key.siries[8]=='\0') // перевірямо серію паспорту на валідність
		{
			tmp=addElementToMap(arr,key,size); // додаємо елемент до карти
			if(tmp==NULL)
				std::cout<<"This element is present \n";
			else
				arr=tmp;
		}
		else
			std::cout<<"Passport series isn't valid \n";
		
		std::cout<<"\nAdd new element ? : y/n\n";
		variant = _getch();
		
		if(variant=='n'||variant=='N')
			break;
	}

	std::cout<<"\nSearching :\n";
	while(true)
	{
		std::cout<<"Enter the desired element : ";
		std::cin>>key.siries;// ввід даних з клавіатури
		
		if(isValidPassportSiries(1,key)&&key.siries[8]=='\0') // перевірямо серію паспорту на валідність
		{
			index=BinSearch(arr,size,key,compare); // використовуємо функцію пошуку
			if(arr[index].hash!=key.hash) // перевірка чи шуканий елемент існує
				std::cout<<"This element isn't in database\n";
			else
			{
				std::cout<<"Element was found : "<<arr[index].siries;
				std::cout<<" Delete element ? :y/n \n";
				variant = _getch();
				
				if(variant=='y'||variant=='Y')
				{
					tmp=deleteElement(arr,size,arr[index]); // виклик функції видалення
					if(tmp==NULL)
						std::cout<<"\nError while deleting \n";
					else 
					{
						std::cout<<"\nSuccessful deleting\n";
						arr=tmp;
					}
				}
			}

		}
		else
			std::cout<<"Passport series isn't valid \n";

		std::cout<<"\nTry again : y/n \n";

			variant = _getch();
		
			if(variant=='n'||variant=='N')
				break;

	}
	std::cout<<"\nDatabase of passport series :\n";
	
	for(int i=(int)0;i<size;i++) // вивів карти на екран
		std::cout<<"SIRIES : "<<arr[i].siries<<" HASH : "<<arr[i].hash<<" "<<"\n";
	
	delete []arr;
	_getch();
	return 0;
}