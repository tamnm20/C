// #include<stdio.h>

// int main()
// {
    // static char *s[] = {"black", "white", "pink", "violet"};
    // printf("Addr s = %p\n",(void*)&s[0]);
    // char **ptr[] = {s+3, s+2, s+1, s}, ***p;
    // p = ptr;
    // ++p;
    // printf("%s\n", **p+1);
    // return 0;
// }
#include<stdio.h>
#include<stdint.h>
uint8_t *aptr1;
uint8_t *aptr2;

void swap(){
    uint8_t temp = *aptr1;
    *aptr1 = *aptr2;
    *aptr2 = temp;
}

int main(){
    uint8_t a1 =10;
    uint8_t a2 =20;
    aptr1 = &a1;
    aptr2 = &a2;
    printf("con tro aptr1 tro den a1 = %d\n",*aptr1);
    printf("con tro aptr2 tro den a2 = %d\n",*aptr2);
    swap();
    printf("con tro aptr1 tro den a1 = %d\n",*aptr1);
    printf("con tro aptr2 tro den a2 = %d\n",*aptr2);
}