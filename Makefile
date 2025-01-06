NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I. -I$(INC_DIR)

VARGS = --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes

LIBFT       = $(LIBFT_DIR)/libft.a
LIBFT_DIR   = 42_Libft
INC_DIR     = inc
SRC_DIR     = src
UTILS_DIR   = $(SRC_DIR)/utils
INIT_DIR    = $(SRC_DIR)/init


SRC		=	$(SRC_DIR)/main.c \


all: $(LIBFT) $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT)

$(LIBFT_DIR):
	git clone git@github.com:m3irel3s/42_Libft.git $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

gdb: all $(NAME)
	tmux split-window -h "gdb --tui --args --log-file=gdb.txt ./$(NAME)"
	tmux resize-pane -L 5
	make get_log

get_log:
	rm -f gdb.txt
	touch gdb.txt
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

clean:
	rm -f $(NAME) $(NAME_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rm -rf $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
