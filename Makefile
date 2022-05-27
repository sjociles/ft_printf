
NAME = print.a
# change name to libftprintf.a
SRCS = ft_printf.c 

OBJS = $(SRCS:%.c=%.o)

HEADER = includes/libftprintf.h

INCLUDE = includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

# Colors

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
YELLOW = \033[0;93m

%.o : %.c
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
#	@ar -crs ${NAME} ${OBJS}
#	@ranlib $(NAME)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@echo "$(BLUE)ft_printf executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY: all clean fclean re
