/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsunagakenta <matsunagakenta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:55:03 by kmatsuna          #+#    #+#             */
/*   Updated: 2025/01/26 19:02:49 by matsunagake      ###   ########.fr       */
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
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
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

// 0 1 2 3 k e n \0