NAME = push_swap

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS = 	main.c \
		ft_isnbr.c \
		ft_is_doublon.c \
		ft_atoips.c

OBJ = $(SRCS:.c=.o)

.c.o:	push_swap.h
	gcc ${FLAGS} -c $< -o ${<:.c=.o}
			
$(NAME): 	$(OBJ) libft
	@gcc ${FLAGS} $(OBJ) libft.a -o $(NAME)

libft:
	@make -C libft/
	@cp ./libft/libft.a ./

all: $(NAME) libft

clean:
	@$(RM) $(OBJ)
	@make clean -C libft/

fclean:		clean
	@$(RM) $(NAME) libft.a
	@make fclean -C libft/ 

re: 	fclean all

.PHONY: 	clean fclean re libft all

