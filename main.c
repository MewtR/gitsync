#include <stdio.h>
//takes path to directory and remote url
int main(int argc, char * argv[]) 
{
    printf("Here is the number of arguments I received: %i \n", argc);

    int i = 0;
    for(char** av = argv; *av; av++){ //argv ends with null pointer
        if(i == 0){
            printf("The program name is: %s \n", argv[0]);
        }else{
            printf("Argument number %d is: %s \n", i, argv[i]);
        }
        i++;
    }

    return 0;
}
