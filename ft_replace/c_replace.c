/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:31:17 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/26 17:07:17 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

char	*c_replace(char *str, t_flag_list *flag, va_list *args, size_t *size)
{
	char	*to_return;
	char	car;
	size_t	i;


	*size = *size - 1;

	car = va_arg(*args, int);
	to_return = (char *)malloc(sizeof(char) * (*size + 1));
	if (!to_return)
		return (NULL);
	i = 0;
	while (i < flag->length_flag)
	{
		to_return[i] = str[i];
		i++;
	}
	to_return[flag->length_flag] = car;
	i = 0;
	while (flag->length_flag + 1 + i < *size)
	{
		to_return[flag->length_flag + 1 + i] = str[flag->length_flag + 2 + i];
		i++;
	}
	to_return[*size] = '\0';

	free(str);
	return (to_return);
}
// a%cc\n        	Size = 5
// a0c\n   		    Size = 4