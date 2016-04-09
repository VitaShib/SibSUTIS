/*
Входные данные: вещественные числа x и y.
Выходные данные: |x – y|.
Ограничения:
	Не допускается вычисление разности с последующим взятием модуля: нет возможности хранить отрицательное число.
Рекомендации:
	Сформировать выражение, аналогично задаче С09.2, позволяющее получить требуемое решение.
*/

#include <stdio.h>

int main()
{
	float a,b;
	printf("Введите X и Y: ");
	scanf("%f %f",&a,&b);
	printf("\tX = %.2f\n\tY = %.2f\n\t|X-Y| = %.2f\n",a,b,(((a-b)>=0)-((a-b)<0))*(a-b));
	return 0;
}

