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

void Read(char *fname, char *textfile)
{
	int i=0, ch;
	FILE *fp = fopen(fname, "r");
	// Check the file 
	if(fp == NULL)
	{
		printf("No file");
		return; 
	}
	// Read the file
	for(i=0; i<1000; i++)
	{
		ch = fscanf(fp, "%c", &textfile[i]);
		if(ch == EOF )
			break;
	}
	fclose(fp);
	return;
}

