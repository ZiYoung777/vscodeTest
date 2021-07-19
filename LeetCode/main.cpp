#include <vector>
#include <iostream>
using namespace std;

union A
{
    int a;
    char b[4];
};
struct B
{
    int a=0x00000202;
};

struct mybitfields
{
    unsigned short a : 4;
    unsigned short b : 5;
    unsigned short c : 7;
} test;
int main()
{
    int i,j,k;
    A a;
    a.a=0x01000000;
    a.b[3]=0;
    B b;
    test.a = 2;
    test.b = 3;
    test.c = 0;
    printf("%d,%d\n",i,a.a);
    return 0;
}