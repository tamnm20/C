#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	
	fp = fopen("C:\\Users\\TAMRD\\Documents\\C\\File_handling\\example.txt", "w");
	
	if(fp == NULL)
	{
		printf("Error!");
		exit(1);
	}
	
	fputs("Learning about File Handling", fp);
	
	fclose(fp);
	
	return 0;
}
