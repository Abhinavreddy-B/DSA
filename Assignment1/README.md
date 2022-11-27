# compiling:
Reach the parent folder and simply use command:
```
$ make
(or)
$ make all
```
in terminal

# Q1-details
* to make only Q1 seperately:
```
$ make 1
```
* run the executable as:
```
$ ./q1.out
```
* To exit the programme use: 
```
exit
```
* remaining functionality is according to the given input formats in PDF

# Q2-details
* to make only Q2 seperately:
```
$ make 2
```
* run the executable as:
```
$ ./q2.out
```
* changes in function name:
```
cos has been changed to COS
(conflict with math.h library)
```
* Other extra functions:
```
InitComplex(unsigned int complex_size, int inp_mode) - to initate a complex number of size complex_size.
if inp_mode is 0, then takes input from stdin
else just initiate the array.

void AddCoeff(Element _x, complex *_a) - used internaly , externally of no use.
```
* input format: As given in the PDF
* output format:
prints floats of 2 decimals

# Q3-details
* **Attempted Bonus part also**
* to make only Q3 seperately:
```
$ make 3
```
* run the executable as:
```
$ ./q3.out
```
* input format: As given in the Sample Driver code