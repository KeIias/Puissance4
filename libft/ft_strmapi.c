/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:31:15 by mapandel          #+#    #+#             */
/*   Updated: 2016/12/27 00:03:30 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*scpy;
	char			*result;

	i = 0;
	scpy = NULL;
	result = NULL;
	if (!s || !f || !(scpy = ft_strdup(s))
		|| !(result = ft_strnew(ft_strlen(scpy))))
		return (NULL);
	while (i < ft_strlen(scpy))
	{
		result[i] = f(i, scpy[i]);
		i++;
	}
	return (result);
}
