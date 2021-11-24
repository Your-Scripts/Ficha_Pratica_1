#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void encode() {
    char message[100], ch;
    int i, key;
    printf("Introduz a mensagem para encriptar: ");
    getchar();
    gets(message);
    printf("Introduz um número de 0 a 9: ");
    scanf("%d", &key);
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    
    printf("Mensagem encriptada: %s", message);
}

void decode() {
    char message[100], ch;
    int i, key;
    printf("Introduz a mensagem para desencriptar: ");
    getchar();
    gets(message);
    printf("Introduz um número de 0 a 9: ");
    scanf("%d", &key);
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
    printf("Mensagem desencryptada: %s", message);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    char opcao;
    
    printf("Codificar(C)\nDecodificar(D): ");
    scanf(" %c", &opcao);
    
    switch (toupper(opcao)) {
        case 'C':
            encode();
            break;
        case 'D':
            decode();
            break;
        default:
            printf("Opção errada");
    }
    return 0;
}