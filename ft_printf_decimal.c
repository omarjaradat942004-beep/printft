/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 15:01:16 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/24 20:22:31 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	digit_count(long numb, int *counter)
{
	if (numb < 0)
	{
		(*counter)++;
		numb = -numb;
	}
	while (numb > 9)
	{
		(*counter)++;
		numb /= 10;
	}
	(*counter)++;
	return (*counter);
}

int	ft_printf_decimal(int num)
{
	int		counter;
	long	numb;
	char	*str;

	numb = (long)num;
	counter = 0;
	counter = digit_count(numb, &counter);
	str = ft_itoa(num);
	write(1, str, counter);
	free(str);
	return (counter);
}
/*
#include <stdio.h>
int main()
{
        int    num = 2147483647;
	printf("\n%d",ft_printf_decimal(num));
}
*/
