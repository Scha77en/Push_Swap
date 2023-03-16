SRC = push_swap.c sa_sb_ss.c pa_pb.c ra_rb_rr.c rra_rrb_rrr.c filling.c nodes_lists.c Sorting_testing.c

OBJ = ${SRC:.c=.o}

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -c

RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	ar -r $@ $^

%.o : %.c push_swap.h
	${CC} ${FLAGS} $< -o $@

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re