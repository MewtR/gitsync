#include "branch.h"
#include <stdlib.h>
#include <string.h>

int get_remote_name(git_repository * repo, git_buf* remote_branch, char** remote_name)
{
    git_buf buf = {NULL,0,0};
    int status = git_branch_remote_name(&buf, repo, remote_branch->ptr);
    if(status){
        git_buf_dispose(&buf);
        return handle_error("Error getting the remote name of %s", remote_branch->ptr, status);
    }else{
        printf("The remote of %s is %s \n", remote_branch->ptr, buf.ptr);
        *remote_name = malloc(strlen(buf.ptr)+1);
        strcpy(*remote_name, buf.ptr);
    }
    git_buf_dispose(&buf);
    return 0;
}
int get_current_upstream_branch(git_repository *repo,git_reference* ref, char** remote_name)
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
        get_remote_name(repo, &buf, remote_name);
    }
    git_buf_dispose(&buf);
    return 0;
}

int get_current_branch(git_repository * repo, git_reference ** ref, char** remote_name)
{
    const char* branch_name = NULL;
    int status = git_repository_head(ref, repo);
    if (status){
        return handle_error("Error getting repository HEAD \n", NULL, status);
    }else{    
        get_current_upstream_branch(repo, *ref, remote_name);
    }
    return 0;
}
int get_current_branch_remote(git_repository * repo, git_reference **ref, char** remote_name)
{
    int status = get_current_branch(repo, ref, remote_name);
    printf("Final remote is %s\n", *remote_name); 
    return status;
}
