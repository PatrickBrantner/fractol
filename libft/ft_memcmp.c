/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:26:03 by pbrantne          #+#    #+#             */
/*   Updated: 2022/10/14 13:30:24 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ptr_s1;
	const char	*ptr_s2;
	int			i;

	ptr_s1 = s1;
	ptr_s2 = s2;
	i = 0;
	while (n > 0)
	{
		if (ptr_s1[i] > ptr_s2[i])
			return ((unsigned char)ptr_s1[i] - (unsigned char)ptr_s2[i]);
		if (ptr_s1[i] < ptr_s2[i])
			return ((unsigned char)ptr_s1[i] - (unsigned char)ptr_s2[i]);
		n--;
		i++;
	}
	return (0);
}
