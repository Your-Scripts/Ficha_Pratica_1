#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int verificarPalavra(char palavra[50]) {
    char reversePal[50];
    int i, j = 0, tamanho, capicua;
    tamanho = strlen(palavra);
    
    for (i = (tamanho - 1); i >= 0; i--) {
        palavra[i] = tolower(palavra[i]);
        reversePal[j] = palavra[i];
        j++;
    }
    reversePal[j] = '\0';
    
    capicua = strcmp(palavra, reversePal);
    
    return capicua;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    char palavra[50];
    int capicua;
    
    printf("Introduz uma palavra: ");
    gets(palavra);
    
    capicua = verificarPalavra(palavra);
    
    if (capicua == 0) {
        printf("A palavra é capicua");
    } else {
        printf("A palavra não é capicua");
    }
    
    return 0;
}