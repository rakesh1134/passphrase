#include <string>
#include <cstdlib>
#include <stdio.h>

void fun()
{
	FILE* fp;
	errno_t er = fopen_s(&fp, "testfile1.txt", "r");
	char buffer[5*1024] = {'\0'};
	if (fp == NULL)
		exit(0);
	int ch;
	int i = 0;
	do
	{
		ch = fgetc(fp);
		if (feof(fp))
			break;
		//printf("%c", ch);
		buffer[i++] = (char)ch;

	} while (true);

	char* p = buffer;
	while (*p != '\0')
	{
		if(isalpha(*p))
		{
			char* endp = p + 16;
			while (p != endp)
			{
				printf("%c", *p++);
			}
			break;
		}
		else if(*p == '-' || isdigit(*p))
		{
			char sign = '+';
			if (*p == '-')
				sign = '-';
			char* begnum = p;
			if(sign == '-')
				++p;
			int offset;
			char num[10] = {'\0'};
			int j = 0;
			while (isdigit(*p))
			{
				num[j++] = *p++;
			}
			offset = atoi(num);
			printf("%d\n", offset);
			if (sign == '-')
				p = begnum - offset;
			else
				p = begnum + offset;
		}
	}
	fclose(fp);
}

int main()
{	
	fun();
}
