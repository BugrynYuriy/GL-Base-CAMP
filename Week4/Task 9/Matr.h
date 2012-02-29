#pragma once

#ifndef _INC_MATR
#define _INC_MATR

#include <time.h>
#include <iostream>


class Matr
{
	private :

		unsigned int size; // dimension of matrix
		unsigned int count; // count of matrix elements
		int *ptr; // pointer to matrix
		int * vector ; // pointer to vector

		void createVector (unsigned int n); // initialize vector of elements from main diagonal  mod n
		void nullInit(); // initialize all parameters in NULL
		void deleteMatrix();
		
		bool allocateMemory (const unsigned int size, int **ptr); // memory allocator
		
	public :

		Matr (); // Constructor
		Matr (const unsigned int size); // Constructor with parameter
		Matr (const Matr& obj); //Copy constructor
		~Matr (); // Destructor
		
		Matr & operator = (const Matr& obj); 
		
		
		void setValueByIndexes (const unsigned int row ,const unsigned  column  , const int value , bool& error); // set value of element from matrix (safe function)
		void showVector(); // Output vector in console
		void showMatrix(); // Output matrix in console
		void randomMatrix(const int from , int to); // fill matrix by random values
		void inputMatrix(); //Input matrix from the keyboard
		void newMatrix (const unsigned int size );
		
		int& at (const unsigned int row ,const unsigned  column  ); // get reference by value of element from matrix
		
		int getValueByIndexes (const unsigned int row , const unsigned int column  , bool& error) const ; // get value of element from matrix (safe function)
		
		long int dotProduct(const int n,bool& error); // return scalar product of the main diagonal and vector

		class IndexesAreNotValid // Exeption class
		{
			public :

				void message ()
				{
					std::cout<<"\nIndexes Are Not Valid\n";
				}
		};
	
};

#endif  /* _INC_MATR */