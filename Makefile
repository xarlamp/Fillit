Flags = -Wall -Werror -Wextra
Includes = ./includes
SDIR = ./srcs
SRCS = $(SDIR)/main.c $(SDIR)/valid_or_not.c $(SDIR)/support.c $(SDIR)/debug.c \
$(SDIR)/../libft/libft.a




all:
	gcc $(Flags) -I$(Includes) $(SRCS)
