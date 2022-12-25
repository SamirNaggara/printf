/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:24:48 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 19:42:47 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../printf.h"

char	*s_replace(char *str, t_flag_list *flag, va_list *args)
{
	char	*to_return;
	size_t	length;
	char	*arg;

	arg = va_arg(*args, char *);
	to_return = (char *)malloc(sizeof(char)
			* (ft_strlen(str) - 1 + ft_strlen(arg)));
	if (!to_return)
		return (NULL);
	ft_strlcpy(to_return, str, flag->length_flag + 1);
	ft_strlcat(to_return, arg, flag->length_flag + 1 + ft_strlen(arg));
	ft_strlcat(to_return, str + flag->length_flag + 2,
		ft_strlen(str)+ ft_strlen(arg) - 1);
	free(str);
	return (to_return);
}
