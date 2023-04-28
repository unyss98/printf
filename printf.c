#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
 *  _printf - prints format string
 *  @format: pointer to input string
 *  Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i, j, k, cv, dv, temp, dd, nd, l, m, count = 0;
	unsigned int ov, uv, xv, Xv;
	char *sv;

	va_start(list, format);
	if (format == NULL || strcmp(format, "%") == 0)
		exit(1);
	for (i = 0; format[i] != '\0'; i++)
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					cv = va_arg(list, int), putchar(cv), count++;
					break;
				case 's':
					sv = va_arg(list, char*);
					if (sv == NULL)
						exit(1);
					for (j = 0; sv[j] != '\0'; j++)
						putchar(sv[j]), count++;
					break;
				case 'd':
				case 'i':
					dv = va_arg(list, int);
					if (dv == INT_MIN)
					{
						fputs("-2147483648", stdout);
						return (count += 11);
						break;
					}
					if (dv == INT_MAX)
					{
						fputs("2147483648", stdout);
						return (count += 10);
					}
					if (dv < 0)
					{
						putchar('-');
						dv = -dv;
						count++;
					}
					if (dv == 0)
					{
						putchar('0');
						count++;
						break;
					}
					nd = 0, temp = dv;
					while (temp != 0)
						temp /= 10, nd++;
					for (k = nd - 1; k >= 0; k--)
					{
						l = 1;
						for (m = 0; m < k; m++)
						{
							l *= 10;
						}
						dd = dv / l % 10;
						putchar('0' + dd);
						count++;
					}
					break;
				case 'u':
					uv = va_arg(list, unsigned int);
					if (uv == 0)
					{
						putchar('0');
						count++;
						break;
					}
					nd = 0, temp = uv;
					while (temp != 0)
						temp /= 10, nd++;
					for (k = nd - 1; k >= 0; k--)
					{
						l = 1;
						for (m = 0; m < k; m++)
							l *= 10;
						dd = uv / l % 10;
						putchar('0' + dd);
						count++;
					}
					break;
				case 'o':
                                        ov = va_arg(list, unsigned int);
                                        if (ov == 0)
                                        {
                                                putchar('0');
                                                count++;
                                                break;
                                        }
                                        nd = 0, temp = ov;
                                        while (temp != 0)
                                                temp /= 8, nd++;
                                        for (k = nd - 1; k >= 0; k--)
                                        {
                                                l = 1;
                                                for (m = 0; m < k; m++)
                                                        l *= 8;
                                                dd = ov / l % 8;
                                                putchar('0' + dd);
                                                count++;
                                        }
                                        break;
				case 'x':
                                        xv = va_arg(list, unsigned int);
                                        if (xv == 0)
                                        {
                                                putchar('0');
                                                count++;
                                                break;
                                        }
                                        nd = 0, temp = xv;
                                        while (temp != 0)
                                                temp /= 0x10, nd++;
                                        for (k = nd - 1; k >= 0; k--)
                                        {
                                                l = 1;
                                                for (m = 0; m < k; m++)
                                                        l *= 0x10;
                                                dd = xv / l % 0x10;
                                                putchar((dd < 10) ? ('0' + dd) : ('a' + dd));
                                                count++;
                                        }
					break;
				case 'X':
                                        Xv = va_arg(list, unsigned int);
                                        if (Xv == 0)
                                        {
                                                putchar('0');
                                                count++;
                                                break;
                                        }
                                        nd = 0, temp = Xv;
                                        while (temp != 0)
                                                temp /= 0X10, nd++;
                                        for (k = nd - 1; k >= 0; k--)
                                        {
                                                l = 1;
                                                for (m = 0; m < k; m++)
                                                        l *= 0X10;
                                                dd = xv / l % 0X10;
                                                putchar((dd < 10) ? ('0' + dd) : ('X' + dd));
                                                count++;
                                        }
                                        break;
				case '%':
					putchar('%'), count++;
					break;
				default:
					putchar('%'), putchar(format[i]), count += 2;
					break;
			}
		}
		else
			putchar(format[i]), count++;
	va_end(list);
	return (count);
}
