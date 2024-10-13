/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:16:07 by moutdili          #+#    #+#             */
/*   Updated: 2024/10/13 06:22:54 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

int	print_char_buffered(char c, char *buffer, int *index)
{
	if (*index >= BUFFER_SIZE)
		return (-1);
	buffer[(*index)++] = c;
	return (1);
}

int	print_str(const char *str, char *buffer, int *index)
{
	int	count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		if (print_char_buffered(*str++, buffer, index) < 0)
			return (-1);
		count++;
	}
	return (count);
}

int	print_number(long n, char *buffer, int *index)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (print_char_buffered('-', buffer, index) < 0)
			return (-1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += print_number(n / 10, buffer, index);
	if (print_char_buffered((n % 10) + '0', buffer, index) < 0)
		return (-1);
	count++;
	return (count);
}

int	print_unsigned(unsigned long n, char *buffer, int *index)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10, buffer, index);
	if (print_char_buffered((n % 10) + '0', buffer, index) < 0)
		return (-1);
	count++;
	return (count);
}

int	print_hex(unsigned long n, char *buffer, int *index, int uppercase)
{
	const char	*digits;
	int			count;

	count = 0;
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (n >= 16)
		count += print_hex(n / 16, buffer, index, uppercase);
	if (print_char_buffered(digits[n % 16], buffer, index) < 0)
		return (-1);
	count++;
	return (count);
}
