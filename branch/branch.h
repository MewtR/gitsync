#ifndef _BRANCH_H
#define _BRANCH_H
#include <stdio.h>
#include <string.h>
#include "git2/repository.h"
#include "git2/refs.h"
#include "git2/branch.h"
#include "git2/buffer.h"
#include "git2/errors.h"
#include "../error/error.h"

int get_current_branch_info(git_repository*, git_reference**, char**, char**,char**);
#endif
