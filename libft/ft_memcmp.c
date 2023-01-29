/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:44:26 by adihaj            #+#    #+#             */
/*   Updated: 2022/10/31 16:00:24 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)(s1);
	str2 = (unsigned char *)(s2);
	while (n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}

// int main()
// {
// 	// int a[] = {1,4,5,6,4,5,3};
// 	// int b[] = {257,4,5,6,4,5,3};

// 	printf("%d", ft_memcmp("f","a", 1));
// 	return 0;
// }