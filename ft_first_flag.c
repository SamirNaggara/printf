/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:58:30 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 18:59:09 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

t_flag_list	*first_flag(t_flag_list **flag_list, const char *str)
{
	t_flag_list *browse;
	char	*ptr;

	ptr = ft_strchr(str, '%');

	if (!ptr)
		return (NULL);
	browse = *flag_list;
	while (browse)
	{
		if (browse->type == ptr[1])
		{
			browse->length_flag = ptr - str;
			return (browse);
		}
		browse = browse->next;
	}
	return (NULL);
}
