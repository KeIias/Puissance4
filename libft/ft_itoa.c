/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:55:11 by mapandel          #+#    #+#             */
/*   Updated: 2016/11/16 15:01:32 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getsize(int n)
{
	size_t		len;

	len = 1;
	while (n /= 10)
		++len;
	return (len);
}

char			*ft_itoa(int n)
{
	char		*result;
	size_t		len;
	int			ncpy;

	result = NULL;
	len = 0;
	ncpy = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_getsize(n);
	if (n < 0)
		++len;
	if (n < 0)
		ncpy = -n;
	if ((result = ft_strnew(len)) == NULL)
		return (NULL);
	result[len] = '\0';
	result[--len] = ncpy % 10 + '0';
	while (ncpy /= 10)
		result[--len] = ncpy % 10 + '0';
	if (n < 0)
		result[--len] = '-';
	return (result);
}
