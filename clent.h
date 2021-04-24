/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clent.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:30:56 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/25 00:30:58 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdlib.h>

#include <fcntl.h>

int 	g_fd_logs;


int 	ft_send_msg(int socket, char *str);
char	*ft_read_msg(int socket);
int 	ft_connection_in_sever(int socket, char *name);
int     ft_wait_server(int socket);


#endif
