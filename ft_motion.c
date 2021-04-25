/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_motion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:00:29 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/25 22:00:29 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "clent.h"

int     ft_motion(int socket,char *str)
{
    (void) socket;
    printf("Мы были в [%d,%d]\n",game.my_pos.x, game.my_pos.y);

    if (game.my_pos.y + 1 <= game.height)
    {
        game.my_pos.y+=1;
    }
    else if (game.my_pos.x + 1 <= game.width)
    {
         game.my_pos.y+=1;
    }
    else if (game.my_pos.y - 1 >= 0)
    {
        game.my_pos.y-=1;
    }
    else if (game.my_pos.x - 1 >= 0)
    {   
        game.my_pos.x-=1;
    }

    dprintf(g_fd_logs, "Мы отправили на сервер:\n");
    dprintf(g_fd_logs, "SOCKET STEP {\"width\":%d,\"height\":%d,\"position\":[%d,%d],\"opponentPosition\":[%d,%d],\"barriers\":%s",game.width, game.height, game.my_pos.x, game.my_pos.y, game.opponent_pos.x, game.opponent_pos.y, str);
    dprintf(socket, "SOCKET STEP {\"width\":%d,\"height\":%d,\"position\":[%d,%d],\"opponentPosition\":[%d,%d],\"barriers\":%s",game.width, game.height, game.my_pos.x, game.my_pos.y, game.opponent_pos.x, game.opponent_pos.y, str);
    printf("Мы сделали ход в [%d,%d]\n",game.my_pos.x, game.my_pos.y);
    return(0);   
}