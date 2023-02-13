#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int difficulty;
    int value1;
    int value2;
    int operation;
    int result;
} calculate;

void start(); // jogar
void showInfo(calculate calc); // mostrar info

int points = 0; // Placar

int main() {
    // Must be called only once
    srand(time(NULL));

    start();

    return 0;
}

void start() {
    // let's implement
}

void showInfo(calculate calc){
    char op[25];

    if(calc.operation == 0) {
        sprintf(op, "Add");
    } else if(calc.operation == 1){
        sprintf(op, "Subtract");
    } else if(calc.operation == 2){
        sprintf(op, "Multiply");
    } else{
        sprintf(op, "Unknowm operation");
    }
    printf("Valor 1: %d \nValor 2: %d \nDifficulty: %d \n Operation: %s", 
        calc.value1, calc.value2, calc.difficulty, calc.difficulty, op);
}

int add(int result, calculate calc){
    int result = calc.value1 + calc.value2;
    calc.result = result;
    int hit = 0; // 0 == miss, 1 == hit, certo

    if(result == calc.result) {
        printf("Right answer!\n");
        hit = 1;
    } else {
        printf("Miss!\n");
    }

    printf("%d + %d = %d\n", calc.value1, calc.value2, calc.result);
    return hit;
}

int sub(int result, calculate calc){
    int result = calc.value1 - calc.value2;
    calc.result = result;
    int hit = 0; // 0 == miss, 1 == hit, certo

    if(result == calc.result) {
        printf("Right answer!\n");
        hit = 1;
    } else {
        printf("Miss!\n");
    }
    
    printf("%d - %d = %d\n", calc.value1, calc.value2, calc.result);
    return hit;
}

int mul(int result, calculate calc){
    /int result = calc.value1 * calc.value2;
    calc.result = result;
    int hit = 0; // 0 == miss, 1 == hit, certo

    if(result == calc.result) {
        printf("Right answer!\n");
        hit = 1;
    } else {
        printf("Miss!\n");
    }
    
    printf("%d x %d = %d\n", calc.value1, calc.value2, calc.result);
    return hit;
}