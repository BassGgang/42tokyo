/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsunagakenta <matsunagakenta@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:28:06 by kmatsuna          #+#    #+#             */
/*   Updated: 2025/01/26 19:20:41 by matsunagake      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	int					i;

	d = dest;
	s = src;
	i = 0;
	if (s > d)
	{
		while (len > 0)
		{
			d[i] = s[i];
			i++;
			len--;
		}
	}
	else if (s < d)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dest);
}

// int main(void)
// {
//     char a[] = "abcdefghijklmnopqrs";
//     ft_memmove(a+3,a,5);
//     printf("gen = %s\n",a);
//     return (0);
// }

// int main(void)
// {
//     char a[] = "01234567890";
//     memmove(a,a+2,4);
//     printf("gen = %s\n",a);
//     return (0);
// }

// 		＜＜＜＜MEMO＞＞＞＞
//				<d>      <s>
//				 の場合、頭が重複してしまうので、後ろから入れていく。

//		<s>     <d>
//				の場合、上記の逆が起きてしまうので、頭から入れていく。