CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Iinclude
NAME = push_swap
BONUS = checker
SRCS = src/ft_atoi_include_exit.c \
	   src/ft_make_clear_arguments_utils.c \
	   src/ft_sort_out.c \
	   src/ft_do_action_stack.c \
	   src/ft_push_swap.c \
	   src/ft_sort_stack.c \
	   src/ft_do_action_stack_extend.c \
	   src/ft_push_swap_other_utils.c \
	   src/ft_sort_stack_utils.c \
	   src/ft_make_array_utils.c \
	   src/ft_push_swap_utils.c
EXTRA_SRCS = src/ft_atoi_include_exit_bonus.c \
			 src/ft_do_action_stack_bonus.c \
			 src/ft_can_you_sort_out_bonus.c \
			 src/ft_do_action_stack_extend_bonus.c \
			 src/ft_checker_bonus.c \
			 src/ft_make_array_utils_bonus.c \
			 src/ft_checker_other_utils_bonus.c \
			 src/ft_make_clear_arguments_utils_bonus.c \
			 src/ft_checker_utils_bonus.c
FT_PRINTF = lib/libftprintf.a
GNL = lib/libgnl.a
LIBFT = lib/libft.a
OBJS = $(SRCS:.c=.o)
EXTRA_OBJS = $(EXTRA_SRCS:.c=.o)

.PHONY: bonus all clean fclean re

all: $(NAME)

bonus: $(BONUS)

clean:
	rm -f $(OBJS) $(EXTRA_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean
	$(MAKE) all

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

$(BONUS): $(FT_PRINTF) $(GNL) $(EXTRA_OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(BONUS) $(EXTRA_OBJS) $(LIBFT) $(FT_PRINTF) $(GNL)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^
