NAME = fillit
LNAME =  libft
INCLUDES = ./includes
FLAGS = -Wall -Werror -Wextra -I$(INCLUDES)
RM = /bin/rm -rf
SDIR = ./srcs
SRCS = $(SDIR)/main.c $(SDIR)/valid_or_not.c $(SDIR)/support.c $(SDIR)/debug.c \
$(SDIR)/support2.c $(SDIR)/solver1.c
OBJ = $(SRCS:.c=.o)
LIBFT = libft/libft.a


all: $(LNAME) $(OBJ) $(NAME)
$(LNAME):
	@make re -C libft
$(OBJ): %.o : %.c
	@gcc $(FLAGS) -c $< -o $@
$(NAME):
	@gcc $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)
clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
re: fclean all
