#include <stdio.h>
#include <stdint.h>

/*
	uint32_t temp =0; //temp. register

		if(pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber < 8){ //pin 0 - 7 CRL
			//1. Config mode and speed
			pGPIOHandle -> pGPIOx -> CRL &= ~(0xF << (4* pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber)); //clear bit
			temp = (pGPIOHandle->GPIO_pinConfig.GPIO_PinMode << (4* pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber));
			//2. Config output type or input type
			temp |= (pGPIOHandle->GPIO_pinConfig.GPIO_PinType << (4* (pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber)+2));
			pGPIOHandle -> pGPIOx -> CRL |= temp;
		}
		else{ //pin 8 - 15 CRH
			//1. Config mode and speed
			pGPIOHandle -> pGPIOx -> CRH &= ~(0xF << (4* (pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber - 8))); //clear bit
			temp = (pGPIOHandle->GPIO_pinConfig.GPIO_PinMode << (4* pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber- 8));
			//2. Config output type or input type
			temp |= (pGPIOHandle->GPIO_pinConfig.GPIO_PinType << (4* (pGPIOHandle-> GPIO_pinConfig.GPIO_PinNumber - 8)+2));
			//pGPIOHandle -> pGPIOx -> CRH |= temp;
			pGPIOHandle -> pGPIOx -> CRH |= 0x00200000UL;
		}
*/

// Hàm in s? nguyên du?i d?ng bin
void printBinary(uint32_t num) {
	int i =0;
    for (i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
    }
}

uint32_t temp =0; //temp. register
uint32_t CRH =0;
uint8_t GPIO_PinNumber =13;
uint8_t GPIO_PinMode = 3;
uint8_t GPIO_PinType = 0;

int main(void){
	CRH &= ~(0xF << (4* (GPIO_PinNumber - 8)));
	printf("Clear 4 bit in CRH: \n");
	printf("CRH in hex: 0x%08X\n", CRH);
    printf("CRH in bin: ");
    printBinary(CRH);
    printf("\n");
	
	temp = GPIO_PinMode << 4* ((GPIO_PinNumber - 8));
	printf("SET MODE: \n");
	printf("temp in hex: 0x%08X\n", temp);
    printf("temp in bin: ");
    printBinary(temp);
    printf("\n");
    
	temp |= GPIO_PinType << (4*(GPIO_PinNumber - 8) + 2);
	printf("SET CNF: \n");
	printf("temp in hex: 0x%08X\n", temp);
    printf("temp in bin: ");
    printBinary(temp);
    printf("\n");
    
	CRH |= temp;
	printf("FINAL CRH: \n");
	printf("CRH in hex: 0x%08X\n", CRH);
    printf("CRH in bin: ");
    printBinary(CRH);
    printf("\n");

	// CRH = 0x00200000;
	// printf("FINAL CRH2: \n");
	// printf("CRH in hex: 0x%08X\n", CRH);
    // printf("CRH in bin: ");
    // printBinary(CRH);
    // printf("\n");
	return 0;
}
