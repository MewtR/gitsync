#include <stdio.h>
//takes path to directory and remote url
int main(int argc, char * argv[]) 
{
    if (argc < 3){
        printf("Please specify a local directory and a remote url \n");
        return -1;
    }

    int i = 0;
    // argv ends with null pointer. So we can end the for loop when that
    // is met
    for(char** av = argv; *av; av++){  
        if(i == 0){
            printf("The program name is: %s \n", argv[0]);
        }else{
            printf("Argument %d is: %s \n", i, *av);
        }
        i++;
    }

    return 0;
}
