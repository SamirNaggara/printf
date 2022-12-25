/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:59:53 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 19:43:11 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int	ft_printf(const char *str, ...){
	t_flag_list	**flag_list;
	va_list		args;
	t_flag_list	*flag;
	char		*to_return;

	va_start(args, str);
	flag_list = create_flag_list();
	if (!flag_list)
		return (0);
	to_return = choose_flag(flag_list, str, &args);
	if (!to_return)
		return (0);
	ft_putstr(to_return);
	ft_lstflag_clear(flag_list, free);
	free(flag_list);
	free(to_return);
	va_end(args);
	return (1);
}

int	main(int ac, char **av){

	void	*ptr;
	int		nbr;

	//printf("%s\n", ft_itoa_hexa(140723940386924));
	nbr = 8;
	ptr = &nbr;
	//printf("Voila un pointeur, enfin je crois : %p\n", ptr);
	if (!ac)
		return (1);
	ft_printf("Test 1 : ok c'est la chaine simple\n\n");
	//printf("Test 1 : % ok c'est la chaine simple\n\n");
	ft_printf("Test 2 : La y'a un int : %d\n\n", -25);
	ft_printf("Test 3 : La y'a une chaine : %s\n\n", "La chaine");
	ft_printf("Test 4 : La y'a une chaine : %s et la le nombre\n\n", "La chaine");
	ft_printf("Test 4 : La y'a une chaine : %s et la le nombre\n\n", "La chaine");
	ft_printf("Test 5 : La y'a un seul char : %c\n\n", 'r');
	ft_printf("Test 6 : Voila le pointeur%papres\n\n", ptr);
	//printf("Test 6 : Voila le pointeur%papres\n", ptr);
	ft_printf("Test 7 : Voici le i qui affiche un nombre i: %i\n\n", 123);
	ft_printf("Test 8 : La y'a un int : %u\n\n", -3);
	//printf("Test 8 : La y'a un int : %u\n\n", -3);
	ft_printf("Test 9 : La y'a un nombre hexa : %x\n\n", 421);
	//printf("Test 9 : La y'a un nombre hexa : %x\n\n", 421);
	ft_printf("Test 10 : La y'a un nombre hexa maj: %X\n\n", 421);
	ft_printf("Test 11 : La y'a un pourcentage : %%aa\n\n");



	//printf("%d\n", ft_atoi(av[1]));
	//printf("voila");
	return (0);
}
