/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:24:48 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/26 19:23:33 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

char	*s_replace(char *str, t_flag_list *flag, va_list *args, size_t *size)
{
	char	*to_return;
	char	*arg;

	arg = va_arg(*args, char *);
	to_return = replace_flag_by_str(str,flag, arg, size);
	
	return (to_return);
}

char	*replace_flag_by_str(char *str, t_flag_list *flag, char *arg_str, size_t *size)
{
	size_t	i;
	size_t	j;
	char	str_null[7];
	char	*to_return;

	if (!arg_str)
	{
		ft_strlcpy(str_null, "(null)", 7);
		arg_str = str_null;
	}
	*size = ft_strlen(str) - 2 + ft_strlen(arg_str);
	to_return = (char *)malloc(sizeof(char) * (*size + 1));
	if (!to_return)
		return (NULL);
	i = 0;
	j = 0;
	while (i < flag->length_flag)
		to_return[i++] = str[j++];
	j = 0;
	while (i < flag->length_flag + ft_strlen(arg_str))
		to_return[i++] = arg_str[j++];
	j = 0;
	while (i < *size )
		to_return[i++] = str[flag->length_flag + 2 + j++];
	to_return[i] = '\0';
	free(str);
	return (to_return);
}
// a%sa\n   5
// aSamira\n  5 -2 + 5 = 
