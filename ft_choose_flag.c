/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:17:19 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 19:55:01 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*choose_flag(t_flag_list **flag_list, const char *str, va_list *args)
{
	t_flag_list	*flag;
	char		*to_return;

	to_return = (char *)ft_strdup(str);
	while (flag = first_flag(flag_list, to_return))
	{
		if (flag->type == 'c')
			to_return = c_replace(to_return, flag, args);
		else if (flag->type == 's')
			to_return = s_replace(to_return, flag, args);
		else if (flag->type == 'p')
			to_return = p_replace(to_return, flag, args);
		else if (flag->type == 'd')
			to_return = d_replace(to_return, flag, args);
		else if (flag->type == 'i')
			to_return = i_replace(to_return, flag, args);
		else if (flag->type == 'u')
			to_return = u_replace(to_return, flag, args);
		else if (flag->type == 'x')
			to_return = xup_replace(to_return, flag, args);
		else if (flag->type == 'X')
			to_return = xup_replace(to_return, flag, args);
		else if (flag->type == '%')
			to_return = c_replace(to_return, flag, args);
	}
	return (to_return);
}


