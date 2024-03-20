#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str1[10], str2[10], str3 [10];
	int year;
	FILE *fp;
	fp = fopen("baitapc.txt", "w+");
	printf("Vi tri con tro file: %ld\n", ftell(fp) );
	fputs("Nam nay la 2024", fp);
	rewind (fp);
	fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);
	
	printf("Doc chuoi 1:|%s|\n", str1 );
	printf("Doc chuoi 2:|%s|\n", str2 );
	printf("Doc chuoi 3:|%s|\n", str3 );
	printf("Vi tri con tro file: %ld\n", ftell(fp) );
	printf("Doc so nguyen: %d\n",year );
	
	fclose(fp);
	printf("Vi tri con tro file: %ld\n", ftell(fp) );
	return(0);
}