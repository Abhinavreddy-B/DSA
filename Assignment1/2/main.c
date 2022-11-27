#include "complex.h"
#include <stdio.h>
#include <string.h>

int main(){
    complex a,b;
    int n;
    char inp[10];
    scanf("%s",inp);
    scanf("%d",&n);
    a=InitComplex(n,1);
    if(!strcmp(inp,"MOD")){
        printf("%.2lf\n",mod(a));
    }else if(!strcmp(inp,"ADD")){
        b=InitComplex(n,1);
        print(add(a,b));
    }else if(!strcmp(inp,"SUB")){
        b=InitComplex(n,1);
        print(sub(a,b));
    }else if(!strcmp(inp,"DOT")){
        b=InitComplex(n,1);
        printf("%.2lf\n",dot(a,b));
    }else if(!strcmp(inp,"COS")){
        b=InitComplex(n,1);
        printf("%.2lf\n",COS(a,b));
    }
}