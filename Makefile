NAME = push_swap

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRCS = 	srcs/parsing/ft_isnbr.c \
		srcs/parsing/ft_is_doublon.c \
		srcs/parsing/ft_atoips.c \
		srcs/parsing/ft_is_sorted.c \
		srcs/parsing/ft_error.c \
		srcs/utils/ft_instruction.c \
		srcs/utils/ft_free_struc.c \
		srcs/utils/ft_min_max.c \
		srcs/utils/ft_rotate.c  \
		srcs/utils/ft_index.c \
		srcs/small_list/ft_small.c \
		srcs/small_list/ft_sup3.c \
		srcs/small_list/ft_pa.c \
		srcs/big_list/ft_big.c \
		checker_bonus/instruction_bonus.c

CHE = checker_bonus/checker_bonus.c
MAN = srcs/main.c

OCHE = $(CHE:.c=.o)
OMAN = $(MAN:.c=.o)
OBJ = $(SRCS:.c=.o)


.c.o:	includes/push_swap.h
	gcc ${FLAGS} -c $< -o ${<:.c=.o}
			
$(NAME): 	$(OBJ) $(OMAN) libft
	gcc ${FLAGS} $(OBJ) $(OMAN) libft.a -o $(NAME)

bonus:	$(OBJ) $(OCHE) libft
	gcc ${FLAGS} $(OBJ) $(OCHE) libft.a -o checker

libft:
	make -C libft/
	cp ./libft/libft.a ./

all: $(NAME) libft

clean:
	@$(RM) $(OBJ) srcs/main.o
	@make clean -C libft/

fclean:		clean
	@$(RM) $(NAME) libft.a checker
	@make fclean -C libft/ 

re: 	fclean all

.PHONY: 	clean fclean re libft all

