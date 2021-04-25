NAME	= game

LIBFT = libft.a
LIB_DIR =  ./libft/
LIB_NAME =	./libft/libft.a

CC		= gcc

FLAGS	= -Wall -Wextra -Werror 

HEADER	= ./includes
#HEADER_LIB = ./libft/includes
HEADERS = $(addprefix $(HEADER)/,libft.h )





F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m




SRCS = main.c ft_connect_server.c ft_send_msg.c ft_read_msg.c ft_wait_read_server.c ft_parse_start_game.c ft_motion.c ft_parse_step.c 
SRCS.O = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -I$(HEADER)  -c $< -o $@
	@echo "$(F_BLUE)Object files game in ready! $(F_NONE)"
#$(SRCS.O): %.o:%.c
#	$(CC) $(FLAGS) -I$(HEADER) -c $< -o $@
#	@echo "$(F_BLUE)Object files minishell in ready! $(F_NONE)"


all: $(LIB_NAME) $(NAME)


$(LIB_NAME):
		@echo "$(F_YELLOW)START RUN Makefile in libft $(F_NONE)"
		@$(MAKE) -C $(LIB_DIR)
		rm includes/libft.h
		cp  libft/includes/libft.h includes/
		@echo "$(F_YELLOW)END RUN Makefile in libft $(F_NONE)"

$(NAME): $(SRCS.O) $(HEADERS)
		@echo "$(F_CYAN)Compile client ...$(F_NONE)"
		$(CC) $(FLAGS)  -I$(HEADER)  $(SRCS.O) -L. $(LIB_NAME) -o $(NAME)
		@echo "$(F_GREEN)Game is Ready! GOOD LUCK:) $(F_NONE)"


clean:

	rm -rf $(SRCS.O)
	@echo "$(F_GREEN)Object files game delete!$(F_NONE)"
fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME)
	@echo "$(F_GREEN)Delete $(NAME_MINISHELL) FCleaned! $(F_NONE)"

re: fclean all

norm:
	norminette *.c *.h

code:
	@echo " ~~~~~~~~~~~~~~~~"
	@echo "$(F_BOLD)  * Make code, *"
	@echo "$(F_BOLD)   * not war! *"
	@echo "$(F_RED)    ..10101.."
	@echo "$(F_ORANGE)  01    1    10"
	@echo "$(F_YELLOW) 10     0     00"
	@echo "$(F_GREEN) 11   .010.   11"
	@echo "$(F_CYAN) 00 .01 1 01. 10"
	@echo "$(F_BLUE)  010   1   110"
	@echo "$(F_BLUE)    110110101$(F_NONE)"

.PHONY:     all clean fclean re bonus code
