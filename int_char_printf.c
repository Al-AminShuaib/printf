#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format,...)
{
    int i = 0;
    int res;

    va_list values;
    va_start(values, format);

    while (format[i])
    {

        if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i' || format[i + 1] == 'u'))
        {
            res = va_arg(values, int);
            printf("%d", res);
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == 'c')
        {
                res = (char)va_arg(values, int);
                printf("%c", res);
                i++;
        }
        else
        {
            printf("%c", format[i]);
        }
        i++;
    }
    va_end(values);
 
    return (0);
}