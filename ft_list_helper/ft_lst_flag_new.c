/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_flag_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:37:09 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 18:53:39 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../printf.h"

t_flag_list	*ft_lst_flag_new(int type)
{
	t_flag_list	*first;

	first = (t_flag_list *)malloc(sizeof(t_flag_list));
	if (!first)
		return ((t_flag_list *) NULL);
	(*first).type = (char)type;
	(*first).length_flag = 0;
	(*first).next = NULL;
	return (first);
}
