#include <git2/remote.h>
#include <stdio.h>
#include "remote/remote.h"
#include "branch/branch.h"
#include "git2/global.h"
#include <stdlib.h>
#include <string.h>

void clean_up(git_repository * repo, git_reference * head, char* remote_name, git_remote* remote, char* remote_branch_name, char* local_branch_name)
{
    if (remote_name) free(remote_name);
    if (remote_branch_name) free(remote_branch_name);
    if (local_branch_name) free(local_branch_name);
    git_repository_free(repo);
    git_reference_free(head);
    git_remote_free(remote);
    git_libgit2_shutdown();
}
//takes path to directory and remote url
int main(int argc, char * argv[]) 
{
    if (argc < 2){
        printf("Please specify a local directory \n");
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
    git_repository * repo;
    git_reference * head = NULL;
    char * remote_name = NULL;
    char * remote_branch_name = NULL;
    char * local_branch_name = NULL;
    git_remote * remote = NULL;
    
    int status = open_repo(argv[1], &repo);
    if (status < 0) goto on_error;

    // The name of the remote
    status = get_current_branch_info(repo, &head, &remote_name, &remote_branch_name, &local_branch_name);
    if (status < 0) goto on_error;

    // the remote  struct
    status = get_remote(&remote, repo, remote_name);  
    if (status < 0) goto on_error;
    
    //git fetch 
    status = fetch(remote);
    if (status < 0) goto on_error;

    if(is_out_of_date(repo, remote_branch_name, local_branch_name)){
        status = pull(remote);
        if(status < 0) goto on_error;
    }

    clean_up(repo, head, remote_name, remote, remote_branch_name, local_branch_name);
    return 0;

on_error:
    clean_up(repo, head, remote_name, remote, remote_branch_name, local_branch_name);
    return -1;
}
