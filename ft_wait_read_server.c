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
    
    str = NULL;
    while(1)
    {
        str = ft_read_msg(socket);
        if (ft_strnstr(str, "SOCKET STARTGAME", ft_strlen(str)) != NULL)
        {
            printf("Start Game!\n");
            //первый ход
            
        }
        else if (ft_strnstr(str, "SOCKET ENDGAME", ft_strlen(str)) != NULL)
        {
            printf("Game end!\n");
            ft_end_game(str);
        }
        else if (ft_strnstr(str, "SOCKET STEP", ft_strlen(str)) != NULL)
        {

        }
        free(str);
    }
}
