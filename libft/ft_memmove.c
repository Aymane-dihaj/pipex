/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:27:12 by adihaj            #+#    #+#             */
/*   Updated: 2022/10/31 15:48:45 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src,	size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return ((char *)dst);
	if (dst > src && (src + len > dst))
	{
		while (len--)
		{
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

// int main()
// {

// 	printf("%s\n", ft_memmove("aymen", "aymen", 5));
// 	//printf("%s\n", memmove("aymen", "aymen", 5));
// }
