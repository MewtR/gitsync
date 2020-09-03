#include <stdio.h>
#include "remote.h"


int handle_error(char * message, int freeable)
{
    printf("%s", message);
    if (freeable) free(message);
    return -1;
}

int get_remotes(const char *path, git_repository **repo, git_strarray *remotes)
{
    int status = git_repository_open(repo, path);
    if(status) return handle_error("Error opening the git repo.\n", 0);

    status = git_remote_list(remotes, *repo);
    if(status) return handle_error("Error getting remote\n", 0);

    if(!remotes->count) return handle_error("This repo does not have any remotes\n", 0);
    
    return 0;
}
int get_remote(git_remote ** out, git_repository* repo, const char* name)
{
    int status = git_remote_lookup(out, repo, name);
    if (status) {
        size_t needed = snprintf(NULL, 0, "Invalid remote %s", name);
        char *buffer = malloc(needed);
        sprintf(buffer, "Invalid remote %s", name);
        return handle_error(buffer, 1);
    }
    return 0;
}

