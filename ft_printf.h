/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:45:36 by snaggara          #+#    #+#             */
/*   Updated: 2022/12/25 22:44:43 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct s_flag_list
{
	char				type;
	size_t				length_flag;
	char				*(*func_replace)(char*, struct s_flag_list*, va_list*);
	struct s_flag_list	*next;
}t_flag_list;

int	ft_printf(const char *str, ...);
t_flag_list	**create_flag_list(void);
t_flag_list	*ft_lst_flag_new(int type, char *(*func_replace)(char*,
					struct s_flag_list*, va_list*));
t_flag_list	*first_flag(t_flag_list **flag_list, const char *str);
char		*ft_modify_str(t_flag_list **flag_list, const char *str,
				va_list *args);
void		ft_lst_flag_add_back(t_flag_list **lst, t_flag_list *new);
void		ft_lstflag_clear(t_flag_list **lst, void (*del)(void *));
char		*s_replace(char *str, t_flag_list *flag, va_list *args);
char		*d_replace(char *str, t_flag_list *flag, va_list *args);
char		*i_replace(char *str, t_flag_list *flag, va_list *args);
char		*c_replace(char *str, t_flag_list *flag, va_list *args);
char		*p_replace(char *str, t_flag_list *flag, va_list *args);
char		*u_replace(char *str, t_flag_list *flag, va_list *args);
char		*x_replace(char *str, t_flag_list *flag, va_list *args);
char		*xup_replace(char *str, t_flag_list *flag, va_list *args);
char		*pc_replace(char *str, t_flag_list *flag, va_list *args);
void		ft_putstr(char *str);
char		*ft_itoa_hexa(long n);
void		del(void *content);
char		*ft_itoa_long(unsigned long n);
void		ft_strtoupper(char *str);

#endif