NAME = push_swap

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS = main.c

OBJ = $(SRC:.c=.o)

.c.o:	push_swap.h
	@gcc ${FLAGS} -c $< -o ${<:.c=.o}
			
$(NAME): 	$(OBJ)
	@gcc ${FLAGS} -o $(OBJ) $(NAME)

libft:
	@make -C libft_42/

all: $(NAME) libft

clean:
	@$(RM) $(OBJ)
	@make clean -C libft_42/

fclean:		clean
	@$(RM) $(NAME)
	@make fclean -C libft_42/ 

re: 	fclean all

.PHONY: 	clean fclean re libft all

