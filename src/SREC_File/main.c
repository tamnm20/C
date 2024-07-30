#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
//srec_file/example.srec
void help() {
    printf("Usage: srecord_parser <input_file>\n");
    printf("Parses an S-record format file and generates an output file named \"Output.txt\".\n");
    printf("The output file will contain lines composed of the order number, address, and data, separated by spaces.\n");
}
// Hàm kiểm tra checksum của bản ghi S-record
int check_checksum(const char *line) {
    int length = strlen(line);
    int sum = 0;
    int i;

    // Tính tổng của tất cả các byte (ngoại trừ 'S' và checksum cuối cùng)
    for (i = 2; i < length - 2; i += 2) {
        int value;
        sscanf(line + i, "%2x", &value);
        sum += value;
    }

    // Tính checksum
    sum = (sum & 0xFF) ^ 0xFF;
    int checksum;
    sscanf(line + length - 2, "%2x", &checksum);

    return sum == checksum;
}

// Hàm phân tích tệp S-record
void parse_srecord(const char *filename) {
    FILE *input = fopen(filename, "r");
    FILE *output = fopen("Output.txt", "w");

    if (!input) {
        perror("Error opening input file");
        return;
    }
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int order_number = 1;

    while (fgets(line, sizeof(line), input)) {
        if (line[0] != 'S') {
            fprintf(stderr, "Error: Invalid line format - %s", line);
            continue;
        }

        // Kiểm tra checksum
        if (!check_checksum(line)) {
            fprintf(stderr, "Error: Checksum mismatch - %s", line);
            continue;
        }

        // Phân tích loại bản ghi và địa chỉ/dữ liệu
        char record_type;
        int address;
        char data[256];

        if (sscanf(line, "S%c%4x%[^\n]", &record_type, &address, data) != 3) {
            fprintf(stderr, "Error parsing line - %s", line);
            continue;
        }

        fprintf(output, "%d %04X %s\n", order_number++, address, data);
    }

    fclose(input);
    fclose(output);
    printf("Parsing complete. Output written to Output.txt\n");
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
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
