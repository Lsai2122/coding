#include<stdio.h>
struct a
{
    char i[10];
    int j;
} b[2]={
    {"aai",1},
    {"ajay",2}
};
int main()
{
    char * m[2]={b[0].i,b[1].i};
    printf("%d",*(m[0]+1)<*(m[1]+1));
}