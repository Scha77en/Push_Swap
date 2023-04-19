SOURCE = ./src
OBJECTS = ./obj
INCLUDE = ./inc
SOURCE_BONUS = ./bonus
OBJECTS_BONUS = ./obj_bonus

SRC = push_swap.c sa_sb_ss.c pa_pb.c ra_rb_rr.c rra_rrb_rrr.c linked_tools.c checking_tools.c setting_things.c \
small_sorts.c tools_o_o.c error_tools.c

OBJ = ${addprefix ${OBJECTS}/, ${SRC:.c=.o}}

SRC_BONUS = sa_sb_ss.c pa_pb.c ra_rb_rr.c rra_rrb_rrr.c linked_tools.c checking_tools.c \
error_tools.c main_checker.c get_next_line.c get_next_line_utils.c handling_errors.c

OBJ_BONUS = ${addprefix ${OBJECTS_BONUS}/, ${SRC_BONUS:.c=.o}}

NAME = push_swap

NAME_BONUS = checker

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

all : ${NAME}

bonus : ${NAME_BONUS}

${NAME} : ${OBJ}
	${CC} ${FLAGS} $^ -o ${NAME}

${OBJECTS}/%.o : ${SOURCE}/%.c ${INCLUDE}/push_swap.h
	@mkdir -p ${dir $@}
	${CC} ${FLAGS} -c $< -o $@

${NAME_BONUS} : ${OBJ_BONUS}
	${CC} ${FLAGS} ${OBJ_BONUS} -o $@

${OBJECTS_BONUS}/%.o : ${SOURCE_BONUS}/%.c ${INCLUDE}/push_swap_bonus.h
	@mkdir -p ${dir $@}
	${CC} ${FLAGS} -c $< -o $@

clean :
	${RM} ${OBJECTS} ${OBJECTS_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS}

re : fclean all

.PHONY : all clean fclean re