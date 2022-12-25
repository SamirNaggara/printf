/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstflag_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:37:20 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 18:38:18 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../printf.h"

void	ft_lstflag_clear(t_flag_list **lst, void (*del)(void *))
{
	t_flag_list	*browse;
	t_flag_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	browse = *lst;
	while (browse)
	{
		tmp = browse;
		browse = browse->next;
		free(tmp);
	}
	*lst = NULL;
}
