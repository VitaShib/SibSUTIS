/*
Алгоритм сортировки методом пузырька
Доработать программу, разработанную при выполнении задания H16.3.
Требования:
	1. Ввод и вывод массива реализуются в отдельных подпрограммах.
	Входные данные: массив и максимальное количество элементов в нем.
	Выходные данные: фактическое количество элементов в массиве и значения элементов.
	2. Реализовать прохода алгоритма в виде отдельной подпрограммы.
	Входные данные: 1) массив; 2) его размер; 3) номер прохода.
	Выходные данные: исходный массив, в котором k+1 элементов слева отсортированы.
	2. Алгоритм сортировки также вынести в отдельную подпрограмму.
*/

#include<stdio.h>

#include <stdlib.h>
#include <time.h>

void GenRandMas(int* arr, const int len, const int l, const int r)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < len; i++)
		arr[i]= (l-1 + rand() % r+2);
}

void KMUoutput(int MasX[], int M)
{
	int i,j, n=0;
//	double maxi=0, d=1;

//	for (i=0; i<M-1; i++)
//	{
//		maxi = maxi + M - i - 1;
//		for (j=i; j<M; j++)
//			if (MasX[i]>MasX[j])
//				n++;
//	}
//	d = d * (n / maxi);

	printf("\t%d:[",M);
	for (i=0; i<M; i++)
		i<M-1?printf("%d,", MasX[i]):printf("%d]\n", MasX[i]);
//		i<M-1?printf("%d,", MasX[i]):printf("%d] ", MasX[i]);
//	printf("(abs.inv)=%d; (rel.inv) = %.4lf\n", n,d);
}

void SortMP(int* arr, const int len)
{
	int i=0, j=0, tmp=0;
	for(i = 0 ; i < len - 1; i++) 
		for(j = 0 ; j < len - i - 1 ; j++)
			if(arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1] ;
				arr[j+1] = tmp;
				KMUoutput(arr, len);
			}

}

int main()
{
	int n=0;
	printf("Укажите размер случайного массива: ");
	scanf("%d", &n);
	int Mas[n];

	srand(time(NULL));
	printf("\tСлучайный массив: ");
	GenRandMas(Mas, n, 0, 100);
	KMUoutput(Mas, n);
	SortMP(Mas, n);
}
