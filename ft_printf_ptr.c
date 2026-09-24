/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:18:18 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/24 20:39:14 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(void *ptr)
{
	unsigned long	num;
	size_t			counter;
	char			re;
	char			str[17];

	counter = 15;
	num = (unsigned long)ptr;
	if (num == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	while (num != 0)
	{
		re = "0123456789abcdef"[num % 16];
		str[counter] = re;
		counter--;
		num /= 16;
	}
	str[16] = '\0';
	write(1, "0x", 2);
	write(1, &str[counter + 1], 16 - counter);
	return (15 - (counter - 2));
}
/*
#include <stdio.h>
int main()
{
	char str[]="omar";
	void	*ptr = str;
	printf("\n%d",ft_printf_ptr(ptr));
}
*/
