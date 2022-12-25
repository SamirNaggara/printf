/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:31:55 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 19:36:45 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../printf.h"

char	*x_replace(char *str, t_flag_list *flag, va_list *args)
{
	char	*to_return;
	char	*number;
	size_t	length;

	number = ft_itoa_hexa(va_arg(*args, int));
	if (!number)
		return (NULL);
	to_return = (char *)malloc(sizeof(char)
			* (ft_strlen(str) - 1 + ft_strlen(number)));
	ft_strlcpy(to_return, str, flag->length_flag + 1);
	ft_strlcat(to_return, number, flag->length_flag + 1 + ft_strlen(number));
	ft_strlcat(to_return, str + flag->length_flag + 2,
		ft_strlen(str)+ ft_strlen(number) - 1);
	free(str);
	free(number);
	return (to_return);
}
