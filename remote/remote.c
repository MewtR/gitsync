#include <stdio.h>
#include "remote.h"


int handle_error(char * message)
{
    printf("%s", message);
    return -1;
}

int get_remotes(const char *path, git_repository **repo, git_strarray *remotes)
{
    int status = git_repository_open(repo, path);
    if(status) return handle_error("Error opening the git repo.\n");

    status = git_remote_list(remotes, *repo);
    if(status) return handle_error("Error getting remote\n");

    if(!remotes->count) return handle_error("This repo does not have any remotes\n");
    
    return 0;
}

