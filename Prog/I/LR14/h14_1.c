/*
В отделении банка функционирует электронная очередь. Клиентам выдают талоны (момент выдачи считается началом обслуживания).
Далее они ожидают, пока на экране будет отображен их номер и проходят к специалисту. Специалист фиксирует время завершения обслуживания.
В результате к концу дня формируется последовательность времен обслуживания посетителей.
Разработать программу анализа работы банковского специалиста. На вход поступает последовательность времен обслуживания его клиентов.
Далее программа интерактивно взаимодействует с пользователем запрашивая номер I клиента, для которого нужно произвести анализ.
Далее определяется время c i пребывания i-го покупателя в очереди.
Указание:
	Время обслуживания i-го клиента складывается из времени обслуживания всех клиентов, стоящих перед ним, т.е. 0, 1, ..., i – 1 и его собственного.
*/

#include<stdio.h>

int main()
{
	int i=0, j=1, n, t=0, NClients=0;
	printf("Введите количество клиентов: ");
	scanf("%d",&NClients);
	int Time[NClients];
	for(i=0; i<NClients; i++)
	{
		printf("Введите время %d клиента: ",i+1);
		scanf("%d",&Time[i]);
	}

	while (j!=0)
	{
		printf("Продолжить? ('0'-нет/'1+'-да)");
		scanf("%d",&j);
		if (j)
		{
			printf("Введите номер клиента: ");
			scanf("%d",&n);
			if (n>NClients)
				printf("\tКлиент с таким номером отсутствует.\n");
			else
			{
				for(i=0; i<n; i++)
					t = t + Time[i];
				printf("\tВремя в очереди клиента №%d: %d\n",n,t);
			}
		}
		t=0;
	}

	return 0;
}

