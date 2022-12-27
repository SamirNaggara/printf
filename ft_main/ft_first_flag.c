/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:58:30 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/26 17:16:26 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

t_flag_list	*first_flag(t_flag_list **flag_list, const char *str, size_t *size)
{
	t_flag_list	*browse;
	char		*ptr;
	size_t		i;

	i = 0;
	ptr = NULL;
	while (i < *size)
	{
		if (str[i] == '%')
		{
			ptr = (char *)str + i;
			break ;
		}
		i++;
	}

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
