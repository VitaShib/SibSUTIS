/*
На рисунке показана разметка серверного помещения, разбитого на прямоугольные фрагменты линиями на полу. Это сделано для упрощения поиска оборудования и инвентаризации. Каждая прямоугольная область имеет порядковый номер (указан внутри). Для упрощения их поиска введена двумерная нумерация, показанная на рисунках сбоку.
	1. Разработать программу, которая по уникальному номеру прямоугольной области определяет ее двумерные координаты.
	2. Разработать программу, которая по двумерным координатам области определяет ее порядковый номер.
*/

#include <stdio.h>

int main()
{
	printf("\t\t\t\t{x}\n\t\t[0]\t[1]\t[2]\t[3]\t[4]\n\t[0]\t 0\t 1\t 2\t 3\t 4\n{y}\t[1]\t 5\t 6\t 7\t 8\t 9\n\t[2]\t10\t11\t12\t13\t14\n\t[3]\t15\t16\t17\t18\t19\n\n");
	int x=0, y=0, n=0;

	printf("Введите номер прямоугольной области (1..19): ");
	scanf("%d",&n);
	x = n % 5;
	y = n / 5;
	printf("Двумерные координаты: [%d;%d]\n\n",x ,y);

	printf("Введите двумерные координаты: \n\tx (0..4): ");
	scanf("%d",&x);	
	printf("\ty (0..3): ");
	scanf("%d",&y);
	n = y*5-(4-x)+4;
	printf("Номер прямоугольной области: %d\n", n);



	return 0;
}

/*	
	int i=0, j=0;	//tmp
	for (j = 0; j <= 3; j++ )
	{ 
		for (i = 0; i <= 4; i++ )
		{
			printf ("\n\t[%d][%d]=(%d)",i,j, j*5-(4-i)+4 );
		}
		
	}
*/
