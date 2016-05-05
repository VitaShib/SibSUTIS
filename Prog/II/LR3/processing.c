#include "processing.h"

/*
void input(char *a, char *c, char *d)
{
	int i;
	printf(" paths: ");
	fgets(a, MAXSIZE, stdin);

	if ((slen(a) == 1))
	{
		printf("%sСтрока не введена%s\n", clBoldRed, clNormal);
		exit(1);
	}

	printf(" dir: ");
	fgets(c, MAXPATH, stdin);
	if (slen(c) == 1)
	{
		printf("%sПуть не введен%s\n", clBoldRed, clNormal);
		exit(1);
	}
	printf(" delim: ");
	scanf("%c", d);
//	scanf("%c%*c",&b);

	if (c[0] != '/')
	{
		printf("%sПуть dir не является абсолютным%s\n", clBoldRed, clNormal);
		exit(1);
	}

	a[slen(a) - 1] = '\0';
	c[slen(c) - 1] = '\0';

	for (i = slen(a)-1; i > 1; --i)
		if ((a[i]=='/')&&(a[i-1]=='/'))
		{
			printf("%sСтрока не корректна%s\n", clBoldRed, clNormal);
			exit(1);
		}

	for (i = slen(c)-1; i >= 1; --i)
		if ((c[i]=='/')&&(c[i-1]=='/'))
		{
			printf("%sПуть не корректен%s\n", clBoldRed, clNormal);
			exit(1);
		}

	if (c[slen(c) - 1] == '/')
		c[slen(c) - 1] = '\0';

	for (i=0; a[i]!='\0'; i++)
		if ((32>a[i]) || (a[i]==34) || (a[i]==42) || (a[i]==58) || (a[i]==60) || (a[i]==62) || (a[i]==63) || (a[i]==64) || (a[i]==92) || (126<a[i]))
		{
			printf("Строка содержит запрещенный заданием символ: \"%c\"\n", a[i]);
			printf("Запрещенный заданием символ по счету: \"%d\"\n", i);
			exit(1);
		}

	for (i=0; c[i]!='\0'; i++)
		if ((32>c[i]) || (c[i]==34) || (c[i]==42) || (c[i]==58) || (c[i]==60) || (c[i]==62) || (c[i]==63) || (c[i]==64) || (c[i]==92) || (126<c[i]))
		{
			printf("Путь содержит запрещенный заданием символ: \"%c\"\n", c[i]);
			printf("Запрещенный заданием символ по счету: \"%d\"\n", i);
			exit(1);
		}

	if ((32 > *d) || (126 < *d))
	{
		printf("%sВведен запрещенный разделительный символ%s\n",clBoldRed,clNormal);
		exit(1);
	}
	return;
}*/

void check(char *pat, char *dir, char del)
{
	char *RAW[MAXSIZE];
	int Z = 0, i;
	Z = stok(pat, del, RAW);
	for (i = 0; i < Z; i++)
	{
		if (slen(RAW[i]) > (MAXPATH - 2))
		{
			printf("%sПолучен путь (%d) длина которого больше разрешенной%s\n", clBoldRed, i + 1, clNormal);
			exit(1);
		}
		if (( (RAW[i][0]) != '~') && ( (RAW[i][0]) != '/'))
		{
			printf("%sПолучен путь (%d) который не является частью фс unix%s\n", clBoldRed, i+1,clNormal);
			exit(1);
		}
	}
	suntok(pat, del, RAW, Z);
}

int Researcher(char *Str)
{
	
	int isipv4(char *str)
	{
		char *EL[MAXSIZE];
		int i, j;
		if ((7 > slen(str)) || (15 < slen(str)))
			return 0;
		int Z = stok(str, '.', EL);
		for (i = 0; i < Z; ++i)
		{
			for (j = 0; EL[i][j] != '\0'; ++j)
			{
				if (myisdigit(EL[i][j]))
					continue;
				else
				{
					suntok(str, '.', EL, Z);
					return 0;
				}
			}
			if (255 < myatoi(EL[i]))
			{
				suntok(str, '.', EL, Z);
				return 0;
			}
		}
		suntok(str, '.', EL, Z);
		return 1;
	}
	
	int isdomain(char *str)
	{
		char d_ru[] = "ru";
		char d_com[] = "com";
		char d_org[] = "org";
		char *EL[MAXSIZE];
		int i;
		if (6 > slen(str))
			return 0;
		int Z = stok(str, '.', EL);
		if (!((scmp(EL[Z - 1], d_ru) == 0) || (scmp(EL[Z - 1], d_com) == 0) || (scmp(EL[Z - 1], d_org) == 0)) )
			return 0;
		suntok(str, '.', EL, Z);
		if (3 != Z)
			return 0;
		for (i = 0; str[i] != '\0'; i++)
		{
			if (!((str[i] >= 'A')&&(str[i] <= 'Z') || ( (str[i] >= 'a')&&(str[i] <= 'z')) || str[i] == '.' ))
				return 0;
		}
		return 1;
	}
	
	int ispath(char *str)
	{
		if (1 > slen(str))
			return 0;
		if ( ( (str[0]) != '~') && ( (str[0]) != '/') )
		{
			if (str[0] != '@')
				return 0;
			else
				if (!(isipv4(&str[1]) || isdomain(&str[1])))
					return 0;
		}
		return 1;
	}
	
	int isservice(char *str)
	{
		char *EL[MAXSIZE];
		int i;
		if ((str[0] == '*') || (str[0] == '.') || (str[slen(str)-1] == '.'))
			return 0;
		if (3 > slen(str))
			return 0;
		int Z = stok(str, '.', EL);
		suntok(str, '.', EL, Z);
		if (2 != Z)
			return 0;
		for (i = 0; str[i] != '\0'; i++)
		{
			if (!((str[i] >= 'A')&&(str[i] <= 'Z') || ( (str[i] >= 'a')&&(str[i] <= 'z')) || (str[i] == '.') || (str[i] == '*') ))
				return 0;
		}
		return 1;
	}

	if (Str[0] == '#')
		return 4;
	if (Str[0] == '+')
		if (isipv4(&Str[1]) || isdomain(&Str[1]))
			return 2;
	if (ispath(Str))
		return 1;
	if (isservice(Str))
		return 0;
	return -1;
}

void SplitStr(char *text, stu *sig)
{
	char word[MAXPATH]= {' '};
	int CountWord = 0, i, inWord = 0, WLen = 0, count = 0;

	for (i=0; text[i] != '\0'; i++)
	{
		if (myisspace(text[i]) || text[i] == '\n')
		{
			inWord = 0;
			if (WLen)
			{
				word[WLen] = '\0';
				sig[count].value = (char*)malloc((WLen + 1) * sizeof(char));
				sig[count].id = Researcher(word);
				scpy(sig[count].value, word);
				count++;
			}
			word[0] = text[i];
			word[1] = '\0';
			sig[count].value = (char*)malloc(2 * sizeof(char));
			sig[count].id = 3;
			scpy(sig[count].value, word);
			count++;
			WLen = 0;
		}
		else
		{
			word[WLen] = text[i];
			++WLen;
			if(inWord == 0)
			{
				inWord = 1;
				++CountWord;
			}
		}
	}
}

void process(char *Text, char *dir, stu *Sign)
{
	void OverwritePath(char *pat, char *dir)
	{
		int R = 0, j, k, dLEN, pLEN;
		char *TOK[MAXSIZE];
		char *a;
		pLEN = slen(pat);
		dLEN = slen(dir);

		R = stok(pat , '/', TOK);
		for (j = 0; j < R; j++)
		{
			if ((j == 0) && (slen(TOK[j]) > 1) && (TOK[j][0] == '~'))
			{
				for (a = pat + pLEN; a > TOK[j]; --a)
					*(a + dLEN) = *a;
				scpy(TOK[j], dir);
				*(TOK[j] + dLEN) = '/';
				for (k = j - 1; k < R; k++)
					TOK[k] += dLEN;
			}
		}
		suntok(pat, '/', TOK, R);
		return;	
	}
//	OverwritePath(pat, dir);
	SplitStr(Text, Sign);
	return;
}


/*
int main()
{
	char DELIM = 0;
	char PATHS[MAXSIZE+MAXSIZE*MAXCNT] = {'\0'};
	char DIR[MAXSIZE] = {'\0'};

	input(PATHS, DIR, &DELIM);
	process(PATHS, DIR, DELIM);
	check(PATHS, DIR, DELIM);
	output(PATHS);
	return 0;
}*/

