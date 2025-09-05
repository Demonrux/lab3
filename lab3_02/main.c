#include <stdio.h>
#include <math.h>
#define CORRCECT_INPUT_DATA 3
#define START_SUM_OF_AREAS 0
#define SPLIT_MULIPLIER 2
#define START_NUMBER_OF_SPLIT 1
#define ZERO 0

typedef enum {
    CORRECT_INPUT,
    INCORRECT_INPUT,
} StatusInput;
StatusInput inputData(double* a, double* b, double* eps);
void сalculationOfIntegrad(double a, double b, double eps);


int main() {
    double a = 0;
    double b = 0;
    double eps = 0;
    StatusInput statusInput = inputData(&a, &b, &eps);
    if (statusInput == INCORRECT_INPUT){
        printf("Incorrect input");
    }
    else {
        сalculationOfIntegrad(a, b, eps);
    }
    return statusInput;
}

void сalculationOfIntegrad(double a, double b, double eps) {
    double oldSumofareas = START_SUM_OF_AREAS;
    int numberOfSplits = START_NUMBER_OF_SPLIT;
    while (eps) {
        double copyA = a;
        double newSumOfAreas = START_SUM_OF_AREAS;
        int copyNumberOfSplits = numberOfSplits;
        double splitStep = (b - copyA) / copyNumberOfSplits;
        while (copyNumberOfSplits + 1 != ZERO) {
            copyA += splitStep;
            newSumOfAreas += (log(copyA) * splitStep);
            copyNumberOfSplits --;
        }
        copyA = a;
        numberOfSplits *= SPLIT_MULIPLIER;
        if (((log(copyA) * splitStep) <= eps) && (fabs(oldSumofareas - newSumOfAreas)) <= eps) {
            printf("%.6lf", newSumOfAreas);
            break;
        }
        oldSumofareas = newSumOfAreas;
    }
}

StatusInput inputData(double* a, double* b, double* eps) {
    StatusInput statusInput;
    if ((scanf("%lf%lf%lf", a, b, eps) != CORRCECT_INPUT_DATA) ||(*eps <= 0) || ((*a <= 0 ) || (*b <= 0 ))) {
        statusInput = INCORRECT_INPUT;
    }
    else {
        statusInput = CORRECT_INPUT;
    }
    return statusInput;
}


