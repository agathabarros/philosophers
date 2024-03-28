/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:10:48 by agpereir          #+#    #+#             */
/*   Updated: 2023/12/06 18:18:53 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_args(const char *str, va_list args, size_t i)
{
	int	ct;

	ct = 0;
	if (str[i + 1] == '%')
		ct += (ft_print_chr(str[i + 1]));
	else if (str[i + 1] == 'c')
		ct += (ft_print_chr(va_arg(args, int)));
	else if (str[i + 1] == 's')
		ct += (ft_print_str(va_arg(args, char *)));
	else if ((str [i + 1] == 'd') | (str [i + 1] == 'i'))
		ct += (ft_print_nbr(va_arg(args, int)));
	else if (str [i + 1] == 'u')
		ct += (ft_print_unsig(va_arg(args, unsigned int)));
	else if (str [i + 1] == 'p')
		ct += (ft_print_pointer(va_arg(args, unsigned long int)));
	else if ((str [i + 1] == 'x') | (str [i + 1] == 'X'))
		ct += (ft_print_hex(va_arg(args, unsigned int), str[i + 1]));
	return (ct);
}

/*utilizamos o strchr dentro do if para porcurar se tem cspdiuxX logo apos a %
caso tenha, entramos na funcao args, se nao printamos o chr*/
int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			j += ft_args(str, args, i);
			i++;
		}
		else
		{
			ft_print_chr(str[i]);
			j++;
		}
		i++;
	}
	va_end (args);
	return (j);
}
