/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:13:17 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/24 20:37:16 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	size_t	index;
	size_t	counter;

	index = 0;
	counter = 0;
	while (str[index])
	{
		write(1, &str[index], 1);
		index++;
		counter++;
	}
	return (counter);
}
/*
int main()
{
	char str[]="omar jaradat";
	ft_printf_str(str);
}
*/
