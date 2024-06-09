/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsuna <kmatsuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:55:03 by kmatsuna          #+#    #+#             */
/*   Updated: 2024/06/09 21:00:30 by kmatsuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*re;

	i = 0;
	re = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			re = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	if (re == NULL)
		return (NULL);
	return (re);
}
// ---MEMO---
// reを初期化せずに%pを表示させようとすると「nullだから表示できない」と出力されるが、
// re = NULL　がないとif文で引っかかってくれないので注意

// int main(void)
// {
//     	char *s = "kenta";
//     printf("mine=%p\n",ft_strrchr(s,'4'));
//     printf("gen =%p\n",strrchr(s,'4'));
//     return (0);
// }