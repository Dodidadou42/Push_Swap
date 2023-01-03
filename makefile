SRCS	=	srcs/push_swap.c srcs/ps_utils.c srcs/ps_setup.c srcs/ps_case_tree.c \
			srcs/ps_sort_little.c srcs/ps_op.c srcs/ps_sort_big.c srcs/ps_get_cheapest.c \
			srcs/ps_push_cheapest.c srcs/ps_get_rotate.c \
			libft/ft_atoi.c libft/ft_lst.c  libft/ft_putstr_fd.c \
			libft/ft_split.c libft/ft_strcmp.c libft/ft_strlen.c

SRCS_BONUS = bonus/checker.c srcs/ps_utils.c srcs/ps_setup.c srcs/ps_case_tree.c \
			srcs/ps_sort_little.c srcs/ps_op.c srcs/ps_sort_big.c srcs/ps_get_cheapest.c \
			srcs/ps_push_cheapest.c srcs/ps_get_rotate.c \
			libft/ft_atoi.c libft/ft_lst.c  libft/ft_putstr_fd.c \
			libft/ft_split.c libft/ft_strcmp.c libft/ft_strlen.c

NAME = push_swap
NAME_BONUS = checker
CC	= gcc
RM	= rm -f
INCLUDES	= -I pipex.h
CFLAGS 	= -Wall -Wextra -Werror
${NAME}:	${OBJS}
			${CC} -o  ${NAME} ${INCLUDES} ${CFLAGS} ${SRCS}
bonus : 	
			${CC} -o  ${NAME_BONUS} ${INCLUDES} ${CFLAGS} ${SRCS_BONUS}
all:		${NAME}
clean:
	${RM} ${OBJS}
fclean:	clean
	${RM} ${NAME} ${NAME_BONUS}
re:	fclean all
.PHONY: all clean fclean re bonus

