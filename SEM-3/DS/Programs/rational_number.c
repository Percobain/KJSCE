#include <stdio.h>

struct rational {
    int numerator;
    int denominator;
} rational;

struct rational create() {
    struct rational rational;
    printf("Enter numerator: ");
    scanf("%d", &rational.numerator); 
    printf("Enter denominator: ");
    scanf("%d", &rational.denominator);
    if (rational.denominator == 0) {
        printf("Denominator cannot be zero. Please enter a valid denominator.\n");
        return create();
    }
    return rational;
}

struct rational add(struct rational r1, struct rational r2) {  
    struct rational result;
    result.numerator = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);
    result.denominator = r1.denominator * r2.denominator;
    return result;
}

struct rational multiply(struct rational r1, struct rational r2) {
    struct rational result;
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    return result;
}

int compare(struct rational r1, struct rational r2) {
    if ((r1.numerator * r2.denominator) > (r2.numerator * r1.denominator)) {
        return 1;
    } else if ((r1.numerator * r2.denominator) < (r2.numerator * r1.denominator)) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int c;
    struct rational r1, r2, sum, product;

    while (1) {
        printf("Menu:\n");
        printf("1. Create Rational Numbers\n");
        printf("2. Add Rational Numbers\n");
        printf("3. Multiply Rational Numbers\n");
        printf("4. Compare Rational Numbers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter rational number 1: \n");
                r1 = create();
                printf("Enter rational number 2: \n");
                r2 = create();
                break;
            case 2:
                    sum = add(r1, r2);
                    printf("Sum: %d/%d\n", sum.numerator, sum.denominator);
                break;
            case 3:
                    product = multiply(r1, r2);
                    printf("Product: %d/%d\n", product.numerator, product.denominator);
                break;
            case 4:
                    if (compare(r1, r2) == 1) {
                        printf("r1 > r2\n");
                    } else if (compare(r1, r2) == -1) {
                        printf("r1 < r2\n");
                    } else {
                        printf("r1 = r2\n");
                    }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}