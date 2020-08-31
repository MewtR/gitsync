
RM = rm -r
SRCS = main.c
OBJS = $(subst .c,.o,$(SRCS))
CFLAGS = -g3 # debug with extra information

gitsync: $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.c

.PHONY: clean
clean: 
	$(RM) $(OBJS) gitsync
