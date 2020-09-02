#include <stdio.h>
#include "remote.h"

int handle_error(char * message,git_repository *repo, git_strarray *remotes)
{
    printf("%s", message);
    git_repository_free(repo);
    git_strarray_free(remotes);
    return -1;
}

int get_remotes(const char *path, git_repository **repo, git_strarray *remotes)
{
    int status = git_repository_open(repo, path);
    if(status) return handle_error("Error opening the git repo.\n", *repo, remotes);

    status = git_remote_list(remotes, *repo);
    if(status) return handle_error("Error getting remote\n", *repo, remotes);

    if(!remotes->count) return handle_error("This repo does not have any remotes\n", *repo, remotes);
    
    return 0;
}

