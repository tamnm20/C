// #include <stdio.h>
// #include <string.h>

// int main() {
    // const char *source = "Hello, World!";
    // char destination[20];

    // // Đặt con trỏ nguồn tới vị trí bắt đầu của chuỗi con "World"
    // const char *srcSubstring = source + 7;

    // // Sao chép chuỗi con từ srcSubstring sang destination
    // memcpy(destination, srcSubstring, strlen(srcSubstring) + 1);

    // // In ra chuỗi đã sao chép
    // printf("Sao chep: %s\n", destination);

    // return 0;
// }


// #include <stdio.h>
// #include <string.h>

// int main() {
    // // const char *source = "Hello, World!";
    // // char destination[20];

    // // // Tìm vị trí của chuỗi con "World" trong chuỗi nguồn
    // // const char *substring = strstr(source, "World");

    // // if (substring != NULL) {
        // // // Sao chép từ vị trí của chuỗi con đến hết chuỗi nguồn
        // // memcpy(destination, substring, strlen(substring)+1);

        // // // In ra chuỗi đã sao chép
        // // printf("Sao chep: %s\n", destination);
    // // } else {
        // // printf("Chuỗi con không tìm thấy.\n");
    // // }
	// int i;
	// char Cs;
	// char Write_Buf[3] = {'t','a'};
	// unsigned char Buf[3] = {0,};
	// memset(Buf, (char)0x00 ,3);
	// memcpy(Buf,&Write_Buf[1],2);
	// memcpy(&Buf[3],&Write_Buf[3],2);

	// for (i = 0; i < 2; i++)
	// {
		// Cs ^= Buf[i];
	// }
	// Buf[2] = Cs;

	// printf("%s\n", Write_Buf);


    // return 0;
// }

#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char Cs = 0;
	unsigned char *Write_Buf = "Hello, World!";
    //char Write_Buf[3] = {'t', 'a', '\0'};
    unsigned char Buf[3] = {0};

    memset(Buf, 0x00, 3);
    memcpy(Buf, &Write_Buf[1], 3);  // Sửa lỗi tại đây

    for (i = 0; i < 3; i++) {
        Cs ^= Buf[i];
    }
    Buf[2] = Cs;
	printf("%c\n", Cs);
    printf("%s\n", Write_Buf);
	 for (i = 0; i < 3; i++) {
        printf("%c", Buf[i]);
    }
	printf("\n");
    return 0;
}

void Diag_Write_Transfer_Data(U8 *Buf)
{
	SEG_XDATA U32	 address = (U32)0x00U;
	static SEG_XDATA U32 cnt   = (U32)0x00U;
	static SEG_XDATA U32 erase_cnt   = (U32)0x00U;
	static SEG_XDATA U32 lotation = (U32)0x01U;
	static SEG_XDATA volatile U8 Buf1[256] = {0U,};
	static SEG_XDATA volatile U8 Buf2[256] = {0U,};
	static SEG_XDATA volatile U8 buf1_index = 253U;
	static SEG_XDATA volatile U8 buf2_index = 3U;
	static SEG_XDATA volatile U8 loop_index = 0U;
	SEG_XDATA U8 Write_Buf[256] = {0U,};

	if ((cnt % (U32)16) == (U32)0)
	{
		Flash_EraseSector(erase_cnt*(U32)0x1000U);	
		erase_cnt++;
		Wait_ms(100U);
	}
	if ( cnt == 0x00U)
	{
		memset(Buf1, (char)0xFFU ,256U);	
		memset(Buf2, (char)0xFFU ,256U);	
		memcpy(Buf1,&Buf[1U],253U);
	}
	else
	{
		if ( loop_index == 0U)
		{
			if ( buf1_index == 1U)
			{
				memcpy(&Buf1[buf1_index],&Buf[1U],253U);
				//memcpy(Buf1,Buf,256U);
				buf1_index = 254U;
				buf2_index = 2U;
				loop_index = 1U;
				lotation++;
			}
			else
			{
				memcpy(Buf2,&Buf[1U],253U);
				memcpy(&Buf1[buf1_index],Buf2,buf2_index);
				
				address = (cnt-lotation)*(U32)256;
				memcpy(Write_Buf,Buf1,256U);

				Flash_Write(address,Write_Buf,(U16)256);

				memset(Buf1, (char)0xFFU ,256U);	
				memcpy(Buf1,&Buf2[buf2_index],buf1_index);
				memset(Buf2, (char)0xFFU ,256U);	
				buf1_index-=3U;
				buf2_index+=3U;
			}
		}
		
		else if ( loop_index == 1U)
		{
			if ( buf1_index == 2U)
			{
				memcpy(&Buf1[buf1_index],(Buf+1U),253U);
				buf1_index = 255U;
				buf2_index = 1U;
				loop_index = 2U;
				lotation++;
			}
			else
			{	
				memcpy(Buf2,&Buf[1U],253U);
				memcpy(&Buf1[buf1_index],Buf2,buf2_index);
				
				address = (cnt-lotation)*(U32)256;
				memcpy(Write_Buf,Buf1,256U);

				Flash_Write(address,Write_Buf,(U16)256);

				memset(Buf1, (char)0xFFU ,256U);	
				memcpy(Buf1,&Buf2[buf2_index],buf1_index);
				memset(Buf2, (char)0xFFU ,256U);	
				buf1_index-=3U;
				buf2_index+=3U;
			}
				
		}
		else if ( loop_index == 2U )
		{
			if ( buf1_index == 0U)
			{
				memcpy(&Buf1[buf1_index],&Buf[1U],253U);
				buf1_index = 253U;
				buf2_index = 3U;
				loop_index = 0U;
				lotation++;
			}
			else
			{
				memcpy(Buf2,&Buf[1U],253U);
				memcpy(&Buf1[buf1_index],Buf2,buf2_index);
				
				address = (cnt-lotation)*(U32)256;
				memcpy(Write_Buf,Buf1,256U);

				Flash_Write(address,Write_Buf,(U16)256);

				memset(Buf1, (char)0xFFU ,256U);	
				memcpy(Buf1,&Buf2[buf2_index],buf1_index);
				memset(Buf2, (char)0xFFU ,256U);	
				buf1_index-=3U;
				buf2_index+=3U;
			}
		}
		else
		{
		}
		
	}
	cnt++;
}
