/*
Преподаватель подготовил N вариантов заданий, их нужно распределить между M студентами.
Если M ≤ N, то каждый студент получает уникальный вариант.
Если M > N, то распределение производится следующим образом:
	1. Первые N студентов получают задания, которые совпадают с их номерами.
	2. Студент с номером (N+1) выполняет 1-е задание, с номером 2N – N-е задание и так далее.
На вход программы поступает количество N вариантов и порядковый номер i студента в списке преподавателя. Определить вариант, который необходимо выполнить студенту.
*/

#include <stdio.h>

int main(void)
{
	int i=0, n=0, g=0;
	printf("Введите число вариантов: ");
	scanf("%d",&i);

	printf("Введите номер студента: ");
	scanf("%d",&n);

	for (g = 1; g <= n; g++ )
	{ 
		printf ("\nСтудент [%d]\t №Варианта: (%d)", g, ((g-1)%i)+1);
	}
	printf("\n");
	

	return 0;
}
