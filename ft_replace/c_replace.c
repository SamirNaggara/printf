/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:31:17 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/26 00:35:16 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

char	*c_replace(char *str, t_flag_list *flag, va_list *args)
{
	char	*to_return;

	to_return = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (!to_return)
		return (NULL);
	ft_strlcpy(to_return, str, flag->length_flag + 1);
	to_return[flag->length_flag] = va_arg(*args, int);
	to_return[flag->length_flag + 1] = '\0';
	ft_strlcat(to_return, str + flag->length_flag + 2, ft_strlen(str));
	free(str);
	return (to_return);
}
