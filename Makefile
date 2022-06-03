
#NAME = a.out
NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_x.c ft_printf_u.c ft_printf_p.c ft_printf_dis.c \

OBJS = $(SRCS:%.c=%.o)

LIBFT =	libft

HEADER = inc/ft_printf.h

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
	@cp $(LIBFT)/$(LIBFT).a . #needed for final lib
	@mv $(LIBFT).a $(NAME) #needed for final lib
#	@${CC} ${OBJS} ${LIBFT}/${LIBFT}.a -o ${NAME} #comment to create lib
	@echo "$(BLUE)${LIBFT}.a linked $(DEF_COLOR)"
	@ar -crs ${NAME} ${OBJS} #comment to create program
	@ranlib $(NAME) #comment to create program
	@echo "$(BOLDGREEN)ft_printf compiled!$(DEF_COLOR)"

clean:
	@${RM} ${OBJS}
	@echo "$(CYAN)ft_pintf and libft objects files cleaned!$(DEF_COLOR)"
	@${RM} ${LIBFT}/%.o

fclean: clean
	@${RM} ${NAME}
	@${RM} $(LIBFT)/${LIBFT}.a
	@echo "$(BLUE)ft_printf and libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY: all clean fclean re
