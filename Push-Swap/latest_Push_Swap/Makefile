SRC = push_swap.c sa_sb_ss.c pa_pb.c ra_rb_rr.c rra_rrb_rrr.c linked_tools.c checking_tools.c setting_things.c \
small_sorts.c tools_o_o.c error_tools.c

OBJ = ${SRC:.c=.o}

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address 

RM = rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

%.o : %.c push_swap.h
	${CC} ${FLAGS} -c $< -o $@

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re