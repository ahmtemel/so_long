/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 06:21:56 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/07/21 17:40:31 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_pri(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen_pri(src));
}

char	*ft_strdup(const char *s1)
{
	char	*d;
	size_t	len;

	len = ft_strlen_pri(s1) + 1;
	d = (char *)malloc(len * 1);
	if (!d)
		return (0);
	ft_strlcpy(d, s1, len);
	return (d);
}

static long	ft_len(long src)
{
	int	i;

	i = 0;
	if (src < 0)
	{
		src *= -1;
		i++;
	}
	while (src > 0)
	{
		src /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long n)
{
	char	*ret;
	int		i;
	long	num;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	i = ft_len(num);
	ret = malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		num *= -1;
		ret[0] = '-';
	}
	ret[i] = 0;
	i--;
	while (i >= 0 && num > 0)
	{
		ret[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (ret);
}
