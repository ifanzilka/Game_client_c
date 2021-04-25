/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 18:31:08 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/07 21:25:51 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ENG
*/

/*
** RUS
**
** Функция ft_swap_str заменяет местами строки в массиве char**
**
** RETURN
*/

void	ft_swap_str(void *p1, void *p2)
{
	char **s1;
	char **s2;
	char *tmp;

	s1 = (char **)p1;
	s2 = (char**)p2;
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
