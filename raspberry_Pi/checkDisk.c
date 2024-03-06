#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

double get_disk_usage() {
    FILE* fp = popen("df | awk '/dev\\/sda1/ {print $5}'", "r");
    if (fp == NULL) {
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }

    char output[16];
    fgets(output, sizeof(output), fp);
    pclose(fp);

    return atof(output);
}

int main() {
      while (1) {
        double disk_usage = get_disk_usage();
        printf("Disk Usage: %.2f%%\n", disk_usage);
        sleep(1);  // Delay 1 giây trước khi lấy thông tin tiếp theo
    }
    return 0;
}