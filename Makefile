
RM = rm -rf
SRCS = main.c remote/remote.c branch/branch.c error/error.c
OBJS = $(subst .c,.o,$(SRCS))
CFLAGS = -g3 # debug with extra information

# implicit variables only used in implicit rules.
# Else you need to explicitly specify them
# I got the following line from: https://libgit2.org/docs/guides/build-and-link/
LDLIBS = $(shell pkg-config --libs libgit2)

gitsync: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDLIBS)

main.o: main.c 

remote/remote.o: remote/remote.c remote/remote.h

branch/branch.o: branch/branch.c branch/branch.h

error/error.o: error/error.c error/error.h

.PHONY: clean
clean: 
	$(RM) $(OBJS) gitsync
