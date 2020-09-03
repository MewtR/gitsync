#include "repo.h"

int get_current_branch(git_repository * repo, git_reference ** ref, const char** branch_name)
{
    int status = git_repository_head(ref, repo);
    if (status){
        //failure
        return -1;
    }else{    
        status = git_branch_name(branch_name, *ref);
        if (status) return -1;
        else printf("Current branch is %s\n", *branch_name); // TODO: get remote name through branch name
    }
    return 0;
}
