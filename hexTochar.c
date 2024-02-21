#include <stdio.h>
#include <stdint.h>

// Hàm chuyển đổi giá trị hex thành chuỗi char
void hexToChar(uint8_t value, char *result) {
    sprintf(result, "%X", value);
}

int main() {
    uint8_t hexValue = 0x04; // Giá trị hex cần chuyển đổi
    char charString[9]; // Chuỗi lưu giá trị char

    hexToChar(hexValue, charString); // Gọi hàm chuyển đổi

    // In ra giá trị char
    printf("Char value: %s\n", charString);
	for(int i=0;i<strlen(charString);i++){
		printf("%d %c\n",i, charString[i]);
	}
    return 0;
}