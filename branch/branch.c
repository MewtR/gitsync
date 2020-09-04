#include "branch.h"

int get_current_branch(git_repository * repo, git_reference ** ref)
{
    const char* branch_name = NULL;
    int status = git_repository_head(ref, repo);
    if (status){
        return handle_error("Error getting repository HEAD \n", NULL);
    }else{    
        status = git_branch_name(&branch_name, *ref);
        if (status) handle_error("Error getting branch name \n", NULL);
        else printf("Current branch is %s\n", branch_name); // TODO: get remote name through branch name
    }
    return 0;
}
