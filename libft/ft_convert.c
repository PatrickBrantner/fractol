/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:02:10 by pbrantne          #+#    #+#             */
/*   Updated: 2022/11/10 20:14:50 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_print(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

int	ft_convert(unsigned long long num)
{
	static char	set[] = "0123456789ABCDEF";
	char		*ptr;
	int			i;
	int			j;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	j = ft_strlen_print(num);
	i = ft_strlen_print(num);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	*(ptr + i) = '\0';
	while (num != 0)
	{
		ptr[i - 1] = set[num % 16];
		i--;
		num /= 16;
	}
	ft_putstr(ptr);
	free(ptr);
	return (j);
}
