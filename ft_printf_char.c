/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 11:47:00 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/23 12:12:09 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int     ft_printf_char(int c)
{
	char	s;

	s = c;	
	write (1,&s,1);
	return (1);
}

int main()
{
	ft_printf_char('A');

}
