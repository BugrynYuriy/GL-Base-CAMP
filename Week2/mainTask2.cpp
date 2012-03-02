#include <iostream>
#include "haderTask2.h"


int main ()
{
	int lab ;
	std::cout<<"Chose lab number : ";
	std::cin>>lab;
	const volatile int i=10;
	* ( (int *) &i ) = 8;
	std::cout<<i;
	
	switch (lab)
	{
	 
		case 1 : main1();break;
		case 3 : main3();break;
		case 7 : main7();break;
		case 9 : main9();break;
		case 8 : main8();break;
		case 13 : main13();break;
		case 19 : main19();break;
		case 18 : main18();break;
		default : break;
	
	}

	return 0;
}