#include <stdio.h>
#include "remote/remote.h"
#include "git2/global.h"
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

    git_libgit2_init();
    // Assume first arg is local directory (check that it exists)
    // Actually, just check right away if it is a git repo to avoid TOCTOU bug
    // possible options: git ls-files (returns error if not a git repo)
    // I can get the remotes information right away. If it errors it means it's not a git repo.
    // if not I can use the information in the next part.
    // What I'm looking for is git_remote_list
    git_repository * repo;
    git_strarray remotes = {NULL, 0};
    int status = get_remotes(argv[1], &repo, &remotes);
    if (status < 0) return -1;

    printf("Remotes found!\n");
    for(char** r = remotes.strings; *r; r++){
        printf("Remote: %s\n", *r);
    }
        

    // Assume second arg is remote repo. Check that it is valid

    git_libgit2_shutdown();
    return 0;
}
