#include<stdio.h>
#include<stdlib.h>
char * get_str(int n)
{
    char * str = malloc(n*sizeof(char));
    for(int i=0;i<n;i++)
    {
       str[i] = getchar();
    }
    return str;
}
int main()
{
    char* a = get_str(10);
    for(int i=0;i<10;i++)
    {
        printf("%c",a[i]);
    }
    free(a);
}