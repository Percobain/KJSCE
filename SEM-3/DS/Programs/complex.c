#include <stdio.h>
#include <math.h>

typedef struct {
    float real;
    float imaginary;
} complex;

complex create (float r, float i) {
    complex c;
    c.real = r;
    c.imaginary = i;
    return c;
}

complex add(complex n1, complex n2) {
    complex res;
    res.real = n1.real + n2.real;
    res.imaginary = n1.imaginary + n2.imaginary;
    return res;
}

void compare(complex n1, complex n2) {
    if (n1.real == n2.real && n1.imaginary == n2.imaginary) {
        printf("Both complex numbers are equal\n");
    } else if(n1.real>n2.real || n1.imaginary>n2.imaginary) {
        printf("Complex Number 1 > Complex Number 2\n");
    } else {
        printf("Complex Number 1 < Complex Number 2\n");
    }
}

complex multiply(complex n1, complex n2) {
    complex num;
    num.real = (n1.real * n2.real) - (n1.imaginary * n2.imaginary);
    num.imaginary = (n1.real * n2.imaginary) + (n1.imaginary * n2.real);
    return num;
}

void print(complex c) {
    printf("%.1f + %.1f i\n", c.real, c.imaginary);
}

int main() {
    complex n1, n2, result;
    int c;

    n1 = create(3.0, 4.0);
    n2 = create(1.0, 2.0);

    
    printf("Complex Number 2: ");
    print(n2);


    printf("\nEnter The Operation :-\n1) Create\n2) Add\n3) Compare\n4) Multiply\n");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
        printf("Enter real part of complex number 1\n");
        scanf("%f",&n1.real);
        printf("Enter imaginary part of complex number 1\n");
        scanf("%f",&n1.imaginary);

        printf("Complex Number 1: ");
        print(n1);

        printf("Enter real part of complex number 2\n");
        scanf("%f",&n2.real);
        printf("Enter imaginary part of complex number 2\n");
        scanf("%f",&n2);
        break;

        case 2:
        result = add(n1, n2);
        printf("Sum: ");
        print(result);
        break;

        case 3:
        compare(n1, n2);
        break;

        case 4:
        result = multiply(n1, n2);
        printf("Product: ");
        print(result);
        break;

        default:
        printf("\nWrong Input");
    } 
    return 0;
}