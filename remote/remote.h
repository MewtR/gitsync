#ifndef _REMOTE_H
#define _REMOTE_H
#include "git2/remote.h"
#include "git2/repository.h"
#include "git2/strarray.h"
#include "../error/error.h"

int get_remotes(const char*,git_repository**,git_strarray*);
#endif
