#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int romanoParaNumero(char romano) {
    switch(toupper(romano)) {
        case 'I':  
            return 1;  
        case 'V':  
            return 5;  
        case 'X':  
            return 10;  
        case 'L':  
            return 50;  
        case 'C':  
            return 100;  
        case 'D':  
            return 500;  
        case 'M':  
            return 1000;  
        default:
            return 0;
    }
}

int romanoCalculator(char romano[20]) {
    int i = 0, int_num = 0, prev_num = 0, cur_num = 0;

    while (romano[i] != '\0') {
        prev_num = romanoParaNumero(romano[i - 1]);
        cur_num = romanoParaNumero(romano[i]);
        if (prev_num < cur_num) {
            int_num = int_num - prev_num + (cur_num - prev_num);
        } else {
            int_num += cur_num;
        }
        i++;
    }
    
    return int_num;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    char romano[20];
    int numero = 0;
    
    printf("Introduz um número romano: ");
    gets(romano);
    
    numero = romanoCalculator(romano);
    
    printf("O número romano %s é: %d", romano, numero);
    
    return 0;
}