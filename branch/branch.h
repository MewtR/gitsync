#ifndef _BRANCH_H
#define _BRANCH_H
#include <stdio.h>
#include "git2/repository.h"
#include "git2/refs.h"
#include "git2/branch.h"
#include "../error/error.h"

int get_current_branch(git_repository*, git_reference**);
#endif
