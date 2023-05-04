/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:39:25 by pbrantne          #+#    #+#             */
/*   Updated: 2022/10/16 17:40:30 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst1;
	char	*src1;

	i = -1;
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (!dst1 && !src1)
		return (NULL);
	if (src1 < dst1)
	{
		while ((int)(--n) >= 0)
			*(dst1 + n) = *(src1 + n);
	}
	else
	{
		while (++i < n)
			*(dst1 + i) = *(src1 + i);
	}
	return (dst);
}
