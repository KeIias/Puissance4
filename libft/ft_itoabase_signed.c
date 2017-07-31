/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_signed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 02:18:37 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/25 14:52:44 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoabase_signed(long long int nbr, int base)
{
	char	*s;
	int		neg;
	char	tmp;

	s = ft_strnew(0);
	neg = 0;
	if (nbr < 0 && (++neg))
		nbr = -nbr;
	else if (!nbr)
		return ((s = ft_stradd_leakless(s, '0')));
	while (nbr && base > 1 && base < 37)
	{
		tmp = (char)(nbr % base);
		if (tmp > 9)
			tmp += 'a' - 10;
		else
			tmp += '0';
		s = ft_stradd_leakless(s, tmp);
		nbr /= base;
	}
	if (neg)
		s = ft_stradd_leakless(s, '-');
	return ((s = ft_strrev_leakless(s)));
}
