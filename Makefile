SRCS				=	ft_memset.c				\
						ft_bzero.c				\
						ft_memcpy.c				\
						ft_memccpy.c			\
						ft_memmove.c			\
						ft_memchr.c				\
						ft_memcmp.c				\
						ft_strlen.c				\
						ft_isalpha.c			\
						ft_isdigit.c			\
						ft_isalnum.c			\
						ft_isascii.c			\
						ft_isprint.c			\
						ft_toupper.c			\
						ft_tolower.c			\
						ft_strchr.c				\
						ft_strrchr.c			\
						ft_strncmp.c			\
						ft_strlcpy.c			\
						ft_strlcat.c			\
						ft_strnstr.c			\
						ft_atoi.c				\
						ft_calloc.c				\
						ft_strdup.c				\
						ft_substr.c				\
						ft_strjoin.c			\
						ft_strtrim.c			\
						ft_split.c				\
						ft_itoa.c				\
						ft_strmapi.c			\
						ft_putchar_fd.c			\
						ft_putstr_fd.c			\
						ft_putendl_fd.c			\
						ft_putnbr_fd.c

BONUS				=	ft_lstnew_bonus.c		\
						ft_lstadd_front_bonus.c	\
						ft_lstsize_bonus.c		\
						ft_lstlast_bonus.c		\
						ft_lstadd_back_bonus.c	\
						ft_lstdelone_bonus.c	\
						ft_lstclear_bonus.c		\
						ft_lstiter_bonus.c		\
						ft_lstmap_bonus.c		\
						btree_create_node.c		\
						btree_apply_prefix.c	\
						btree_apply_suffix.c	\
						btree_apply_infix.c		\
						btree_insert_data.c		\
						btree_search_item.c		\
						btree_level_count.c		\
						btree_apply_by_level.c

BONUSOBJS		 	= ${BONUS:.c=.o}
OBJS				= ${SRCS:.c=.o}
GCC					= gcc
CFLAGS				= -Wall -Wextra -Werror
NAME				= libft.a
RM					= rm -f

.c.o:
					${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):			${OBJS}
					ar rc ${NAME} ${OBJS}
					ranlib ${NAME}

all:				${NAME}

clean:
					${RM} ${OBJS} ${BONUSOBJS}

fclean:				clean
					${RM} ${NAME}

re:					fclean all

bonus:				${BONUSOBJS}
					ar rc ${NAME} ${BONUSOBJS}
					ranlib ${NAME}

.PHONY:				all clean fclean re bonus
