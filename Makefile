NAME		:=	libft.a

PATH_SRC	:=	src
PATH_OBJ	:=	obj
PATH_INC	:=	include

ifndef $(ECHO)
ECHO			:=	echo

UNAME_S			:= $(shell uname -s)
ifeq ($(UNAME_S),Linux)
ECHO			:=	/bin/echo -e
endif
ifeq ($(UNAME_S),Darwin)
ECHO			:=	echo
endif
undefine UNAME_S
endif

CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -I$(PATH_INC) -g3 -ggdb3 -MMD -O3 -fstack-protector-all -fno-omit-frame-pointer
LDFLAGS		:=	-g

SRC			:=	lst/ft_lstfirst.c				\
				lst/ft_lstadd_front.c			\
				lst/ft_lstsize.c				\
				lst/ft_lstadd_back.c			\
				lst/ft_lstlast.c				\
				lst/ft_lstnew.c					\
				lst/ft_lstiter.c				\
				lst/ft_lstmap.c					\
				lst/ft_lstdelone.c				\
				lst/ft_lstclear.c				\
				getopt/parse_args.c				\
				getopt/get_option.c				\
				getopt/print_flags.c			\
				string/ft_strrchr.c				\
				string/ft_strnstr.c				\
				string/ft_strchr.c				\
				string/ft_toupper.c				\
				string/ft_strcmp.c				\
				string/ft_strlcpy.c				\
				string/ft_strtrim.c				\
				string/get_next_line.c			\
				string/ft_strlen.c				\
				string/ft_tolower.c				\
				string/ft_strjoin_arr.c			\
				string/ft_substr.c				\
				string/ft_itoa.c				\
				string/ft_ltoa_base.c			\
				string/ft_ultoa_base.c			\
				string/ft_split.c				\
				string/get_next_line_utils.c	\
				string/ft_strdup.c				\
				string/ft_strndup.c				\
				string/ft_strjoin.c				\
				string/ft_strncmp.c				\
				string/ft_strmapi.c				\
				string/ft_strlcat.c				\
				math/ft_pow.c					\
				math/int128.c					\
				memory/ft_memmove.c				\
				memory/ft_memccpy.c				\
				memory/ft_calloc.c				\
				memory/ft_memchr.c				\
				memory/ft_memcmp.c				\
				memory/ft_memcpy.c				\
				memory/ft_memset.c				\
				memory/ft_memdup.c				\
				memory/ft_memjoin.c				\
				memory/ft_bzero.c				\
				utils/ft_isalnum.c				\
				utils/ft_atoi.c					\
				utils/ft_isdigit.c				\
				utils/ft_isalpha.c				\
				utils/random.c					\
				utils/ft_isascii.c				\
				utils/endian.c					\
				utils/ft_isprint.c				\
				print/ft_putchar_fd.c			\
				print/ft_putnbr_fd.c			\
				print/ft_putstr_fd.c			\
				stream/stream_close.c			\
				stream/stream_open.c			\
				stream/stream_read.c			\
				stream/stream_write.c			\

OBJ			:=	$(addprefix $(PATH_OBJ)/, $(SRC:.c=.o))
DEP			:=	$(addprefix $(PATH_OBJ)/, $(SRC:.c=.d))
SRC 		:=	$(addprefix $(PATH_SRC)/, $(SRC))


ifeq ($(shell uname),Darwin)
	ECHO	:=	echo
else
	ECHO	:=	/bin/echo -e
endif

$(PATH_OBJ)/%.o:	$(PATH_SRC)/%.c
	@mkdir -p $(dir $@)
	@$(ECHO) "  Compiling   \033[31m$(notdir $<)\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@


all: 				$(NAME)

-include $(DEP)

$(NAME): 			$(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:				clean
	@rm -f $(NAME)
	@rm -rf $(PATH_OBJ)

re:					fclean all

.PHONY:				all clean fclean re
