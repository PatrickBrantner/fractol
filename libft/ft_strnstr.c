/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrantne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:22:29 by pbrantne          #+#    #+#             */
/*   Updated: 2022/10/15 15:04:34 by pbrantne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((i < len && big[i] != '\0') || i == 0)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && little[j] != '\0')
			j++;
		if ((little[j] == '\0') || little[j] == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
