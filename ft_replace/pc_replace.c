/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:31:17 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/27 13:26:53 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

char	*pc_replace(char *str, t_flag_list *flag, va_list *args, size_t *size)
{
	char	*to_return;

	(void)args;
	to_return = replace_flag_by_str(str, flag, "%", size);
	return (to_return);
}
