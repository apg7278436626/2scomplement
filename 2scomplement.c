#include<stdio.h>
int main()
{
    int num;
    printf("Enter a Number : ");
    scanf("%d",&num);
    int decimal = (~num)+1;
    printf("2s complement in decimal is %d\n",decimal);
    printf("2s complement of %d number is ",num);
    for(int i=0;i<32;i++)
    {
        if(((~num +1)) & ( 1 << 31-i))
        printf("1");
        else
        printf("0");
    }
    printf("\n");
    return 0;
}
