
#include <iostream>
#include <conio.h>
#include "Matr.h"
/* 
   #include <C:\Program Files\Visual Leak Detector\src\vld.h>
   Visual Leak Detector is a free, robust, open-source memory leak detection system for Visual C++
   
   if you want use  this tools , you must downlowd it from http://vld.codeplex.com/ and install in you PC 
 
 */

//Задана квадратна матриця розмірності m × m. Матрицю задати в класі Matr. 
//Знайти скалярний добуток головної діагоналі на m-мірний вектор, кожна 
//координата якого є залишок по  mod n від різних елементів головної діагоналі. 
//Розмір¬ність задати в головній програмі константою. Елементами матриці є цілі числа.


int main()
{
	
  bool error ;
  unsigned int size=0;
  Matr *matr ;
  char variant;

  std::cout<<"Enter size of matrix : ";
  std::cin>>size; // read size of matrix

  matr= new Matr(size) ; // create matrix

  std::cout<<"Use randomize values ? : y/n " ;
  variant = _getch();

  //Input matrix from the keyboard or fill by random values
  if(variant=='y'||variant =='Y') 
	 
	  matr->randomMatrix(10,99);
  
  else
	  
	  matr->inputMatrix();

  
  std::cout<<"\nOutput "<<size*size<<" elements of matrix :\n\n";

  //Output matrix from the keyboard
  matr->showMatrix();
  
  std::cout<<"\nEnter mod value n : ";
  int n ;

  std::cin>>n;
  
  int dot = matr->dotProduct(n,error); // get scalar product of the main diagonal and vector
   
  std::cout<<"\nVector : ";
  matr->showVector();
   
  std::cout<<"\nScalar product of the main diagonal and vector : "<<dot;
  
  delete matr;
  _getch();
  return 0;

}