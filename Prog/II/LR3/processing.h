#ifndef PROCESSING_H
#define PROCESSING_H



/*
ID	Класс		Символы

0	service		[a-z]
1	priority	[a-z]
2	output		[0-9a-zA-Z/\!@#$%^&*()":;/?>.<, ]
3	host		[0-9a-zA-Z/\@:. ]
4	str			#.* или пробелы
-1	error
*/

typedef struct
{
	int id;
	char *value;
} stu;

void process(char *pat, char *dir);


//int update(...);
//int process(...);


#endif
