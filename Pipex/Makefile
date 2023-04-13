SRC = 

OBJ = ${SRC:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror -c

RM = rm -rf

NAME = pipex

all : ${NAME}

${NAME} : ${OBJ}
	ar -r $@ $^

%.o : %.c pipex.h
	${CC} ${FLAGS} $< -o $@

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re