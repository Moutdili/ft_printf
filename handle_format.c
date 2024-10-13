/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:15:47 by moutdili          #+#    #+#             */
/*   Updated: 2024/10/13 05:26:26 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_format(char specifier, va_list args, char *buffer, int *index)
{
    int count = 0;

    if (specifier == 'c')
        count = print_char_buffered(va_arg(args, int), buffer, index);
    else if (specifier == 's')
        count = print_str(va_arg(args, char *), buffer, index);
    else if (specifier == 'd' || specifier == 'i')
        count = print_number(va_arg(args, int), buffer, index);
    else if (specifier == 'u')
        count = print_unsigned(va_arg(args, unsigned int), buffer, index);
    else if (specifier == 'x')
        count = print_hex(va_arg(args, unsigned int), buffer, index, 0);
    else if (specifier == 'X')
        count = print_hex(va_arg(args, unsigned int), buffer, index, 1);
    else if (specifier == 'p')
        count = print_pointer(va_arg(args, void *), buffer, index);
    else if (specifier == '%')
        count = print_char_buffered('%', buffer, index);
    if (count < 0)
        return (-1);
    return (count);
}
