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
    // let's implement
}

int add(int result, calculate calc){
    // let's implement
}

int sub(int result, calculate calc){
    // let's implement
}

int mul(int result, calculate calc){
    // let's implement
}