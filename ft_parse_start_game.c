/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_start_game.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:38:09 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/25 21:38:10 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "clent.h"

//SOCKET STARTGAME {"move":false,"width":5,"height":7,"position":[6,1],"opponentPosition":[0,1],"barriers":[[[4,1],[4,0],[5,1],[5,0]],[[3,2],[3,3],[4,2],[4,3]]]}

int     ft_parse_start_game(char *str)
{
    int res;
    int true_false;

    true_false = 0;
    res = sscanf(str,"SOCKET STARTGAME {\"move\":false,\"width\":%d,\"height\":%d,\"position\":[%d,%d],\"opponentPosition\":[%d,%d],\"barriers\":[[[4,1],[4,0],[5,1],[5,0]],[[3,2],[3,3],[4,2],[4,3]]]}", &game.width, &game.height, &game.my_pos.x, &game.my_pos.y, &game.opponent_pos.x, &game.opponent_pos.y);
    if (res == 0)
    {
        true_false = 1;
        res = sscanf(str,"SOCKET STARTGAME {\"move\":true,\"width\":%d,\"height\":%d,\"position\":[%d,%d],\"opponentPosition\":[%d,%d],\"barriers\":[[[4,1],[4,0],[5,1],[5,0]],[[3,2],[3,3],[4,2],[4,3]]]}", &game.width, &game.height, &game.my_pos.x, &game.my_pos.y, &game.opponent_pos.x, &game.opponent_pos.y);
    }
    printf("scanf res: %d\n",res);
    printf("Параметры игры:\nwidth:%d\nheight:%d\n",game.width, game.height);
    printf("Моя позиция:[%d,%d]\n",game.my_pos.x, game.my_pos.y);
    printf("Позиция Оппонента:[%d,%d]\n",game.opponent_pos.x, game.opponent_pos.y);
    return (true_false);
}

