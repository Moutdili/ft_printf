/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process-char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:15:26 by moutdili          #+#    #+#             */
/*   Updated: 2024/10/13 05:35:10 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int process_char(const char **format, va_list args, char *buffer, int *index)
{
    int count = 0;
    int res;

    if (**format == '%')
    {
        (*format)++;
        if (**format == '%')
        {
            res = print_char_buffered('%', buffer, index);
        }
        else
        {
            res = handle_format(**format, args, buffer, index);
        }
        if (res < 0)
        {
            return -1;
        }
        count += res;
    }
    else
    {
        res = print_char_buffered(**format, buffer, index);
        if (res < 0)
        {
            return -1;
        }
        count++;
    }
    return count;
}

