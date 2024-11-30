#include <stdio.h>

typedef struct rational {
    int num;
    int den;
} rat;

rat create() {
    rat r;
    printf("Enter the numerator: ");
    scanf("%d", &r.num);
    printf("Enter the denominator: ");
    scanf("%d", &r.den);

    if (r.den == 0) printf("Invalid denominator\n");
    return r;   
}

rat add(rat r1, rat r2) {
    rat r;
    r.num = (r1.num * r2.den) + (r2.num * r1.den);
    r.den = r1.den * r2.den;
    return r;
}

rat sub(rat r1, rat r2) {
    rat r;
    r.num = (r1.num * r2.den) - (r2.num * r1.den);
    r.den = r1.den * r2.den;
    return r;
}

rat mul(rat r1, rat r2) {
    rat r;
    r.num = r1.num * r2.num;
    r.den = r1.den * r2.den;
    return r;
}

int compare(rat r1, rat r2) {
    rat r;
    if ((r1.num * r2.den) > (r2.num * r1.den)) {
        return 1;
    }
    else if ((r1.num * r2.den) < (r2.num * r1.den)) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    int c;
    rat r1, r2, sum, diff, prod;

    while (1) {
        printf("1. Create\n2. Add\n3. Subtract\n4. Multiply\n5. Compare\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch(c) {
            case 1:
                printf("Rational Number 1: \n");
                r1 = create();
                printf("Rational Number 2: \n");
                r2 = create();
                break;
            
            case 2:
                sum = add(r1, r2);
                printf("Sum: %d/%d\n", sum.num, sum.den);
                break;

            case 3:
                diff = sub(r1, r2);
                printf("Difference: %d/%d\n", diff.num, diff.den);
                break;

            case 4:
                prod = mul(r1, r2);
                printf("Product: %d/%d\n", prod.num, prod.den);
                break;

            case 5:
                if (compare(r1, r2) == 1) printf("Rational Number 1 is greater\n");
                else if (compare(r1, r2) == -1) printf("Rational Number 2 is greater\n");
                else printf("Both are equal\n");
                break;
            
            case 6:
                return 0;
            
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}