#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo sys_info;

    // Lấy thông tin hệ thống
    if (sysinfo(&sys_info) != 0) {
        perror("sysinfo");
        return 1;
    }

    // In thông tin về RAM
    printf("Total RAM: %ld MB\n", sys_info.totalram / (1024 * 1024));
    printf("Free RAM : %ld MB\n", sys_info.freeram / (1024 * 1024));
    printf("Used RAM : %ld MB\n", (sys_info.totalram - sys_info.freeram) / (1024 * 1024));

    return 0;
}
