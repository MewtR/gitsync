#ifndef _REPO_H
#define _REPO_H
#include <stdio.h>
#include "git2/repository.h"
#include "git2/refs.h"
#include "git2/branch.h"

int get_current_branch(git_repository*, git_reference**, const char** branch_name);
#endif
