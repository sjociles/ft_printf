
NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_atoi.c ft_isascii.c ft_strncmp.c \
ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlen.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

LIB = libft.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} ${LIB}
	@ar -crs ${NAME} ${OBJS}
	@ranlib $(NAME)

bonus:${NAME} ${OBJS_BONUS}
	@ar -rcs $(NAME) $(OBJS_BONUS)
	@touch $@
clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} bonus

re: fclean all

.PHONY: all clean fclean re
