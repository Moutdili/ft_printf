/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutdili <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 05:16:26 by moutdili          #+#    #+#             */
/*   Updated: 2024/10/13 05:23:16 by moutdili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

int print_pointer(void *ptr, char *buffer, int *index)
{
    int count = 0;
    if (print_str("0x", buffer, index) < 0)
        return (-1);
    if (ptr == NULL)
    {
        if (print_str("0", buffer, index) < 0)
            return (-1);
        count += 3; // "0x" + "0"
    }
    else
    {
        count += print_hex((unsigned long)ptr, buffer, index, 0) + 2; // "0x" + hex value
    }
    return (count);
}

