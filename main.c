#include <stdio.h>
#include "remote/remote.h"
#include "branch/branch.h"
#include "git2/global.h"
#include <string.h>

void clean_up(git_repository * repo, git_strarray * remotes, git_reference * head, char* remote_name)
{
    if (remote_name) free(remote_name);
    git_repository_free(repo);
    git_strarray_free(remotes);
    git_reference_free(head);
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
    // TODO: 
    // - how to get git_remote objects <- git_remote_lookup does this
    // - if there are multiple remotes how to determine which one is the default <- basically need to get the current branch because each branch tracks its own remote.
    // In order to get current branch I need to:
    // - git_repository_head() <- gets reference pointed to by head
    // - git_reference_type() <- either symbolic or direct reference
    // - git_reference_symbolic_target or git_reference_target depending on type
    // from branch can get remote. Can I just git_branch_name
    // git_branch_name -> full name of branch? ->git_branch_upstream_remote -> git_remote_lookup  -> git_remote_fetch
    // or 
    // git_branch_name -> git_branch_upstream_name -> git_branch_remote_name -> git_remote_lookup  -> git_remote_fetch
    // My end goal is to use git_remote_fetch & git_remote_download
    git_repository * repo;
    git_strarray remotes = {NULL, 0};
    git_reference * head = NULL;
    char * remote_name = NULL;
    int status = get_remotes(argv[1], &repo, &remotes);
    if (status < 0) goto on_error;
    

    printf("Remotes found!\n");
    for (int i = 0; i < remotes.count; i++){
        printf("Remote %d: %s\n", i, remotes.strings[i]);
    }
    status = get_current_branch_remote(repo, &head, &remote_name);
    if (status < 0) goto on_error;
    
    // Assume second arg is remote repo. Check that it is valid

    clean_up(repo, &remotes, head, remote_name);
    return 0;

on_error:
    clean_up(repo, &remotes, head, remote_name);
    return -1;
}
