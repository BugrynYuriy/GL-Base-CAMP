#include <iostream>
#include <conio.h>
#include <string>


struct WORK1 // ��������� ��� ����� �������� ���
{
	int month;
	int plan;
	int actual_output;

};



int main3()
{

	std::string  month []  ={ "January","February","March","April","May","June","July","August","September","October",
	"November","December"};
	WORK1 *wk,TMP; // �������� �� ����� ��������
	int size;
	
	
	std::cout<<"Enter size of array : ";
	std::cin>>size; // �������� ��������� ������

	wk= (WORK1 *) malloc(sizeof(WORK1)*size);

	for(int i=0;i<size;i++) // ��� �����
	{
		std::cout<<"Enter month : ";
		std::cin>>wk[i].month;
		std::cout<<"Enter plan : ";
		std::cin>>wk[i].plan;
		std::cout<<"Enter actual output : ";
		std::cin>>wk[i].actual_output;

	}

	for(int i=0;i<size-1;i++) // ���������� �� ������
		for(int j=i+1;j<size;j++)
		{
			if(((double)wk[i].actual_output/(double)wk[i].plan)*100<((double)wk[j].actual_output/(double)wk[i].plan)*100)
			{
				TMP=wk[i];
				wk[i]=wk[j];
				wk[j]=TMP;
			}
		}

	std::cout<<"\nAfter sorting : \n";

	for(int i=0;i<size;i++) // ���� �����
	{
		std::cout<<"month : ";
		std::cout<<month[wk[i].month-1];
		std::cout<<" plan : ";
		std::cout<<wk[i].plan;
		std::cout<<" actual output : ";
		std::cout<<wk[i].actual_output<<"\n";
	}


	
	_getch();
	free(wk); // �������� ������� �����
	return 0 ;
}