#ifndef _REMOTE_H
#define _REMOTE_H
#include "git2/remote.h"
#include "git2/repository.h"
#include "git2/strarray.h"
#include "../error/error.h"

int  open_repo(const char*, git_repository**);
int get_remote(git_remote**, git_repository*, const char*);
int fetch(git_remote*);
#endif
