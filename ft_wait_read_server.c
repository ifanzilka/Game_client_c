/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_read_server.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 01:18:39 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/25 01:18:40 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "clent.h"

void    ft_end_game(char *str)
{
    char *str1;
    char *str2;

    str1 = ft_strnstr(str,"result", ft_strlen(str));
    str1 +=9;
    str2 = ft_substr(str1, 0, 4);
    printf("You are : %s\n", str2);
}

int     ft_wait_server(int socket)
{
    char *str;
    char *barrier;
    int res;
    int i = 0;

    str = NULL;
    while(i < 100)
    {
        str = ft_read_msg(socket);
        if (ft_strnstr(str, "SOCKET STARTGAME", ft_strlen(str)) != NULL)
        {
            printf("Start Game!\n");

            res = ft_parse_start_game(str);
            if (res == 1)
            {
                barrier = ft_strnstr(str, "barriers",ft_strlen(str));
                barrier += 10;
                ft_motion(socket, barrier);
            }    
        }
        else if (ft_strnstr(str, "SOCKET ENDGAME", ft_strlen(str)) != NULL)
        {
            printf("Game end!\n");
            ft_end_game(str);
            ft_send_msg(socket, "SOCKET LEAVELOBBY");
            ft_send_msg(socket,"DISCONNECT {\"QUIT\":\"\"}");
            return(0);
        }
        else if (ft_strnstr(str, "SOCKET STEP", ft_strlen(str)) != NULL)
        {       
                res = ft_parse_step(str);
                barrier = ft_strnstr(str, "barriers",ft_strlen(str));
                barrier += 10;
                ft_motion(socket, barrier);
        }
        i++;
        free(str);
    }
    return (0);
}
