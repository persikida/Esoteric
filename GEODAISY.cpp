/*

	НИЗКОУРОВНЕВЫЙ ЯЗЫК ПРОГРАММИРОВАНИЯ GEODAISY.
	Author: MRWARHEAD.
	All rights reserved. In development.

	(COPYRIGHT) 2014.

*/

/*

	ТРЕБУЕТСЯ ДЛЯ РАЗРАБОТКИ:

	1. Перевод команд на 64 битную архитектуру.
	2. Оптимизация циклов.
	3. Оптимизация.
	4. Упрощение всех символов для упрощения разработки программ.
	5. Встроенный интерпретатор C# в GEODAISY.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF	1000

int main(int argc, char *argv[])
{
	printf("[GEODAISY][WELCOME] Copyright 2014. Author: MRWARHEAD.\n");
	//if (argc == true) { puts("[GEODAISY][COMPILE] File of source was not found."); return false; }
	char* filename = argv[1]; 
	FILE* f = fopen(filename,"r");
	char program[32768];
	fgets(program, 32768,f);
	FILE* source = fopen("geodaisy.tmp.c","w");
	fputs("int main(){char* p; char s[1000]; p=s;", source);
	for(int i=0;i<strlen(program);i++)
	{
		switch (program[i])
		{
			case '$': fputs("*p=getchar();", source);
			case '^': fputs("for(p=-1;p<DEF;p++){", source);
			case '|': fputs("}", source);
			case '+': fputs("memory = memory+1024;", source);
			case '-': fputs("memory = memory-1024;", source);
			default: putchar(program[i]), puts("[GEODAISY][COMPILE] Unknown symbol detected in source.");
		}
	system("pause");
	fputs("}", source);//, fclose(source), fclose(f);
	system("gcc -O2 -march=native geodaisy.tmp.c "), system("del geodaisy.tmp.c"), system("rm geodaisy.tmp.c");
	return false;
	}
}
