/*
Аналогично С08.5 реализовать обмен значениями двух ячеек без использования вспомогательной переменной на основе операции XOR.
	• Имеет ли данный подход какие-либо ограничения?
	• Имеет ли значение, какой тип данного имеют ячейки, для которых производится обмен?
	• Покажите, работоспособность данного подхода для значений, на которых подход на основании суммы не работает.
*/

#include <stdio.h>

int main()
{
	int a=0, b=0;
	printf("Введите A и B: ");
	scanf("%d %d",&a,&b);
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	printf("\nОбмен значениями:\na=%d b=%d\n", a, b);
	return 0;
}
