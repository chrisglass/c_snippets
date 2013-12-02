#include <stdio.h>

int main(){

    char word[] = {'a', 's', 'd', 'f', 'i', '\0'};
    int counter = 0;
    int hashAddress;

    for (counter =0; word[counter]!='\0'; counter++){
        hashAddress = word[counter] + (hashAddress << 6) + (hashAddress << 16) - hashAddress;
    }

    printf("%d", hashAddress);
    printf("\n");
}
