#include <iostream>
#include <conio.h>



struct POINT // ����� ����� � ������
{
	int x,y,z;
};

struct DISTANCE // ����� ������� �� ����� �������
{
	POINT a,b;
	double distance;
};


double getDistance (POINT p1, POINT p2) // ������� ����������� ������ �� ����� �������
{
	return sqrt( (long double)((p1.x-p2.x)*(p1.x-p2.x))+(long double)((p1.y-p2.y)*(p1.y-p2.y))+(long double)((p1.z-p2.z)*(p1.z-p2.z)));
}


int main8 ()
{
	
	POINT *points,tmp; // �������� �� ����� ��������
	DISTANCE dis; // ����� ��� ���������� ������
	int size; // ��������� ������
	double min_distance;

	std::cout<<"Enter size of points array : ";
	std::cin>>size;

	points= (POINT *)malloc(sizeof(POINT)*size); // �������� ����� ��� ������ ��������

	for(register int i=0;i<size;i++) // ��� �����
	{
		std::cout<<"Enter point parameters (x,y,z) : ";
		std::cin>>points[i].x>>points[i].y>>points[i].z;
	}

	// ���������� �� ���������� z 

	std::cout<<"\nPoints array after sorting :\n";

	dis.distance=min_distance=getDistance(points[0],points[1]);
	dis.a=points[0];
	dis.b=points[1];
	
	for(register int i=0;i<size-1;i++){
	
		for(register int j=i+1; j<size;j++)
		{
			if(points[i].z > points[j].z)
			{
				tmp=points[i];
				points[i]=points[j];
				points[j]=tmp;
			}

			if(getDistance(points[i],points[j])<min_distance) // ����������� �������� ������
			{
				dis.distance=min_distance=getDistance(points[i],points[j]);
				dis.a=points[i];
				dis.b=points[j];
			}

		}
	}
		
	for(register int i=0; i<size;i++) // ���� �����
		{
			std::cout<<" X = "<<points[i].x<<" Y = "<<points[i].y<<" Z = "<<points[i].z<<"\n";
		}
		
			std::cout<<"\nThe smallest distance between boints : "<<dis.distance<<"\n";
			std::cout<<" X = "<<dis.a.x<<" Y = "<<dis.a.y<<" Z = "<<dis.a.z<<"\n";
			std::cout<<" X = "<<dis.b.x<<" Y = "<<dis.b.y<<" Z = "<<dis.b.z<<"\n";
	
	_getch();
	free(points);	// �������� �����
	
	return 0;
}

