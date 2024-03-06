#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

double get_cpu_usage() {
    FILE* fp = popen("top -bn1 | awk '/%Cpu/ {print $2 + $4}'", "r");
    if (fp == NULL) {
        perror("Error executing CPU command");
        exit(EXIT_FAILURE);
    }

    char output[16];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    return atof(output);
}

double get_ram_usage() {
    FILE* fp = popen("free | awk '/Mem:/ {print ($3/$2)*100}'", "r");
    if (fp == NULL) {
        perror("Error executing RAM command");
        exit(EXIT_FAILURE);
    }

    char output[16];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    return atof(output);
}

double get_disk_usage() {
    FILE* fp = popen("df | awk '/dev\\/sda1/ {print $5}'", "r");
    if (fp == NULL) {
        perror("Error executing Disk command");
        exit(EXIT_FAILURE);
    }

    char output[16];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    return atof(output);
}

char* create_json(double cpu_usage, double ram_usage, double disk_usage) {
    char* json = (char*)malloc(256);  // 256 là một kích thước đủ lớn cho JSON

    sprintf(json, "{\"CPU Usage\": %.2f, \"RAM Usage\": %.2f, \"Disk Usage\": %.2f}", cpu_usage, ram_usage, disk_usage);

    return json;
}

int main() {
    while (1) {
        double cpu_usage = get_cpu_usage();
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        double ram_usage = get_ram_usage();
        printf("RAM Usage: %.2f%%\n", ram_usage);

        double disk_usage = get_disk_usage();
        printf("Disk Usage: %.2f%%\n", disk_usage);
      
       char* json_data = create_json(cpu_usage, ram_usage, disk_usage);

        printf("JSON Data: %s\n", json_data);

        free(json_data);  // Giải phóng bộ nhớ sau khi sử dụng

        sleep(1);  // Delay 1 giây trước khi lấy thông tin tiếp theo
    }

    return 0;
}
