/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:59:53 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/27 13:29:59 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_flag_list	**flag_list;
	va_list		args;
	char		*to_return;
	size_t			size[1];

	va_start(args, str);
	flag_list = create_flag_list();
	*size = ft_strlen(str);
	if (!flag_list)
		return (0);

	to_return = ft_modify_str(flag_list, str, &args, size);
	if (!to_return)
	{
		ft_lstflag_clear(flag_list, free);
		free(flag_list);
		return (0);
	}
	ft_putstr(to_return, size);
	ft_lstflag_clear(flag_list, free);
	free(flag_list);
	free(to_return);
	va_end(args);
	return ((int)*size);
}

int	main(){


	//ft_printf("bah%ca\nb", 0);
	//char	*ptr;
	//unsigned int i = 14748364955 ;
	//ulong j = -9223372036854775807;
	//j--;
	//int nb1 = ft_printf("a%sa\n", ptr);
	
	int nb1 = ft_printf(" %%%% \n");
	int nb2 = printf(" %%%% \n");

	printf("Mon printf: %d\nLe vrai printf :  %d\n", nb1, nb2);
	//printf(" %c ", '0');
	//printf("a%s", "");
	//printf("%s\n", ft_itoa_hexa(140723940386924));
	//nbr = 8;
	//ptr = &nbr;
	//printf("Voila un pointeur, enfin je crois : %p\n", ptr);
	//ft_printf("Test 1 : ok c'est la chaine simple\n\n");
	//printf("Test 1 : % ok c'est la chaine simple\n\n");
	// ft_printf("Test 2 : La y'a un int : %d\n\n", -25);
	// ft_printf("Test 3 : La y'a une chaine : %s\n\n", "La chaine");
	// ft_printf("Test 4 : La y'a une chaine : %s et la le nombre\n\n", "La chaine");
	// ft_printf("Test 4 : La y'a une chaine : %s et la le nombre\n\n", "La chaine");
	// ft_printf("Test 5 : La y'a un seul char : %c\n\n", 'r');
	// ft_printf("Test 6 : Voila le pointeur%papres\n\n", ptr);
	//printf("Test 6 : Voila le pointeur%papres\n", ptr);
	//ft_printf("Test 7 : Voici le i qui affiche un nombre i: %i\n\n", 123);
	//ft_printf("Test 8 : La y'a un int : %u\n\n", -3);
	//printf("Test 8 : La y'a un int : %u\n\n", -3);
	//ft_printf("Test 9 : La y'a un nombre hexa : %x\n\n", 421);
	//printf("Test 9 : La y'a un nombre hexa : %x\n\n", 421);
	//ft_printf("Test 10 : La y'a un nombre hexa maj: %X\n\n", 421);
	//ft_printf("Test 11 : La y'a un pourcentage : %%aa\n\n");
	//printf("%d\n", ft_atoi(av[1]));
	//printf("voila");
	return (0);
}
