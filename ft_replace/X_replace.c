/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:32:02 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/27 13:21:30 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

char	*xup_replace(char *str, t_flag_list *flag, va_list *args, size_t *size)
{
	char	*to_return;
	char	*number;

	number = ft_itoa_hexa(va_arg(*args, unsigned int));
	ft_strtoupper(number);
	if (!number)
		return (NULL);
	to_return = replace_flag_by_str(str, flag, number, size);
	free(number);
	return (to_return);
}
