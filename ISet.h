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
	int size_set;  // Размер множества

public:
		Set (  )	
		{
			size_set = 0;			// счетчик введенных чисел
			set = new T[size_set];
		}

		void add ( const T& elem ) //Добавить элемент
		{
			T element = elem;
            int * values = NULL;
			bool flag=false;
			for (int i = 0; i<size_set; i++)	//O(N)
				if (element == set[i])
				{	
					
					cout<<"This element is already in set"<<endl;
					flag=true;
				}; 

				if (flag==false)
				{
					size_set++;
 
					set = (int*) realloc (values, size_set * sizeof(int)); //увеличиваем массив на 1
 
					values = set;
					values[size_set - 1] = element;                      // добавить к массиву только что введённое число
				}
					
			for (int i = 1; i<size_set; i++)	//O(N)
			{
				cout<<set[i]<<" ";
			}
		
		};
							
		void remove ( const T& elem )	//Удалить элемент
		{
			T element = elem;
			bool flag = true;
			int * values = NULL;

			for (int i = 0; i < size_set; i++)	//O(N^2)
			{
				if (element == set[i])
				{	
					flag = false;
					
					for( int j = i; j< size_set; j++)	
					{	
							set[j] = set[j+1];
					};

					size_set--;
					set = (int*) realloc (values, size_set * sizeof(int)); //уменьшаем размер на 1

				} 

			}

			if (flag == true)
			{
				cout<<"This element isn't found";
				return;
			}

			for (int i = 1; i<size_set; i++)	//O(N)
			{
				cout<<set[i]<<" ";
			}

		};

		bool contains ( const T& elem ) const	//содержится ли
		{
			
			T element = elem;
			
			bool flag = false;

			for (int i = 0; i<size_set; i++)	// O(N)
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
