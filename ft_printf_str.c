/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:13:17 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/25 14:52:40 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	size_t	index;
	int		counter;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
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
