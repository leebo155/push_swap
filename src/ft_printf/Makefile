CC = cc
CFLAGS = -Wall -Wextra -Werror
LD = ar
LDFLAGS = -rcs
INC = -I./
NAME =  libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c ft_strjoin_free.c ft_conv.c ft_conv_number_utils.c
LIBFT = libft.a
LIBFT_DIR = ../libft
OBJS = $(SRCS:.c=.o)
MAKE_CMD = make
LIBFT_DONE = .libft_done.tmp
ALL_DONE = .all_done.tmp

.PHONY: all clean fclean re

all: $(ALL_DONE)


clean:
	$(MAKE_CMD) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE_CMD) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(LIBFT_DONE) $(ALL_DONE)

re: fclean
	$(MAKE_CMD) all

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) $@ $^

$(ALL_DONE): $(LIBFT_DIR)/$(LIBFT) $(OBJS)
	$(LD) $(LDFLAGS) $(NAME) $(OBJS) 
	touch $@

#$(LIBFT_DONE): $(LIBFT_DIR)/$(LIBFT)
#	touch $@

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE_CMD) -C $(LIBFT_DIR) all bonus
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^
