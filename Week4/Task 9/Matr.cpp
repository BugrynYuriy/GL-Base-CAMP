#include "Matr.h"


//initialize all parameters in NULL
void Matr :: nullInit()
{
	size=0;
	count = 0;
	ptr=NULL;
	vector = NULL;
}

// memory deallocation
void Matr :: deleteMatrix()
{
	if(ptr!=NULL)
		delete [] ptr;

	if(vector!=NULL)
		delete [] vector;

	nullInit();
}

// memory allocator for new matrix
void Matr :: newMatrix (const unsigned int size )
{
	
	deleteMatrix();

	this->size=size;
	count = (long int)size*size;
	
	if(!allocateMemory(count,&ptr))
		{
			nullInit();
			std::cout<<"\nError allocation of memory \n";
			return;
		}
		
	ptr = (int *) memset(ptr,0,count*sizeof(int));
	vector = NULL;
}

// memory allocator
bool Matr::allocateMemory (const unsigned int size, int **cptr)
{
	
	if(*cptr!=NULL)
		
		delete [] *cptr;
	
	
	try
	{
		*cptr = new int [size];
	}

	catch(std::bad_alloc &e)
	{
		return false;
	}
	
	return true;
	
}

// Constructor
Matr::Matr () {
	
	nullInit();
}

// Constructor with parameter
Matr::Matr (const unsigned int size){
	
	nullInit();
	
	this->size=size;
	count = (long int)size*size;
	
	if(!allocateMemory(count,&ptr))
		{
			nullInit();
			std::cout<<"\nError allocation of memory \n";
			return;
		}
		
	ptr = (int *) memset(ptr,0,count*sizeof(int));
	vector = NULL;

}

// copy Constructor
Matr::Matr (const Matr& obj){
	
	size = obj.size;
	count = obj.count;
	
	if(!allocateMemory(count,&ptr))
		{
			nullInit();
			std::cout<<"\nError allocation of memory \n";
			return;
		}

	if(obj.vector!=NULL){
		
		if(!allocateMemory(size,&vector))
		{
			vector=NULL;
			std::cout<<"\nError allocation of memory \n";
			return;
		}
		
		memcpy(vector,obj.vector,size*sizeof(int));

	}
	
	memcpy(ptr,obj.ptr,count*sizeof(int));
	
}

//Destructor
Matr :: ~Matr (){
		
	deleteMatrix();

}

//overloaded assignment operator
Matr & Matr :: operator = (const Matr& obj) {
	
	int * tmp;
	
	if(this != &obj) { 
		
		if(!allocateMemory(obj.count,&tmp))
		{
			std::cout<<"\nError allocation of memory \n";
			return *this;
		}
		
		size = obj.size;
		count = obj.count;
		
		delete ptr;
		
		ptr = tmp;
		memcpy(ptr,obj.ptr,count*sizeof(int));

			if(obj.vector != NULL){
		
				if(!allocateMemory(size,&tmp))
				{
					vector = NULL;
				}
		
				memcpy(tmp,obj.vector,size*sizeof(int));
				vector = tmp;

			}

		
		return *this;
	}
	
	else 
		
		return *this;

}

// get reference by value of element from matrix
int& Matr::at (const unsigned int row , const unsigned int  column ){
		
	if(row >= size || column >= size){
			
		throw IndexesAreNotValid();
	
	}
	
	else{
		
		return ptr[(row*size+column)];
	}

}

// get value of element from matrix (safe function)
int Matr::getValueByIndexes (const unsigned int row , const unsigned int  column , bool& error) const{
	
	if(row>=size || column>=size ){
			
		error = false; // arguments are invalid
		return 0;
		
	}
		
	else{
		
		error = true; // argument are valid
		return ptr[(row*size+column)];
	}
	
}

// set value of element from matrix (safe function)
void Matr:: setValueByIndexes (const unsigned int row , const unsigned int  column , const int value , bool& error) {
	
	if(row>=size || column>=size ){
			
		error = false; // arguments are invalid
		return;
		
	}
	
	else{
		
		error = true; // argument are valid
		ptr[(row*size+column)] = value;
		return;
		
	}
	
}

long int Matr::dotProduct(const int n,bool& error) {
	
	this->createVector(n); // initialize vector of elements from main diagonal  mod n

	long int dotproduct=0;
		
	if(vector!=NULL){
			
		for(unsigned int i=0,j=0;i<count;i+=size+1,j++) {
				
			dotproduct+=(long int)ptr[i]*vector[j];  // get scalar product of the main diagonal and vector
			
		}
		
		error = true;
		
		return dotproduct;
	}

	else {
		
		error=false;
		return 0;
	}

}

// create vector from main diagonal elements	
void  Matr:: createVector (const unsigned int n){
	
	if(size!=0) {
	
		if(!allocateMemory(size,&vector))
		{
			std::cout<<"\nError allocation of memory \n";
			return;
		}
		
	}
		
		for(unsigned int i=0,j=0;i<count;i+=size+1,j++)  // push elements from main diagonal to vetor
				vector[j]=ptr[i] % n;
					
	return ;
			
}

// output vector to console
void Matr::showVector(){

	if(vector!=NULL){
		
		for(unsigned int i=0;i<size;i++)
			std::cout<<vector[i]<<" ";
	}

}

// output matrix to console
void Matr::showMatrix()
{
	
	for(unsigned int i=0; i<count ;i++)
	{
		std::cout<<ptr[i]<<" ";
		if((i+1) % size == 0)
			std::cout<<"\n";
	}
  
}

// fill matrix by random values
void Matr::randomMatrix(const int from , const int to)
{
	
	// initialize random seed : 
	srand (time(NULL) );

	for(unsigned int i =0 ;i <count ; i++)
	{
			ptr[i] = rand() % to + from;
			
	}
	
}

//Input matrix from the keyboard
void Matr:: inputMatrix()
{
	std::cout<<"\nEnter "<<size*size<<" elements of matrix :\n\n";

	for(unsigned int i =0 ;i <count ; i++)
		std::cin>>ptr[i];
}
