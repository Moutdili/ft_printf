/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:39:48 by moutdili          #+#    #+#             */
/*   Updated: 2024/10/13 06:03:44 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	init_and_start(int *nm1, int *nm2)
{
	if (nm1 != NULL)
	{
		*nm1 = 0;
	}
	if (nm2 != NULL)
	{
		*nm2 = 0;
	}
}

int	handle_error(va_list *args)
{
	va_end(*args);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	char		buffer[BUFFER_SIZE];
	int			index;
	int			count;
	int			res;

	init_and_start(&index, &count);
	va_start(args, format);
	while (*format)
	{
		res = process_char(&format, args, buffer, &index);
		if (res < 0)
		{
			return (handle_error(&args));
		}
		count += res;
		format++;
	}
	if (write(1, buffer, index) < 0)
	{
		return (handle_error(&args));
	}
	va_end(args);
	return (count);
}
