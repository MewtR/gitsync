#include <git2/remote.h>
#include <stdio.h>
#include "remote.h"

int open_repo(const char *path, git_repository **repo)
{
    int status = git_repository_open(repo, path);
    if(status) return handle_error("Error opening the git repo located at %s \n", path, status);

    /* obsolete
    status = git_remote_list(remotes, *repo);
    if(status) return handle_error("Error getting remote\n", NULL, status);

    if(!remotes->count) return handle_error("This repo does not have any remotes\n", NULL, status);
    */
    
    return 0;
}
int get_remote(git_remote ** out, git_repository* repo, const char* name)
{
    int status = git_remote_lookup(out, repo, name);
    if (status) {
        return handle_error("Invalid remote %s", name, status);
    }
    return 0;
}

int fetch(git_remote* remote)
{
    git_fetch_options opts = GIT_FETCH_OPTIONS_INIT;
    int status = git_remote_fetch(remote, NULL, &opts, NULL);
    if(status) return handle_error("Error fetching from remote", NULL, status);
    return 0;
}
