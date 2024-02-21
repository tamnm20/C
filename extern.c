#include <stdio.h>

// int bcd2dec( num)
 // {
 // return ((num/16 * 10) + (num % 16));
 // }
 // // Convert from Decimal to BCD
 // int dec2bcd(byte num)
 // {
 // return ((num/10 * 16) + (num % 10));
 // }

int main() {
	float x = 27.055;
//	scanf("%d", &x);
	int t = (0b0111/16 * 10) + (0b0111 % 16);
	
	printf("%0.2f\n", x);
	printf("%d\n", t);
	
	return 0;
}