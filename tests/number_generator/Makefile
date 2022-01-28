NAME = generator
FLAGS = -Wall -Werror -Wextra
SRCS = main.c
OBJ = $(SRCS:%.c=%.o)
RM = rm -rf

.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ) number.h
	gcc $(FLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all clean