/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:31:58 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/25 22:32:00 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "clent.h"

//SOCKET STEP {"width":7,"height":6,"position":[5,6],"opponentPosition":[1,5],"barriers":[[[5,3],[5,4],[4,3],[4,4]]]}

int     ft_parse_step(char *str)
{
    int res;
    int true_false;

    true_false = 0;
    res = sscanf(str, "SOCKET STEP {\"width\":%d,\"height\":%d,\"position\":[%d,%d],\"opponentPosition\":[%d,%d],\"barriers\":[[[4,1],[4,0],[5,1],[5,0]],[[3,2],[3,3],[4,2],[4,3]]]}", &game.width, &game.height, &game.my_pos.x, &game.my_pos.y, &game.opponent_pos.x, &game.opponent_pos.y);
    if (res == 0)
    {
        printf("Ошибка парсинга\n");
    }
    //printf("scanf res: %d\n",res);
    printf("\nМоя позиция:[%d,%d]\n",game.my_pos.x, game.my_pos.y);
    printf("Позиция Оппонента:[%d,%d]\n",game.opponent_pos.x, game.opponent_pos.y);
    return (true_false);
}
