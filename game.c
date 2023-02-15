#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int difficulty;
    int value1;
    int value2;
    int operation;
    int result;
} calculate;

void start(); // jogar
void showInfo(calculate calc); // mostrar info
int add(int result, calculate calc);
int sub(int result, calculate calc);
int mul(int result, calculate calc);

int points = 0; // Placar

int main() {
    // Must be called only once
    srand(time(NULL));

    start();

    return 0;
}

void start() {
    calculate calc;
    int difficulty;

    printf("Enter the difficulty level [1, 2, 3 or 4]:\n");
    scanf("%d", &difficulty);
    calc.difficulty = difficulty;

    // generates a random number between 0 and 2
    // 0 == add, 1 == sub, 3 == mul
    calc.operation = rand() % 3;

    if(calc.difficulty == 1){
        //easy
        calc.value1 = rand() % 11; // 0 to 10
        calc.value2 = rand() % 11;
    } else if(calc.difficulty == 2){
        //Medium
        calc.value1 = rand() % 101; // 0 to 100
        calc.value2 = rand() % 101;
    } else if(calc.difficulty == 3){
        // Hard
        calc.value1 = rand() % 1001; // 0 to 1000
        calc.value2 = rand() % 1001;
    } else if(calc.difficulty == 4){
        // Very Hard
        calc.value1 = rand() % 10001; // 0 to 10000
        calc.value2 = rand() % 10001;
    } else {
        // Nightmare
        calc.value1 = rand() % 100001; // 0 to 100001
        calc.value2 = rand() % 100001;
    }

    int res;
    printf("Enter the result for the following operation: \n");

    //Add
    if(calc.operation == 0) {
        printf("%d + %d\n", calc.value1, calc.value2);
        scanf("%d", &res);

        if(add(res, calc)){
            points+=1;
            printf("you have %d point", points);
        }
    } // Sub
    else if(calc.operation == 1) {
       printf("%d - %d\n", calc.value1, calc.value2);
        scanf("%d", &res);

        if(sub(res, calc)){
            points+=1;
            printf("you have %d point", points);
        } 
    } // mult
    else if(calc.operation == 2){
        printf("%d * %d\n", calc.value1, calc.value2);
        scanf("%d", &res);

        if(mul(res, calc)){
            points+=1;
            printf("you have %d point", points);
        }
    } // Unknown
    else {
        printf("Unknown operation!\n");
    }

    // Play again?
    printf("Play again?[1 - Yes, 0 - No]\n");
    int cont;
    scanf("%d", &cont);

    if(cont) {
        start();
    } else {
        printf("You have finished your game with %d points\n", points);
        exit(1);
    }
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
    result = calc.value1 + calc.value2;
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
    result = calc.value1 - calc.value2;
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
    result = calc.value1 * calc.value2;
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