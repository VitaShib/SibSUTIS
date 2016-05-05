#include "input_output.h"
/*
int input()
{
	FILE *file;
	char *fname = "syslog.conf";//     !!!!! c клавы
	char result_sting[1024]; 				//Строка в 20 символов
	file = fopen(fname,"r");
	if(file == NULL)
	{
		printf("Не могу открыть файл %s", fname);
		return 0;
	}
	int i=0;
	char *real_tail;
	while(fgets(result_sting, sizeof(result_sting), file))
	{
		real_tail="";
		printf("Строка %d:Длина строки - %d:",i++,slen(result_sting));
		if(result_sting[slen(result_sting)-1] == '\n')//проверяем является ли последний элемент в строке символом её окончания
		{
			real_tail="\\n";
			result_sting[slen(result_sting)-1]='\0';
		};// эта часть кода добавлена лишь для отображения символа конца строки в консоль без перевода на новую строку	
		printf("%s%s\n",result_sting,real_tail);
	}
	fclose(file);
	return 0;
}*/

int Read(char *fname, char *textfile)
{
	FILE *fp = fopen(fname,"r");
	int ii=0;
	// Check the file 
	if(fp == NULL)
	{
		printf("No file");
		return 0; 
	}
	// Read the file
	for(ii=0;ii<1000;ii++)
	{
		int ret = fscanf(fp, "%c", &textfile[ii]);
		if(ret == EOF )
			break;
	}
	fclose(fp);
	return 0;
}

