/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:04:44 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/23 11:25:28 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
int main()
{
	size_t     get_strlen(size_t n, ...)
	{

		va_list list;
		int	str_len;
		char	*str;
		size_t	index;
		size_t  index2;


		str_len = 0;
		index = 0;

		va_start(list,n);

		while (index < n)
		{
			index2 = 0;
			str = va_arg(list, char *);
			while(str[index2] != '\0')
			{
				str_len++;
				index2++;
			}
			index++;
		}
		return (str_len);
	}
	printf("%ld",get_strlen(3,"omar","khaled","jaradat"));
}
