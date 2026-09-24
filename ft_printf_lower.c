/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:40:25 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/24 20:34:18 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_lower(unsigned int num)
{
	size_t			counter;
	char			re;
	char			str[17];

	counter = 15;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (num != 0)
	{
		re = "0123456789abcdef"[num % 16];
		str[counter] = re;
		counter--;
		num /= 16;
	}
	str[16] = '\0';
	write(1, &str[counter + 1], 16 - counter);
	return (15 - counter);
}
/*
int main()
{
	unsigned int	num = 1234;
	ft_printf_lower(num);
}
*/
