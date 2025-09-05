#include <stdio.h>
#include <math.h>
#define SEIRES_NUMB_ZERO 1
#define START_NUMB 0
#define CORRECT_EPS 1

typedef enum {
    CORRECT_INPUT,
    INCORRECT_INPUT,
} StatusInput;
StatusInput inputData(double* eps);
void calculationOfSumSeires(double eps);


int main() {
    double eps;
    StatusInput statusInput = inputData(&eps);
    if (statusInput == INCORRECT_INPUT){
        printf("Incorrect input");
    }
    else {
        calculationOfSumSeires(eps);
    }
    return statusInput;
}

void calculationOfSumSeires(double eps) {
    int n = START_NUMB;
    double seires = SEIRES_NUMB_ZERO;
    double sumseires = SEIRES_NUMB_ZERO;
    while ((fabs(seires)) > eps) {
        n++;
        seires = (-1)* seires * pow(n,-1);
        sumseires += seires;
    }
    printf("%.6lf",sumseires);
}
StatusInput inputData(double* eps) {
    StatusInput statusInput;
    if (scanf("%lf", eps) == CORRECT_EPS) {
        statusInput = CORRECT_INPUT;
    }
    else {
        statusInput = INCORRECT_INPUT;
    }
    return statusInput;
}

