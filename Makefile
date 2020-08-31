
RM = rm -r
SRCS = main.c
OBJS = $(subst .c,.o,$(SRCS))

gitsync: $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: main.c

.PHONY: clean
clean: 
	$(RM) $(OBJS) gitsync
