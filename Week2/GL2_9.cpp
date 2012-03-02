#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>


/* 
	� ��������� ������ ����������� ������, �� ����������� � ���-������ � �� ��������� 
	�� �������� ����. �������� �����. ���������� ����� ������� � ������-�������� ������ ������� 
	������ (����� ��� �� ������� ���� ���������), �� ������� � ���� ���������� ������� ������ ��������. 
	��������� ������� ���������� ��������. 
*/


// �������� , ��� ����� �����
union WORD
{
	long long int hash [4]; 
	char word [32];

};

void clear (WORD *word) // ������ ������ �� ��� ����� hash ������
	{
		for(int i=0;i<4;i++)
			word->hash[i]=0;
	}

int equal (WORD word1 , WORD word2) // ������� ��� ����� �� hash
	{
		if(word1.hash[0]==word2.hash[0] && word1.hash[1]==word2.hash[1]&&
				word1.hash[2]==word2.hash[2] && word1.hash[3]==word2.hash[3])

				return 1;
		else
			return 0;
	}




// ��������� ��� ����� �����- ���������
struct Vocabulary
{
	WORD term; // �����
	WORD translation; // ��������
	bool use ; // ������������� ������������ ���������

};

void initVocabulary(Vocabulary *vc) // ����������� �� �����������
	{
		vc->use = false;
		
		// ���������� ����� ������ , ��� �������� ������� ��� ���������� 
		for(int i=0;i<4;i++)
		{
			vc->term.hash[i]=(long long int)0;
			vc->translation.hash[i]=(long long int)0;
		}
	}



int main9 ()
{

	Vocabulary *vc; // �������� �� ��������� �����-��������
	WORD word ; // ������� �� �����
	
	int size=0; // ����� ������ ��������
	int answer_count=0; // ������� �������� , ��� ���������� �����
	int answer=0; // ������
	int right_answer=0; // �������� ������
	int question=0; // ����� ���������
	
	setlocale(LC_ALL,"Ukrainian"); // ��� ����������� ��������
	
	std::cout<<"����i�� �i���i��� ��i� ��� ���������� �������� : ";
	std::cin>>size; // ������� ����� ������-���������

	vc= (Vocabulary *) malloc(sizeof(Vocabulary)*size);

	// ��� �����
	for(register int i=0;i<size;i++)
	{
		
		initVocabulary(&vc[i]);

		std::cout<<"\n����i�� ���i�� : ";
		std::cin>>vc[i].term.word; // ������� �����
		
		std::cout<<"\n����i�� �������� : ";
		std::cin>>vc[i].translation.word; // ������� �������� ������

	}
	
	system("cls"); // �������� ������

	while(true){
	
		std::cout<<"����i�� �i���i��� ��i� ��� ���������� ����� : ";
		std::cin>>answer_count; // ������� ������� �������� , ��� �����

		if(answer_count>size) // �������� �� �������� �� � ����� , �� � � ��������
			std::cout<<"\n���� �i������� �i������ ��������� ��������, ������ ������� �������� ����� "<<size<<"\n";
		else
			break;
	}
	
	srand( (unsigned)time( NULL ) );  // ������������ ������� ����� , ��� ����������� , ��� ������ rand ()   

	while(answer<answer_count) // ���� ������� �������� ����� �� ������� ������� ��������
	{
		question = rand() % size; // �������� ����� ��������� , ������� �� 0 �� size-1

		if(!vc[question].use) // �������� �� ��������� �� �����������������
		{
			vc[question].use=true; // ��������� ��������� �� �����������
			answer++; // �������� �������� ��������
			
			clear(&word); // �������� ����� ����� ���������

			std::cout<<"\n����i�� �������� ����i��  "<<vc[question].term.word<<" - ";
			std::cin>>word.word; // ������� �������
			
			// �������� �� ������� ������� ��������� , �������� �� ������
			
			if(equal(word,vc[question].translation))
			{
				std::cout<<"\n��������� �i����i��\n";
				right_answer++; // ��������� ��������� ���������� ��������
			}
			else 
				std::cout<<"\n����������� �i����i��\n";

		}
	}
	
	std::cout<<"\n�i������ ���������� �i����i��� "<<((double)right_answer)/answer_count*100<<" %"; // ���� ������� ���������� ��������
	_getch ();
	
	free(vc);
	return 0;
}
