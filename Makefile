Flags = -Wall -Werror -Wextra
Includes = ./includes
SDIR = ./srcs
SRCS = $(SDIR)/main.c $(SDIR)/valid_or_not.c $(SDIR)/support.c $(SDIR)/debug.c \
$(SDIR)/../libft/libft.a $(SDIR)/support2.c $(SDIR)/solver1.c




all:
	gcc -g $(Flags) -I$(Includes) $(SRCS)
