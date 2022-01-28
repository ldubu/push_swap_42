NAME = push_swap

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS = 	srcs/main.c \
		srcs/parsing/ft_isnbr.c \
		srcs/parsing/ft_is_doublon.c \
		srcs/parsing/ft_atoips.c \
		srcs/parsing/ft_is_sorted.c \
		srcs/parsing/ft_error.c \
		srcs/utils/ft_instruction.c \
		srcs/utils/ft_free_struc.c \
		srcs/small_list/ft_small.c \
		srcs/small_list/ft_sup3.c \
		srcs/small_list/ft_pa.c

OBJ = $(SRCS:.c=.o)

.c.o:	includes/push_swap.h
	gcc ${FLAGS} -c $< -o ${<:.c=.o}
			
$(NAME): 	$(OBJ) libft
	@gcc ${FLAGS} $(OBJ) libft.a -o $(NAME)

libft:
#	@make printf -C libft/
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

