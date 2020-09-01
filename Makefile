
RM = rm -rf
SRCS = main.c remote/remote.c
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
#remote.o: remote.c remote.h

.PHONY: clean
clean: 
	$(RM) $(OBJS) gitsync
