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
    printf("Fetching...\n");
    int status = git_remote_fetch(remote, NULL, &opts, NULL);
    if(status) return handle_error("Error fetching from remote", NULL, status);
    return 0;
}

// Don't fully understand how this works
// just copy pasted it from SO.
// But basically it seems to count the commit difference between the local and the corresponding remote branch by taking the "difference".
int is_out_of_date(git_repository* repo, const char* remote_branch_name, const char* local_branch_name)
{
    git_revwalk* walk = NULL;
    git_revwalk_new(&walk, repo);
    git_revwalk_push_ref(walk, remote_branch_name);
    git_revwalk_hide_ref(walk, local_branch_name);
    git_oid id;
    int count = 0;
    while(!(git_revwalk_next(&id, walk))) ++count;
    if(count) printf("Local branch is behind by %d commits \n", count);
    else printf("Local branch is up to date with remote \n");
    return count;
}

int pull(const char* path)
{

    // Looking for the cpp way to 
    // allocate the exact amout needed for buffer (can chage due to path's size) without having to do the  trick I did in error.c
    //const char* buffer = 
    return 0;
}
