/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuna <kmatsuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 23:01:07 by kmatsuna          #+#    #+#             */
/*   Updated: 2024/06/22 23:11:17 by kmatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void write_nbr(int n, int fd)
{
    char c;

    if (n/10 >= 1)
        write_nbr(n/10,fd);
    c = n%10 + '0';
    write(fd,&c,1);
}

void ft_putnbr_fd(int n, int fd)
{
    long nbr;

    nbr = n;
    if (n < 0)
    {
        write(fd, "-", 1);
        nbr = nbr * -1;
    }
    write_nbr(nbr,fd);

}
