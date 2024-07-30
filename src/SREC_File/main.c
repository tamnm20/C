#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int max_line = 0;

void help() {
    printf("Usage: srecord_parser <input_file>\n");
    printf("Parses an S-record format file and generates an output file named \"Output.txt\".\n");
    printf("The output file will contain lines composed of the order number, address, and data, separated by spaces.\n");
}
// Hàm kiểm tra checksum của bản ghi S-record
int check_checksum(const char *line, int num_line) {
    int length = strlen(line);
    unsigned int sum = 0;
    int i;

    // Tính tổng của tất cả các byte (ngoại trừ 'S' và checksum cuối cùng)
    for (i = 2; i < length - 4; i += 2) {
        int value;
        sscanf(line + i, "%2x", &value);
        printf("%2x ",value);
        sum += value;
    }
	printf("sum = %2x\n",sum);
    // Tính checksum
    sum = (sum & 0xFF) ^ 0xFF;
    int checksum;
    if(num_line==max_line)
	{
    	sscanf(line + length - 2, "%2x", &checksum);
	}
	else
	{
    	sscanf(line + length - 3, "%2x", &checksum);		
	}
	printf("sum = %2x, checksum = %2x\n",sum,checksum);
    return sum == checksum;
}

// Hàm phân tích tệp S-record
void parse_srecord(const char *filename) {
	int error = 0;
    FILE *input = fopen(filename, "r");
    FILE *output = fopen("Output.txt", "w");

    if (!input) {
        perror("Error opening input file");
        error=1;
    }
    else
    {
	    if (!output) {
	        perror("Error opening output file");
	        fclose(input);
	        error=1;
	    }
	}

	if(!error)
	{
		char line[MAX_LINE_LENGTH];
	    int num_line = 0;

		while (fgets(line, sizeof(line), input)) {
			max_line++;
		}
		rewind(input);
	    while (fgets(line, sizeof(line), input)) {
	    	num_line++;
	        if (line[0] != 'S') {
	            fprintf(stderr, "Error: Invalid line format - %s", line);
	        }
	
	        char record_type;
	        int byte_count, address;
	        char data[256];
	        if (sscanf(line, "S%c%2x%4x%s", &record_type, &byte_count, &address, data) != 4) {
	            fprintf(stderr, "Error parsing line - %s", line);
	        }
	        if(byte_count<3||byte_count>255)
	        {
	        	fprintf(stderr, "Error byte count - %s", line);
			}
	        // Kiểm tra checksum
	        if (!check_checksum(line, num_line)) {
	            fprintf(stderr, "Error: Checksum mismatch - %s", line);
	        }
	        
	        
	        // L?y ph?n d? li?u t? chu?i data (kh�ng t�nh checksum)
	        int data_length = (byte_count - 1) * 2 - 4; // T�nh d? d�i d? li?u hexa
	        char data_hex[256];
	        strncpy(data_hex, data, data_length);
	        data_hex[data_length] = '\0'; // �?m b?o chu?i k?t th�c
	
	        // Ghi d? li?u v�o t?p d?u ra
	        fprintf(output, "%d %04X %s\n", num_line, address, data_hex);
	    }
	
	    fclose(input);
	    fclose(output);
	    printf("\nParsing complete. Output written to Output.txt\n");		
	}
    
}


int main() {
    char filename[MAX_LINE_LENGTH];

    printf("Enter the path of the S-record file: ");
    if (fgets(filename, sizeof(filename), stdin)) {
        // Remove newline character if present
        size_t len = strlen(filename);
        if (len > 0 && filename[len - 1] == '\n') {
            filename[len - 1] = '\0';
        }
        parse_srecord(filename);
    } else {
        help();
    }

    return 0;
}
