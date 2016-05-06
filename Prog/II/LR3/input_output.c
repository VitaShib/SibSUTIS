#include "input_output.h"

void interrogation(char *path, char *dir)
{
	int i;
	printf(" path syslog: ");
	fgets(path, MAXSIZE, stdin);
	
	if ((slen(path) == 1))
	{
		printf("\t%sПуть не введён%s\n", clBoldRed, clNormal);
		exit(1);
	}
	
	printf(" dir: ");
	fgets(dir, MAXSIZE, stdin);
	
	if ((slen(dir) == 1))
	{
		printf("\t%sdir не введён%s\n", clBoldRed, clNormal);
		exit(1);
	}
	if (dir[0] != '/')
	{
		printf("\t%sПуть dir не является абсолютным%s\n", clBoldRed, clNormal);
		exit(1);
	}
	path[slen(path) - 1] = '\0';
	dir[slen(dir) - 1] = '\0';

	for (i = slen(dir) - 1; i > 1; --i)
		if ((dir[i] == '/') && (dir[i - 1] == '/'))
		{
			printf("\t%sdit не корректен%s\n", clBoldRed, clNormal);
			exit(1);
		}
	
	
	return;
}

void Read(char *fname, char *textfile)
{
	FILE* f;
	if((f = fopen(fname, "r")) == NULL)
	{
		perror("fopen");
		exit(1);
	}
	unsigned int i = 0;
	int c;

	while((c = getc(f)) != EOF)
	{
		textfile[i] = c;
		i++;
	}
}

void Write(char *fname, stu *sign, int count)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		if (0 <= sign[i].id)
		{
			printf("%s", sign[i].value);
		}
	}
}


