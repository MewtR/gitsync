#include <stdio.h>
#include "remote.h"

int get_remotes(const char *path, git_repository **repo, git_strarray *remotes)
{
    int status = git_repository_open(repo, path);
    if(status){
        printf("Error opening the git repo.\n");
        //not sure if following two lines are necessary yet
        git_repository_free(*repo);
        git_strarray_free(remotes);
        return -1;
    }
    status = git_remote_list(remotes, *repo);
    if(status){
        printf("Error getting remote.\n");
        //not sure if following two lines are necessary yet
        git_repository_free(*repo);
        git_strarray_free(remotes);
        return -1;
    }
    return 0;
}

