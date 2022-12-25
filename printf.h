/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:45:36 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 19:41:20 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
typedef struct s_flag_list
{
	char				type;
	size_t				length_flag;
	struct s_flag_list	*next;
	//char (*ma_fonction)(char, t_flag_list, void); Quand tu auras besoin d'une fonction, la tu pourras le faire !
}t_flag_list;
t_flag_list**	create_flag_list(void);

t_flag_list	*first_flag(t_flag_list **flag_list, const char *str);
char	*choose_flag(t_flag_list **flag_list, const char *str,va_list *args);
char	*s_replace(char *str, t_flag_list *flag, va_list *args);
char	*d_replace(char *str, t_flag_list *flag, va_list *args);
char	*i_replace(char *str, t_flag_list *flag, va_list *args);
char	*c_replace(char *str, t_flag_list *flag, va_list *args);
char	*p_replace(char *str, t_flag_list *flag, va_list *args);
char	*u_replace(char *str, t_flag_list *flag, va_list *args);
char	*x_replace(char *str, t_flag_list *flag, va_list *args);
char	*xup_replace(char *str, t_flag_list *flag, va_list *args);
void	ft_putstr(char *str);
char	*ft_itoa_hexa(long n);
t_flag_list	*ft_lst_flag_new(int type);
void	ft_lst_flag_add_back(t_flag_list **lst, t_flag_list *new);
void	ft_lstflag_clear(t_flag_list **lst, void (*del)(void *));
void	del(void *content);
char	*ft_itoa_long(unsigned long n);
void	ft_strtoupper(char *str);
# include <stdarg.h>

#endif