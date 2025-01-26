/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsunagakenta <matsunagakenta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:06:08 by jnishimu          #+#    #+#             */
/*   Updated: 2025/01/26 18:48:38 by matsunagake      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	chesp(const char s)
{
	if (s == '\n' || s == '\f' || s == '\t' || s == '\v' || s == '\r'
		|| s == ' ')
		return (1);
	return (0);
}

static int	chenum(const char s)
{
	if ('0' <= s && s <= '9')
		return (1);
	return (0);
}

static int	is_not_long_rang(long a, int b)
{
	long		long_max;
	long int	long_div;
	long int	long_mod;

	long_max = 9223372036854775807;
	long_div = long_max / 10;
	long_mod = long_max % 10;
	return (a > long_div || (a == long_div && b > long_mod));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			pm;
	long int	re;

	i = 0;
	pm = 1;
	re = 0;
	if (!ft_strcmp(str, "-9223372036854775808"))
		return ((int)0x8000000000000000L);
	while (chesp(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pm = pm * -1;
		i++;
	}
	while (chenum(str[i]))
	{
		if (is_not_long_rang(re, str[i] - '0'))
		{
			if (pm == -1)
				re = (int)0x8000000000000000L;
			else
				re = (int)9223372036854775807;
			break ;
		}
		re = re * 10 + (str[i] - '0');
		i++;
	}
	return (re * pm);
}
// --MEMO--
// int is_not_long_rangの戻り値である
// 	return (a > long_div || (a == long_div && b > long_mod));
// の条件式に注意が必要。

// --MEMO--
// is_not_long_rangにて不具合が発生。
// →具体的にはstr[i]をstr[i]-'0'として引数を渡したがis_not_rang関数内で反映されない
// →ft_atoi関数内でprintfを行って見るとis_not_rang関数にも反映された。
// →テスターでも反映されないものが判定されいたので割とガチで謎

// int main (void)
// {
//     char a [] = "-4";
//     printf("gen =%d\n",atoi(a));
//     printf("mine %d\n",ft_atoi(a));

//     return (0);
// }