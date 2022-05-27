
NAME = a.out

SRCS = ft_printf.c 

OBJS = $(SRCS:%.c=%.o)

LIBFT =	libft

HEADER = inc/libftprintf.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

# Colors

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
YELLOW = \033[0;93m
CYAN = \033[0;36m
BOLDGREEN = \033[1;32m

%.o : %.c
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -I./ -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} $(HEADER)
	@make -C $(LIBFT)
	@${CC} ${OBJS} ${LIBFT}/${LIBFT}.a -o ${NAME}
#	borrar linea de arriba al entregar
	@echo "$(BLUE)${LIBFT}.a linked $(DEF_COLOR)"
#	@ar -crs ${NAME} ${OBJS}
#	@ranlib $(NAME)
	@echo "$(BOLDGREEN)ft_printf compiled!$(DEF_COLOR)"

clean:
	@${RM} ${OBJS}
	@echo "$(CYAN)ft_pintf and libft .o files cleaned!$(DEF_COLOR)"
	@${RM} ${LIBFT}/%.o

fclean: clean
	@${RM} ${NAME}
	@echo "$(BLUE)ft_printf executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY: all clean fclean re
