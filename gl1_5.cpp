#include <iostream>
#include <conio.h>


using namespace std;

int max(long int x)
{
	// x>>31 ������� �� ����� � �������� �� , �������� , ���� ����� ����� , �� �� ��� ������ ���� 1
	// ������ �� ��� ������ ���� 0
	// ~(x>>31) - ������� ������� , ���� ����� ������� �� �� ��� ������ ���� 1 ������ 0
	// (~(x>>31))&x- ��������� �������� ����� �� ������ ����� � ��������� ���� ����� ����� �� �����������
	// ���� 0 , �� � ����� ������� �� ��� ����� ���� (0) ������ ����� ���� -1 (����� �� ������� )
	// ����������� ���� ������ ����� , �� �������������� , �� ���� �������
	
	return (~(x>>31))&x;
}


int main ()
{
	long int x, i=(long int)0;
	while(i<3)
	{
		cout<<"\nEnter digit  : ";
		cin>>x;
		
		if(max(x)||x==0)
			cout<<"Digit "<<x<<" is positiv\n";
		else
			cout<<"Digit "<<x<<" is negative\n";
	
		i++;
	}
	getch();

}