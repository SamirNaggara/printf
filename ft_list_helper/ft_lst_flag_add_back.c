/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_flag_add_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:37:00 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 18:38:06 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../printf.h"

void	ft_lst_flag_add_back(t_flag_list **lst, t_flag_list *new)
{
	t_flag_list	*browse;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	browse = *lst;
	while (browse->next)
		browse = browse->next;
	browse->next = new;
}
