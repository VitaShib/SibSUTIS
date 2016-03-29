/*
Требуется реализовать на языке C две библиотеки для работы с бинарным деревом
поиска (Binary search tree) и хеш-таблицей (Hash table). Ключом в обоих случаях
является строка (char []), а значением целое число (int).
Функции для работы с бинарным деревом поиска должны быть помещены в файлы
bstree.c (реализация функций) и bstree.h (объявление функций). В файлах необходимо
реализовать следующие функции:
	 struct bstree *bstree_create(char *key, int value)
	 void bstree_add(struct bstree *tree, char *key, int value)
	 struct bstree *bstree_lookup(struct bstree *tree, char *key)
	 struct bstree *bstree_min(struct bstree *tree)
	 struct bstree *bstree_max(struct bstree *tree)
Функции для работы с хеш-таблицей должны быть помещены в файлы hashtab.c
(реализация функций) и hashtab.h (объявление функций). В файлах необходимо
реализовать следующие функции:
	 unsigned int hashtab_hash(char *key)
	 void hashtab_init(struct listnode **hashtab)
	 void hashtab_add(struct listnode **hashtab, char *key, int value)
	 struct listnode *hashtab_lookup(struct listnode **hashtab, char *key)
	 void hashtab_delete(struct listnode **hashtab, char *key)
Цель работы — провести экспериментальное исследование эффективности бинарных
деревьев поиска и хеш-таблиц.

Вариант 3:
	1: Эксперимент 1
	2: Эксперимент 4
	3: Эксперимент 6 - хеш-функции KP, FNV

Эксперимент 1 
Сравнение эффективности поиска элементов в бинарном дереве поиска и хеш-
таблице в среднем случае (average case)
Требуется заполнить таблицу 1 и построить графики зависимости времени t
выполнения операции поиска (lookup) элемента в бинарном дереве поиска и хеш-
таблице от числа n элементов уже вставленных в словарь.
В качестве ключей использовать слова из романа Л.Н. Толстого «Война и Мир»
(можно использовать любой текстовый файл с большим числом слов). Файл включен
в архив.
В качестве искомого ключа следует выбрать случайное слово, которое уже было
добавлено в словарь.

На выходе таблица:
№ 1-20 | Количество элементов в словаре | Время выполнения функции bstree_lookup, с | Время выполнения функции hashtab_lookup, с


Эксперимент 4
Исследование эффективности поиска минимального элемента
в бинарном дереве поиска в худшем и среднем случаях
Требуется заполнить таблицу 4 и построить графики зависимости времени t
выполнения операции поиска минимального элемента в бинарном дереве поиска в
худшем и среднем случаях.
Анализ поведения в худшем случае: добавляем в словарь n слов - от больших к
меньшим (например, слова «zzzzzzzz», «yyyyyy», ...) и замеряем время поиска
минимального ключа.
Анализ поведения в среднем случае: добавляем в словарь n слов и замеряем время
поиска минимального ключа.

На выходе таблица:
№ 1-20 | Количество элементов в словаре | Время выполнения функции bstree_min в худшем случае, с | Время выполнения функции bstree_min в среднем случае, с


Эксперимент 6
Анализ эффективности хеш-функций
Требуется заполнить таблицу 6 и построить:
	 графики зависимости времени t выполнения операции поиска элемента
	в хеш-таблице от числа n элементов в ней для заданных хеш-функций X и Y
	(см. распределение вариантов)
	 графики зависимости числа q коллизий от количества n элементов
	в хеш-таблице для заданных хеш-функций X и Y (см. распределение вариантов)

№ 1-20 	| Количество элементов	|					Хеш-функция X								|					Хеш-функция Y
		|  в словаре			| Время выполнения функции hashtab_lookup, с | Число коллизий	| Время выполнения функции hashtab_lookup, с | Число коллизий

*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//#include "bstree.h"
//#include "hashtab.h"


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
