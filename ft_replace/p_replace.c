/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:31:39 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/26 23:42:13 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

char	*p_replace(char *str, t_flag_list *flag, va_list *args, size_t *size)
{
	char	*to_return;
	ulong	nbr;
	char	*char_nbr;
	char	*char_to_display;

	nbr = (ulong)va_arg(*args, void *);
	if (!nbr)
	{
		return (replace_flag_by_str(str, flag, "(nil)", size));
	}
	char_nbr = ft_itoa_hexa_ulong(nbr);
	if (!char_nbr)
		return (NULL);
	char_to_display = malloc(sizeof(char) * (ft_strlen(char_nbr) + 3));
	if (!char_to_display)
	{
		free(char_nbr);
		return (NULL);		
	}
	ft_strlcpy(char_to_display, "0x", 3);
	ft_strlcat(char_to_display, char_nbr, ft_strlen(char_nbr) + 3);
	to_return = replace_flag_by_str(str, flag, char_to_display, size);
	if (!to_return)
	{
		free(char_nbr);
		free(char_to_display);
	}
	free(char_nbr);
	free(char_to_display);
	return (to_return);
}
