/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:01:16 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/25 14:51:34 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	digit_count(long numb)
{
	int	counter;

	counter = 0;
	if (numb < 0)
	{
		counter++;
		numb = -numb;
	}
	while (numb > 9)
	{
		counter++;
		numb /= 10;
	}
	counter++;
	return (counter);
}

int	ft_printf_decimal(int num)
{
	int		counter;
	long	numb;
	char	*str;

	numb = (long)num;
	counter = digit_count(numb);
	str = ft_itoa(num);
	write(1, str, counter);
	free(str);
	return (counter);
}
