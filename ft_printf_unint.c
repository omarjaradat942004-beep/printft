/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 19:47:16 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/25 14:52:59 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	digit_count(unsigned long num)
{
	int	counter;

	counter = 0;
	while (num > 9)
	{
		counter++;
		num /= 10;
	}
	counter++;
	return (counter);
}

int	ft_printf_unint(unsigned int num)
{
	int		counter;
	int		counter2;
	char	*str;

	counter = digit_count(num);
	counter2 = counter;
	counter--;
	str = malloc(counter2 * sizeof(char) + 1);
	while (counter >= 0)
	{
		str[counter] = (num % 10) + '0';
		num /= 10;
		counter--;
	}
	str[counter2] = '\0';
	write(1, str, counter2);
	free(str);
	return (counter2);
}
