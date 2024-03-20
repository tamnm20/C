#include <stdio.h>

int main()
{
	int input_char;
	FILE *my_stream;
	char my_filename [] = "example.txt"; 
	int eof_status, error_status;
	
	printf ("Opening file...\n");
	my_stream = fopen (my_filename, "w+"); 
	fprintf (my_stream, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	
	/* Seeking position 25 = '2' */ 
	fseek (my_stream, 25, SEEK_SET);
	input_char = getc(my_stream);
	printf ("Character = '%c'.\n\n", input_char);
	
	/* check EOF*/
	eof_status = feof (my_stream);
	printf ("feof returns %d.\n\n", eof_status);
	
	/* Check error*/
	error_status = ferror (my_stream); 
	printf("ferror returns %d.\n\n", error_status);
	
	fclose (my_stream);
	return 0;
}
