/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuna <kmatsuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:46:32 by kmatsuna          #+#    #+#             */
/*   Updated: 2024/06/22 22:56:33 by kmatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    while(s[i] != 0)
    {
		write(fd,&s[i],1);
		i ++;
    }
}