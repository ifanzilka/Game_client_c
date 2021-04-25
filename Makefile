
all:
	gcc -Wall -Wextra -Werror main.c ft_connect_server.c ft_send_msg.c ft_read_msg.c ft_wait_read_server.c ft_parse_start_game.c ft_motion.c ft_parse_step.c -L. libft.a -o game
