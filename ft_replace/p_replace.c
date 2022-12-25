/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:31:39 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 19:39:27 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../printf.h"

char	*p_replace(char *str, t_flag_list *flag, va_list *args)
{
	char	*to_return;
	long	nbr;
	char	*char_nbr;

	nbr = (long)va_arg(*args, void *);
	char_nbr = ft_itoa_hexa(nbr);
	if (!char_nbr)
		return (NULL);
	to_return = (char *)malloc(sizeof(char)
			* (ft_strlen(str) + 1 + ft_strlen(char_nbr)));
	ft_memset(to_return, 0, ft_strlen(str) + 1 + ft_strlen(char_nbr));
	ft_strlcpy(to_return, str, flag->length_flag + 1);
	ft_strlcat(to_return, "0x", flag->length_flag + 3);
	ft_strlcat(to_return, char_nbr,
		flag->length_flag + 3 + ft_strlen(char_nbr));
	ft_strlcat(to_return, str + flag->length_flag + 2,
		ft_strlen(str)+ ft_strlen(char_nbr) + 1);
	free(str);
	free(char_nbr);
	return (to_return);
}
