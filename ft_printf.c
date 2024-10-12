/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 06:50:08 by moutdili          #+#    #+#             */
/*   Updated: 2024/10/12 05:32:26 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>   // Pour write
#include <stddef.h>   // Pour NULL
#include "ft_printf.h"

#define BUFFER_SIZE 1024

void flush_buffer(char *buffer, int *index)
{
    write(1, buffer, *index);
    *index = 0;
}

int print_char_buffered(char c, char *buffer, int *index)
{
    buffer[(*index)++] = c;
    if (*index == BUFFER_SIZE)
        flush_buffer(buffer, index);
    return 1;
}

int print_str(char *s, char *buffer, int *index)
{
    int count = 0;

    if (s == NULL)
        s = "(null)";
    while (*s)
        count += print_char_buffered(*s++, buffer, index);
    return count;
}

int print_number_base(unsigned long n, int base, char *range, char *buffer, int *index)
{
    int count = 0;

    if (n >= (unsigned long)base)
        count += print_number_base(n / base, base, range, buffer, index);
    count += print_char_buffered(range[n % base], buffer, index);
    return count;
}

int print_unsigned(unsigned int n, char *buffer, int *index)
{
    return print_number_base(n, 10, "0123456789", buffer, index);
}

int print_hex(unsigned int n, int uppercase, char *buffer, int *index)
{
    char *range = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    return print_number_base(n, 16, range, buffer, index);
}

int print_pointer(void *ptr, char *buffer, int *index)
{
    int count = 0;
    count += print_str("0x", buffer, index);
    count += print_hex((unsigned long)ptr, 0, buffer, index);
    return count;
}

int handle_format(char specifier, va_list args, char *buffer, int *index)
{
    if (specifier == 'c')
        return print_char_buffered(va_arg(args, int), buffer, index);
    else if (specifier == 's')
        return print_str(va_arg(args, char *), buffer, index);
    else if (specifier == 'd' || specifier == 'i')
    {
        int n = va_arg(args, int);
        if (n < 0)
        {
            print_char_buffered('-', buffer, index);
            return print_number_base(-n, 10, "0123456789", buffer, index) + 1;
        }
        return print_number_base(n, 10, "0123456789", buffer, index);
    }
    else if (specifier == 'u')
        return print_unsigned(va_arg(args, unsigned int), buffer, index);
    else if (specifier == 'x')
        return print_hex(va_arg(args, unsigned int), 0, buffer, index);
    else if (specifier == 'X')
        return print_hex(va_arg(args, unsigned int), 1, buffer, index);
    else if (specifier == 'p')
        return print_pointer(va_arg(args, void *), buffer, index);
    else if (specifier == '%')
        return print_char_buffered('%', buffer, index);
    return 0;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char buffer[BUFFER_SIZE];
    int index = 0;

    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            count += handle_format(*format, args, buffer, &index);
        }
        else
            count += print_char_buffered(*format, buffer, &index);
        format++;
    }
    va_end(args);
    flush_buffer(buffer, &index);
    return count;
}

