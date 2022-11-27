#include "complex.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

complex InitComplex(unsigned int complex_size, int inp_mode)
{
    complex temp;
    temp.size = complex_size;
    temp.coeff = (Element *)malloc(complex_size * sizeof(Element));
    //assert(temp.coeff != NULL);
    
    //just for filling the coefficients easily
    temp.position=0;
    
    //if inp_mode is 1 , we take input from stdin and store coeffs accordingly
    if (inp_mode)
    {
        for (int i = 0; i < complex_size; i++)
        {
            scanf("%f", &temp.coeff[i]);
        }
        temp.position=complex_size-1;
    }
    return temp;
}

void AddCoeff(Element _x, complex *_a)
{
    //printf("%d\n",_a->position);
    //assert(_a->position < _a->size);
    _a->coeff[_a->position] = _x;
    _a->position++;
}

complex add(const complex _a, const complex _b)
{
    // assert(_a.size == _b.size);
    //printf("Entered add function\n");

    //to initialise an empty complex _c
    complex _c = InitComplex(_a.size,0);
    //PRINT(_c);
    
    int pos = 0;
    while (pos < _a.size){
        AddCoeff(_a.coeff[pos] + _b.coeff[pos], &_c);
        pos++;
    }
        //printf("%d\n", pos);
        

    return _c;
}

complex sub(const complex _a, const complex _b)
{
    // assert(_a.size == _b.size);
    complex _c = InitComplex(_a.size,0);
    int pos = 0;
    while (pos < _a.size){
        AddCoeff(_a.coeff[pos] - _b.coeff[pos], &_c);
        pos++;
    }

    return _c;
}

double mod(const complex _a)
{
    double sqsum = 0;
    int pos = 0;

    while (pos < _a.size){
        sqsum += _a.coeff[pos] * _a.coeff[pos];
        pos++;
    }

    return sqrt(sqsum);
}

double dot(const complex _a, const complex _b)
{
    double x;
    int pos = 0;

    while (pos < _a.size){
        x += _a.coeff[pos] * _b.coeff[pos];
        pos++;
    }

    return x;
}

double COS(const complex _a, const complex _b)
{
    return (dot(_a, _b)) / (mod(_a) * mod(_b));
}

void print(const complex _a)
{
    for (int i = 0; i < _a.size; i++)
    {
        printf("%.2f ", _a.coeff[i]);
    }
    printf("\n");
}


