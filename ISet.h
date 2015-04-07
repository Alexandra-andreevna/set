#ifndef __ISET_H
#define __ISET_H	

	#include <iostream> 
	#include <clocale>
	#include <stdlib.h>
	#include <new>
		
	using namespace std;      

template < class T > class ISet
{
public:
 // добавить элемент
 virtual void add(const T& elem) = 0;
 // удалить элемент
 virtual void remove(const T& elem) = 0;
 // содержится ли элемент
 virtual bool contains(const T& elem) const = 0;
 // узнать размер множества
 virtual int size() const = 0;

};


template < class T > class Set : public ISet < T >
{
protected:

	T *set;  // Множество
	T *temp; // Временный массив
	unsigned int size_set;  // Размер множества

public:
		Set (  )	
		{
			set = new (nothrow) T [0];
			size_set = 0;
		}

		void add ( const T& elem ) //Добавить элемент
		{
			T element = elem;
			

			for (int i = 0; i<size_set; i++)
				if (element == set[i])
				{	
					
					cout<<"This element is already in set"<<endl;
					return;
				} 

				
					temp = new (nothrow) T [size_set];
					
					for (int i=0; i<size_set; i++)
						temp[i] = set[i];

					delete [] set;

					size_set=size_set+1;
					
					set = new (nothrow) T [size_set];

					for(int i = 0; i < size_set; i++)
					set[i] = temp[i];
					
					delete [] temp;

					set[size_set-1] = element;
				
			
		
		};
							
		void remove ( const T& elem )	//Удалить элемент
		{
			T element = elem;
			bool flag = true;
			
			temp = new (nothrow) T [sizeset-1];

			for (int i = 0; i < size_set; i++)
			{
				cout<<"i="<<i<<endl;
				if (element == set[i])
				{	
					flag = false;
					
					int k=0;
					
					for( int j = 0; j< size_set; j++)
					{	
						if (set[i] != element)
						{
							temp[k] = set[i];
							k++;
						}
					}

				} 

			}
			if (flag == true)
			{
				cout<<"This element isn't found";
				return;
			}

		

		};

		bool contains ( const T& elem ) const	//содержится ли
		{
			
			T element = elem;
			
			bool flag = false;

			for (int i = 0; i<size_set; i++)
				if (element == set[i])
				{	
					flag = true;
				} 
			return flag;

		};

		int size() const	//размер множества
		{
			return size_set;
		};
};

#endif
