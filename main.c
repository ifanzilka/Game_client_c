/*
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
int main()
{
	//char *url = "chopin.skyseven.ru";
	//char *port = "5703";
	const char *adr = "152.89.216.205";
	int listener_d = socket(PF_INET, SOCK_STREAM,0);
	if (listener_d == - 1)
	{
		printf("Ошибка\n");
	}
	struct  sockaddr_in name;
	name.sin_family = PF_INET;
	name.sin_port = (in_port_t)htons(5703);
	name.sin_addr.s_addr=htonl(INADDR_ANY);
	int c = bind(listener_d,&name,sizeof(name));
	if (c == -1)
	{
		printf("Не могу связаться\n");
	}
	return (0);
}
*/


#include "libft.h"
#include "clent.h"


int 	ft_create_game(int socket)
{


	ft_send_msg(socket,"POST LOBBY {\"width\":10,\"height\":10,\"gameBarrierCount\":3,\"playerBarrierCount\":2,\"name\":\"TEST_GAME54\",\"players_count\":2}");
	ft_read_msg(socket);
	return (0);
}


int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;	
	struct sockaddr_in si;

	if (argc < 2)
	{
		printf("Напишите login для соединения  в argc [./a.out fanzil]\n");
		return (1);
	}
	int s = socket(PF_INET, SOCK_STREAM, 0);
	si.sin_family = PF_INET;
	si.sin_addr.s_addr=inet_addr("152.89.216.205");
	si.sin_port=htons(5703);
	int c = connect(s, (struct sockaddr*) &si, sizeof(si));

	g_fd_logs =  open("logs", O_WRONLY | O_APPEND | O_CREAT, 0644);

	if (c == -1)
	{
		printf("Не могу подключится\n");
		return (1);
	}

	if (ft_connection_in_sever(s, argv[1]) == 1)
	{
		return (1);
	}
	//ft_create_game(s);
}
