################################################################################
#                               Name of the output                             #
################################################################################
NAME				=	libft.a

################################################################################
#                          Paths of sources and objects                        #
################################################################################
PATH_INCLUDES		=	.
PATH_SRCS			=	.
PATH_OBJS			=	.

################################################################################
#                              Name of sources files                           #
################################################################################
SRCS_BASENAME		=	memset				\
						bzero				\
						memcpy				\
						memccpy				\
						memmove				\
						memchr				\
						memcmp				\
						strlen				\
						isalpha				\
						isdigit				\
						isalnum				\
						isascii				\
						isprint				\
						toupper				\
						tolower				\
						strchr				\
						strrchr				\
						strcmp				\
						strncmp				\
						strlcpy				\
						strlcat				\
						strnstr				\
						atoi				\
						calloc				\
						strdup				\
						substr				\
						strjoin				\
						strjoin_arr			\
						strtrim				\
						split				\
						itoa				\
						strmapi				\
						putchar_fd			\
						putstr_fd			\
						putnbr_fd			\
						lstnew_bonus		\
						lstadd_front_bonus	\
						lstsize_bonus		\
						lstlast_bonus		\
						lstfirst_bonus		\
						lstadd_back_bonus	\
						lstdelone_bonus		\
						lstclear_bonus		\
						lstiter_bonus		\
						lstmap_bonus		\
						btree_apply_suffix	\
						btree_apply_infix	\
						btree_apply_prefix	\
						btree_create_node	\
						ternary				\
						assign				\

GNL_SRCS			=	get_next_line		\
						get_next_line_utils

UTILS_SRCS			=	get_option	\
						parse_args	\
						print_flags	\
						random		\
						endian

################################################################################
#                             Commands and arguments                           #
################################################################################
RM					=	@rm -f
GCC					=	@gcc
CFLAGS				=	-Wall -Wextra -Werror -I$(PATH_INCLUDES) -g -DBUFFER_SIZE=4096

SYS_ENDIAN			=	1

################################################################################
#                         DO NOT MODIFY BELOW THIS POINT                       #
################################################################################
SRCS_EXT			=	$(addsuffix .c, $(SRCS_BASENAME))
GNL_EXT				=	$(addsuffix .c, $(GNL_SRCS))
PRINTF_EXT			=	$(addsuffix .c, $(PRINTF_SRCS))
UTILS_EXT			=	$(addsuffix .c, $(UTILS_SRCS))

SRCS				=	$(addprefix $(PATH_SRCS)/ft_, $(SRCS_EXT))		\
						$(addprefix $(PATH_SRCS)/ft_, $(PRINTF_EXT))	\
						$(addprefix $(PATH_SRCS)/, $(GNL_EXT))			\
						$(addprefix $(PATH_SRCS)/, $(UTILS_EXT))		\

OBJS				=	$(addprefix $(PATH_OBJS)/ft_, $(SRCS_EXT:.c=.o))	\
						$(addprefix $(PATH_OBJS)/ft_, $(PRINTF_EXT:.c=.o))	\
						$(addprefix $(PATH_OBJS)/, $(GNL_EXT:.c=.o))		\
						$(addprefix $(PATH_SRCS)/, $(UTILS_EXT:.c=.o))		\

ifeq ($(SYS_ENDIAN), 1)
	CFLAGS			+=	-DSYS_ENDIAN
endif

$(PATH_OBJS)/%.o:	$(PATH_SRCS)/%.c
					$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS)
					@ar rcs $(NAME) $(OBJS)

all:				$(NAME)

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

bonus:				all

re:					fclean all

.PHONY:				all clean fclean re
