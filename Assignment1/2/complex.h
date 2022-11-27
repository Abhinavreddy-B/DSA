#ifndef _COMPLEX_H_
#define _COMPLEX_H_

typedef float Element;

typedef struct _complex complex;

/**
 * @brief structure to hold a n-ary complex number
 * @param size is the value of n
 * @param position the number of elements whose value is filled
 * @param coeff the pointer to the array of coefficients of complexes
*/ 
struct _complex{
    unsigned int size;
    unsigned int position;
    Element* coeff;
};

/**
 * @brief to initalise a complex structure
 * @param complex_size the size of complex number to be initalised
 * @param inp_mode if 0 then does not initialse the coefficients , else initialises the coefficients with the values at the input (stdin)
 * @return a complex structure
*/
complex InitComplex(unsigned int complex_size, int inp_mode);

/**
 * @brief used internally for implementation
 * @param _x the value of coefficient to be added
 * @param _a pointer to the complex structure
*/
void AddCoeff(Element _x,complex* _a);                  //used internally for implementation

/**
 * @brief add 2 complex data types
 * @param _a first complex structure
 * @param _b second complex structure
 * @return a complex structure with the sum of both complexes
*/
complex add(const complex _a,const complex _b);

/**
 * @brief substract complex data types
 * @param _a first complex structure
 * @param _b second complex structure
 * @return a complex structure with the difference( _a - _b ) of both complexes
*/
complex sub(const complex _a,const complex _b);

/**
 * @brief find MOD of a complex structure
 * @param _a the complex structure
 * @return the answer as a double
*/
double mod(const complex _a);

/**
 * @brief find dot product
 * @param _a first complex structure
 * @param _b second complex structure
 * @return the answer as a double
*/
double dot(const complex _a,const complex _b);

/**
 * @brief find cosine product
 * @param _a first complex structure
 * @param _b second complex structure
 * @return the answer as a double
*/
double COS(const complex _a,const complex _b);

/**
 * @brief to print a complex structure
 * @param _a the complex structure to be printed
*/
void print(const complex _a);

#endif