/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:33:19 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/25 00:33:20 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "clent.h"

int 	ft_send_msg(int socket, char *str)
{
	int res;

	res = send(socket, str , strlen(str), 0);
	if (res == -1)
	{
        ft_putstr_fd("Ошибка,при отправке сообщения серверу\n", g_fd_logs);
		return (1);
	}
	return (0);
}
