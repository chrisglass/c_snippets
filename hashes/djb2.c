#include <stdio.h>

int main(){

    char word[] = {'a', 's', 'd', 'f', 'i', '\0'};
    int counter = 0;
    int hashAddress;

    for (counter =0; word[counter]!='\0'; counter++){
        hashAddress = ((hashAddress << 5) + hashAddress) + word[counter];
    }

    printf("%d", hashAddress);
    printf("\n");
}
