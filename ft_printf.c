#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>



int ft_printf(const char *format, ...)
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int index = 0, count = 0, res;

    va_start(args, format);
    while (*format)
    {
        res = process_char(&format, args, buffer, &index);
        if (res < 0)
        {
            va_end(args);
            return (-1);
        }
        count += res;
        format++;
    }
    if (write(1, buffer, index) < 0)
    {
        va_end(args);
        return (-1);
    }
    va_end(args);
    return (count);
}
