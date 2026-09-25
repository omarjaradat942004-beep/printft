/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omajarad <omajarad@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 09:56:56 by omajarad          #+#    #+#             */
/*   Updated: 2026/09/25 10:19:25 by omajarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *ptr, ...);
int	ft_printf_char(int c);
int	ft_printf_decimal(int num);
int	ft_printf_lower(unsigned int num);
int	ft_printf_ptr(void *ptr);
int	ft_printf_str(char *str);
int	ft_printf_unint(unsigned int num);
int	ft_printf_upper(unsigned int num);

#endif
