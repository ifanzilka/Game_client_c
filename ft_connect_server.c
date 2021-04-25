/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_server.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 00:28:54 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/25 00:29:10 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "clent.h"

static  int     ft_name_cnt(char *str)
{
    int i = 0;

    while(str[i] != '\"')
    {
        i++;
    }
    return (i);
}

static int     ft_connect_random_game(int socket)
{
    char *str = "SOCKET JOINLOBBY {\"id\":null}";
    char *new_msg;
    int num;
    char *name;

    new_msg = NULL;
    ft_send_msg(socket, str);
    new_msg = ft_read_msg(socket);
    if (new_msg != NULL)
    {
        ft_putstr_fd("Подключение прошло успешно!\n", 1);
        num = ft_atoi(new_msg + 16);
        printf("id игры : %d \n", num);
        name = ft_strnstr(new_msg,"\"name\":\"", ft_strlen(new_msg));
        name = name + 8;
        printf("Игра с названием : %s\n",ft_substr(name, 0, ft_name_cnt(name)));
        ft_wait_server(socket);
    }
    return (0);
}

static int ft_connect_id_game(int socket)
{
    char *str1= "SOCKET JOINLOBBY {\"id\":\"";
    char *str3 = "\"}";
    char *str_num;
    char *main_str;
    //char *read_msg;
    int num;
    
    ft_putstr_fd("Напишите id игры к которой хотите подключится\n",1);
    scanf("%d", &num);
    str_num = ft_itoa(num);
    main_str = ft_strjoin(str1, str_num);
    main_str = ft_strjoin(main_str,str3);
    //printf("main str : %s\n",main_str);
    ft_send_msg(socket, main_str);
    ft_wait_server(socket);
    return (0);
}

int 	ft_connection_in_sever(int socket, char *name)
{
	char *str1 ="CONNECTION {\"LOGIN\":\"";
	char *str3 = "\"}";
	char *msg1 = ft_strjoin(str1, name);
	char *msg2 = ft_strjoin(msg1,str3);
	char *str_read;
    int option;

	str_read = NULL;
	ft_send_msg(socket, msg2);
	str_read = ft_read_msg(socket);
    if (ft_strnstr(str_read, "LOGIN OK", ft_strlen(str_read)) != NULL)
    {
        ft_putstr_fd("Вы успешно вошли!\n", 1);
        ft_putstr_fd("Выберите опцию:\n1 -> подключится к рандомной игре\n2 -> подключится к игре по id\n",1);
        scanf("%d", &option);
        if (option != 1 && option !=2 )
        {
             ft_putstr_fd("Нет такого номера, до свиданья!\n", 1);
             return (1);
        }
        if (option == 1)
        {
            ft_connect_random_game(socket);
        }
        else
        {
            ft_connect_id_game(socket);
        }  
    }
    else
    {
        ft_putstr_fd("Не удалось войти, попробуйте другой логин :(\n", 1);
        free(str_read);
	    free(msg1);
	    free(msg2);
        return (1);
    }
    free(str_read);
	free(msg1);
	free(msg2);
	return (0);
}
