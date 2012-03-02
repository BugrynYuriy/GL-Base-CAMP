#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>


/* 
	З клавіатури ввести послідовність записів, які складаються зі слів-термінів і їх перекладів 
	на іноземну мову. Очистити екран. Випадковим чином вибрати з масиву-словника задану кількість 
	термінів (серед них не повинно бути повторень), до кожного з яких користувач повинен ввести переклад. 
	Визначити відсоток правильних відповідей. 
*/


// обєднання , для опису слова
union WORD
{
	long long int hash [4]; 
	char word [32];

};

void clear (WORD *word) // заповнє память на яку вказує hash нулями
	{
		for(int i=0;i<4;i++)
			word->hash[i]=0;
	}

int equal (WORD word1 , WORD word2) // порівнює два слова за hash
	{
		if(word1.hash[0]==word2.hash[0] && word1.hash[1]==word2.hash[1]&&
				word1.hash[2]==word2.hash[2] && word1.hash[3]==word2.hash[3])

				return 1;
		else
			return 0;
	}




// структура для опису слова- перекладу
struct Vocabulary
{
	WORD term; // термін
	WORD translation; // переклад
	bool use ; // ідентифікатор використання структури

};

void initVocabulary(Vocabulary *vc) // конструктор по замовчуванні
	{
		vc->use = false;
		
		// ініціалізуємо слова нулями , щоб уникнути помилок при порівняннях 
		for(int i=0;i<4;i++)
		{
			vc->term.hash[i]=(long long int)0;
			vc->translation.hash[i]=(long long int)0;
		}
	}



int main9 ()
{

	Vocabulary *vc; // вказівник на структуру слово-переклад
	WORD word ; // відповідає за слово
	
	int size=0; // розмір масиву структур
	int answer_count=0; // кількість запитань , для проведення тесту
	int answer=0; // відповіді
	int right_answer=0; // правильні відповіді
	int question=0; // номер запитання
	
	setlocale(LC_ALL,"Ukrainian"); // для відображення кирилиці
	
	std::cout<<"Введiть кiлькiсть слiв для формування словника : ";
	std::cin>>size; // вводимо розмір термінів-перекладів

	vc= (Vocabulary *) malloc(sizeof(Vocabulary)*size);

	// ввід даних
	for(register int i=0;i<size;i++)
	{
		
		initVocabulary(&vc[i]);

		std::cout<<"\nВведiть терiмн : ";
		std::cin>>vc[i].term.word; // вводимо термін
		
		std::cout<<"\nВведiть переклад : ";
		std::cin>>vc[i].translation.word; // вводимо переклад терміну

	}
	
	system("cls"); // очишення екрану

	while(true){
	
		std::cout<<"Введiть кiлькiсть слiв для проведення тесту : ";
		std::cin>>answer_count; // вводимо кількість запитань , для тесту

		if(answer_count>size) // перевірка чи запитань не є більше , ніж є у словнику
			std::cout<<"\nНемає вiдповідної кiльності унікальних запитань, введіть кількість запитань меншу "<<size<<"\n";
		else
			break;
	}
	
	srand( (unsigned)time( NULL ) );  // встановлюємо вихідне число , для послідовності , яку генерує rand ()   

	while(answer<answer_count) // поки кількість відповідей менша за вказану кількість запитань
	{
		question = rand() % size; // генеруємо номер запитання , діапазон від 0 до size-1

		if(!vc[question].use) // перевірка чи запитання не використовувалось
		{
			vc[question].use=true; // відзначаємо запитання як використане
			answer++; // збільшеємо лічільник відповідей
			
			clear(&word); // онулення слова перед введенням

			std::cout<<"\nВведiть переклад термiну  "<<vc[question].term.word<<" - ";
			std::cin>>word.word; // вводимо відповідь
			
			// перевірка чи введена відповідь правильна , перевірка за хешами
			
			if(equal(word,vc[question].translation))
			{
				std::cout<<"\nПравильна вiдповiдь\n";
				right_answer++; // збільшення лічильника правильних відповідей
			}
			else 
				std::cout<<"\nНеправильна вiдповiдь\n";

		}
	}
	
	std::cout<<"\nВiдсоток правильних вiдповiдей "<<((double)right_answer)/answer_count*100<<" %"; // вивід відсотка правильних відповідей
	_getch ();
	
	free(vc);
	return 0;
}
