#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr;
	int id;
	char name[30];
	
	fptr = fopen("Infor.txt", "w+"); 
	if (fptr== NULL)
	{
		printf("File khong ton tai. \n"); 
		exit(1);
	}
	
	printf("Nhap id: ");
	scanf("%d", &id);
	fprintf(fptr, "Id = %d\n", id);
	
	printf("Nhap name: ");
	scanf("%s", name);
	fprintf(fptr, "Name = %s\n", name);
	
	fclose(fptr);
	return 0;
}