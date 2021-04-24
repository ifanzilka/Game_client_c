/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:34:51 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/25 00:34:52 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "clent.h"


char	*ft_read_msg(int socket)
{
	char	buf[BUF];
	int		len;
	char *str;

	str = NULL;
	len = read(socket, buf, BUF);
	if (len == -1)
	{
        ft_putstr_fd("Ошибка,при чтении из сервера\n", g_fd_logs);
		return  (NULL);
	}
	buf[len] = '\0';
    ft_putstr_fd("Полученное сообщение из сервера:\n", g_fd_logs);
    ft_putstr_fd(buf, g_fd_logs);
    ft_putstr_fd("\n", g_fd_logs);
	return (ft_strdup(buf));
}
