#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define IFILE "input.txt"

const int YES = 1, NO = 0;
int main()
{
	uint32_t CountWord = 0, CountSpace = 0;
	FILE* f;
	// Попытка открыть файл
	if((f = fopen(IFILE, "r")) == NULL)
	{
		// Провалилась
		perror("fopen");
		exit(1);
	}
	printf("\tЧтение файла: %s\n", IFILE);


	register int inWord = NO; // Почему не short int?
	char c; // Было у Кернигана и Ритчи int

	int WLen = 0;
	char out[100] = {'\0'};

	while((c = getc(f)) != EOF)
		if(isspace(c) || c == '\n')
		{
			inWord = NO;
			++CountSpace;

//Для вывода
			if (WLen)
			{
				out[WLen] = '\0';
				printf("%s %d\n", out, WLen);
			}
//

			WLen = 0;
		}
		else
		{
			out[WLen] = c;
			++WLen;

			if(inWord == NO)
			{

				inWord = YES;
				++CountWord;
			}
		}
	printf("\tПрочитано слов: %d. Найдено пробелов/переносов: %d\n", CountWord, CountSpace-1);
	return 0;
}
