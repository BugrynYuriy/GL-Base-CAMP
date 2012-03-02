#include <iostream>
#include <conio.h>

// Create MAP and work with them .

union PassportSiries
{
	long long int hash;
	char siries [9];
};



// series of passport checks on the validity

int isValidPassportSiries (PassportSiries siries) 
{
	// checks the first two letters , if characters aren't letters, return 0 else cheks other characters
	if( (siries.siries[0]>=(char)65 && siries.siries[0]<=(char)90) && (siries.siries[1]>=(char)65 && siries.siries[1]<=(char)90) )
	{	
		// if characters aren't digits , return 0 else return 1
		for(int i=2;i<8;i++)
			if(siries.siries[i]<(char)48 || siries.siries[i]>(char)57)
				return 0;
		
		return 1;
	}

	else

		return 0;
}

// �������� ������
int BinSearch(PassportSiries *arr, int count, PassportSiries key) 
{
  int l = (int)0;            // ������ �������
  int u = count - (int)1;    // ������� �������
  int m;
 
  while (l <= u) {
    m = (l + u) / (int)2; // ��������� �������� ������
	if (arr[m].hash == key.hash) return m;  // ���� ������� ������ ��������� ������� , ��������� ���� ������ 
	if (arr[m].hash < key.hash) l = m + (int)1;	// ���� ������� ������� ������ ��������, ������� ����������  �� ������� + 1
	if (arr[m].hash > key.hash) u = m - (int)1;	// ���� ������� ������� ������ ��������, ����� ����������   �� ������� - 1
  }
  return m; // ���� �������� ���� , ������� ������� ������ �������� , ����������� �� ��������
}



// ��������� ��������
PassportSiries * deleteElement (PassportSiries *arr, int &size, PassportSiries element)
{
	PassportSiries  *tmp=NULL,*cpy1=NULL,*cpy2=NULL;
	int index=0,c_buf=0,f_buf=0;
	errno_t err;

	index = BinSearch(arr,size,element); // ������ �������� � ������

	if(arr[index].hash==element.hash ) // �������� �� ������� ����
	{
		tmp = new PassportSiries [size+(int)1]; // �������� ������ ��� ������ ������
		c_buf=sizeof(PassportSiries)*(size-(int)1); 
		f_buf=sizeof(PassportSiries)*index;

		// ������� � ������ � ����� �� �������� �� ���� , ���� ������� ��������
		err= memcpy_s(tmp,c_buf,arr,f_buf); 

		if(err)
					return NULL;
		
			else
			{
				cpy1=tmp+(index); // �������� �������� �� ����� ������� , ��� �� �������� �� ������ ������� ���� ����������
				cpy2=arr+index+1; // �������� �������� � �������� ����� ��� , ��� �� ���� �� ������ ������� ���� ���� , ���� �� ��������
				f_buf = sizeof(PassportSiries)*(size-(index+(int)1));
				err = memcpy_s(cpy1,f_buf,cpy2,f_buf); // ������� � ����� ����� �������� � ������� , �� ����� ���� ����������

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

// �������� ������� � ����� , ��� ��� ���������� �������������� �� ���������
PassportSiries * insertElement (PassportSiries *arr, int &size, PassportSiries element)
{
	PassportSiries  *tmp=NULL,*cpy1=NULL,*cpy2=NULL;
	int index=0,c_buf=0,f_buf=0;
	errno_t err;

	index = BinSearch(arr,size,element); // ������ �������� � ������

	if(arr[index].hash!=element.hash) // �������� �� ������� ����
	{
		if(arr[index].hash>=element.hash) // ���� ������� , �� ���� ����� ������ ������ �� ������� , ���� ������� ��������
		{
			tmp = new PassportSiries [size+1]; // �������� ������ ��� ������ ������
			c_buf=sizeof(PassportSiries)*(size+1); 
			f_buf=sizeof(PassportSiries)*index; 

			err= memcpy_s(tmp,c_buf,arr,f_buf); // ������ � ����� ����� �� �������� �������� , �� �������� �� ���� ����� ������
		
			if(err)
				{
					delete tmp;
					return arr;
				}
		
			else

			{
				tmp[index].hash=element.hash; // � ������ ������� ���� ���������� �������� ������� ���� ������� ������
				tmp[index].siries[8]=(char)'\0';
				cpy1=tmp+(index+1); // �������� �� ����� ����� ������ ��� , ��� �� �������� �� ������ ������� ���� ��������
				cpy2=arr+index; // �������� �� �������� ������ ��� , ��� �� �������� �� ������� , ������ ����� ��������� ������� ������
				f_buf = sizeof(PassportSiries)*(size-index);

				err = memcpy_s(cpy1,f_buf,cpy2,f_buf); // �������� � ����� ����� �������� � �������� ������

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

		else // ���� ������� , �� ���� ����� ������ ����� �������� �� ...
		{
			tmp = new PassportSiries [size+1]; // �������� ������ ��� ������ ������
			c_buf=sizeof(PassportSiries)*(size+1);
			f_buf=sizeof(PassportSiries)*(index+1);

			err= memcpy_s(tmp,c_buf,arr,f_buf); // ������� � ����� ����� �������� � �������� �� �������� �� ���� ����� ������
		
			if(err)
				{
					delete tmp;
					return arr;
				}
		
			else

			{
				tmp[index+1].hash=element.hash; // ���������� � ������� ������� ���� ���������� �������� � ������ ����� ������� �������
				tmp[index+1].siries[8]='\0';
				cpy1=tmp+(index+2); // �������� �������� �� ����� ����� , ��� ��� �� �������� �� ������ ������� ���� ��������
				cpy2=arr+(index+1); // �������� �������� �� ������� ����� , ��� ��� �� �������� �� ������� , �� ���� ������ ������� ���� ���� �� ���� ����� ������
				f_buf = sizeof(PassportSiries)*(size-(index+1));

				err = memcpy_s(cpy1,f_buf,cpy2,f_buf); // ������� � �������� � �����

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

// ���� ������� �� �����
PassportSiries * addElementToMap (PassportSiries *old , PassportSiries element , int &size )
{
	
	PassportSiries *tmp;
	if(size == 0) // ���� ����� ����� , ������ ������ � �������� � �� �������� ��������
	{
		old = new PassportSiries ();
		old->hash=element.hash;
		old->siries[8]='\0';
		size++;
		
		return old;
	}
	
	else // ���� ����� �� �������� , ������������ ������ ������� , � ����������� �������������� �� ����������
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
		std::cin>>key.siries; // ��� ����� � ���������
		if(isValidPassportSiries(key)&&key.siries[8]=='\0') // ��������� ���� �������� �� ��������
		{
			tmp=addElementToMap(arr,key,size); // ������ ������� �� �����
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
		std::cin>>key.siries;// ��� ����� � ���������
		
		if(isValidPassportSiries(key)&&key.siries[8]=='\0') // ��������� ���� �������� �� ��������
		{
			index=BinSearch(arr,size,key); // ������������� ������� ������
			if(arr[index].hash!=key.hash) // �������� �� ������� ������� ����
				std::cout<<"This element isn't in database\n";
			else
			{
				std::cout<<"Element was found : "<<arr[index].siries;
				std::cout<<" Delete element ? :y/n \n";
				variant = _getch();
				
				if(variant=='y'||variant=='Y')
				{
					tmp=deleteElement(arr,size,arr[index]); // ������ ������� ���������
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
	
	for(int i=(int)0;i<size;i++) // ���� ����� �� �����
		std::cout<<"SIRIES : "<<arr[i].siries<<" HASH : "<<arr[i].hash<<" "<<"\n";
	
	delete []arr;
	_getch();
	return 0;
}