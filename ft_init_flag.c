/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:57:17 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 18:57:34 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

t_flag_list**	create_flag_list(void)
{
	t_flag_list	**flags;
	
	flags = (t_flag_list**)malloc(sizeof(t_flag_list*));
	if (!flags)
		return ((t_flag_list**)0);
	*flags = ft_lst_flag_new('c');
	ft_lst_flag_add_back(flags, ft_lst_flag_new('s'));
	ft_lst_flag_add_back(flags, ft_lst_flag_new('p'));
	ft_lst_flag_add_back(flags, ft_lst_flag_new('d'));
	ft_lst_flag_add_back(flags, ft_lst_flag_new('i'));
	ft_lst_flag_add_back(flags, ft_lst_flag_new('u'));
	ft_lst_flag_add_back(flags, ft_lst_flag_new('x'));
	ft_lst_flag_add_back(flags, ft_lst_flag_new('X'));
	ft_lst_flag_add_back(flags, ft_lst_flag_new('%'));
	if (!flags)
		return ((t_flag_list**)0);
	return (flags);
}
