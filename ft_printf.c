/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omar.jaradat1@learner.42.tech>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 10:13:11 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/25 14:54:42 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	specifiers(const char *ptr, size_t index,
		int *counter, va_list list)
{
	if (ptr[index] == 'c')
		(*counter) += ft_printf_char(va_arg(list, int));
	else if (ptr[index] == 's')
		(*counter) += ft_printf_str(va_arg(list, char *));
	else if (ptr[index] == 'p')
		(*counter) += ft_printf_ptr(va_arg(list, void *));
	else if (ptr[index] == 'd' || ptr[index] == 'i')
		(*counter) += ft_printf_decimal(va_arg(list, int));
	else if (ptr[index] == 'u')
		(*counter) += ft_printf_unint(va_arg(list, unsigned int));
	else if (ptr[index] == 'x')
		(*counter) += ft_printf_lower(va_arg(list, unsigned int));
	else if (ptr[index] == 'X')
		(*counter) += ft_printf_upper(va_arg(list, unsigned int));
	else if (ptr[index] == '%')
	{
		write(1, "%", 1);
		(*counter)++;
	}
}

int	ft_printf(const char *ptr, ...)
{
	va_list	list;
	size_t	index;
	int		counter;

	index = 0;
	counter = 0;
	va_start(list, ptr);
	while (ptr[index])
	{
		if (ptr[index] == '%')
		{
			index++;
			if (!ptr[index])
				break ;
			specifiers(ptr, index, &counter, list);
		}
		else
		{
			write(1, &ptr[index], 1);
			counter++;
		}
		index++;
	}
	va_end(list);
	return (counter);
}
