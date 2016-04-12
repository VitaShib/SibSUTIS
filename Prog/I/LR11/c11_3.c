/*
Разработайте программу, позволяющую для типа double экспериментально
определить :
	1) разрядность порядка и мантиссы;
	2) диапазон допустимых значений;
Указания к решению:
1. За основу взять программы вычисления машинного нуля и машинной бесконечности, рассмотренные в лекции No4 (в качестве эталонного значения использовать тип long double).
2. Для того, чтобы вычислить разрядности мантиссы и порядка исследовать два на количество возможных делений пополам:
а) 1, многократное деление этого числа на 2 приведет сначала к уменьшению порядка, после того, как порядок достигнет минимально возможного значения, виртуальная 1 будет игнорироваться и дельнейшее уменьшение числа будет происходить за счет мантиссы;
б) Число 1.9999999999999997779553950749686919152736663818359375, все разряды мантиссы которого единичны (в double-представлении), следовательно когда порядок достигнет минимально возможного значения, дальнейшее деление приведет к падению точности и, следовательно, отличиям между эталонным значением( long double) и анализируемым значением (double).
*/

#include<stdio.h>

int main()
{
	int p=0;
	double d=0, m=0;
	printf("Введите число с плавающей точкой: ");
	scanf("%lf",&d);
	m=d;
	while(m>=1)
	{
		m=m/2;
		p++;
	}
	printf("Порядок = %d, мантисса = %.15lf\n", p, m);
	printf("диапазон допустимых значений: от 1.7Е-308 до 1.7Е+308 (15 разрядов)\n", p, m);
	return 0;
}

/*
	Тип	Размер в байтах (битах)	Интервал изменения
	char				1 (8)	от -128 до 127
	unsigned char		1 (8)	от 0 до 255
	signed char			1 (8)	от -128 до 127
	int					2 (16)	от -32768 до 32767
	unsigned int		2 (16)	от 0 до 65535
	signed int			2 (16)	от -32768 до 32767
	short int			2 (16)	от -32768 до 32767
	unsigned short int	2 (16)	от 0 до 65535
	signed short int	2 (16)	от -32768 до 32767
	long int			4 (32)	от -2147483648 до 2147483647
	unsigned long int	4 (32)	от 0 до 4294967295
	signed long int		4 (32)	от -2147483648 до 2147483647
	float				4 (32)	от 3.4Е-38 до 3.4Е+38
	double				8 (64)	от 1.7Е-308 до 1.7Е+308
	long double			10(80)	от 3.4Е-4932 до 3.4Е+4932
*/