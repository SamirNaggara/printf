/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_long.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:46:32 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/26 00:35:16 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

unsigned long	ft_get_len_lg(unsigned long n);

char			*ft_initialise_result_lg(size_t len);

char	*ft_itoa_long(unsigned long n)
{
	char			*result;
	unsigned long	number;
	size_t			i;
	size_t			len;

	i = 0;
	number = (unsigned long)n;
	len = (size_t)ft_get_len_lg(number);
	result = ft_initialise_result_lg(len);
	if (!result)
		return (NULL);
	while (len > 0)
	{
		result[i] = number / (ft_power(10, len - 1)) + '0';
		number = number % (ft_power(10, len - 1));
		i++;
		len--;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_initialise_result_lg(size_t len)
{
	char	*result;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_memset(result, 0, len + 1);
	return (result);
}

unsigned long	ft_get_len_lg(unsigned long n)
{
	int		i;
	long	n_copy;

	n_copy = (long)n;
	if (n_copy < 0)
	n_copy = -n_copy;
	i = 1;
	while (n_copy >= 10)
	{
		n_copy = n_copy / 10;
		i++;
	}
	return ((size_t)i);
}
/*
int main(int ac, char **av)
{
    char *result;

    result = ft_itoa(ft_atoi(av[1]));
    if (ac)
    {
        printf("ft itoi : %s\n", result);
        free(result);
    }
}
*/
