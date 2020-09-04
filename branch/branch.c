#include "branch.h"

int get_current_upstream_branch(git_repository *repo,git_reference* ref)
{
    const char* ref_name = git_reference_name(ref);
    printf("Current branch is %s\n", ref_name); 
    git_buf buf = {NULL,0,0};
    int status = git_branch_upstream_name(&buf, repo, ref_name);
    if(status) {
        git_buf_dispose(&buf);
        return handle_error("Error getting upstream name of branch %s \n", ref_name, status);
    } else {
        printf("Upstream branch name of %s is %s \n", ref_name, buf.ptr);
        git_buf_dispose(&buf);
    }
    return 0;
}

int get_current_branch(git_repository * repo, git_reference ** ref)
{
    const char* branch_name = NULL;
    int status = git_repository_head(ref, repo);
    if (status){
        return handle_error("Error getting repository HEAD \n", NULL, status);
    }else{    
        return get_current_upstream_branch(repo, *ref);
    }
    return 0;
}

