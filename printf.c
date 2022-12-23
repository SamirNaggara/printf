/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:59:53 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/23 19:13:36 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

t_list*	create_struct_symbol();

int ft_printf(const char *, ...){
	t_list	*symbol;
	va_list args;
	const char *first_arg;

	va_start(args, 0);
	first_arg = va_arg(args, const char *);
	symbol = create_struct_symbol();
	printf("%s\n", first_arg);

	va_end(args);
	return (1);
}


t_list*	create_struct_symbol()
{
	t_list	*symbol;
	
	symbol = ft_lstnew("%d");
	return (symbol);
}


int	main(int ac, char **av){
	if (!ac)
		return (1);
	printf("%d\n", ft_atoi(av[1]));
	return (0);
}