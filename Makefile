RM = rm -rf
SRCS = main.cpp remote/remote.cpp branch/branch.c error/error.c
OBJSC = $(subst .cpp,.o,$(SRCS))
OBJS = $(subst .c,.o,$(OBJSC))
CFLAGS = -g3 # debug with extra information
CC = $(CXX)

# implicit variables only used in implicit rules.
# Else you need to explicitly specify them
# I got the following line from: https://libgit2.org/docs/guides/build-and-link/
LDLIBS = $(shell pkg-config --libs libgit2)

gitsync: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDLIBS)

main.o: main.cpp 

remote/remote.o: remote/remote.cpp remote/remote.h

branch/branch.o: branch/branch.c branch/branch.h

error/error.o: error/error.c error/error.h

.PHONY: clean
clean: 
	$(RM) $(OBJS) gitsync
