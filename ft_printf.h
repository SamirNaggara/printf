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
# include <string.h>

typedef struct s_flag_list
{
	char				type;
	size_t				length_flag;
	char				*(*func_replace)(char*, struct s_flag_list*, va_list*,
							size_t*);
	struct s_flag_list	*next;
}t_flag_list;

int	ft_printf(const char *str, ...);
t_flag_list	**create_flag_list(void);
t_flag_list	*ft_lst_flag_new(int type, char *(*func_replace)(char*,
					struct s_flag_list*, va_list*, size_t*));
t_flag_list	*first_flag(t_flag_list **flag_list, const char *str, size_t *size);
char		*ft_modify_str(t_flag_list **flag_list, const char *str,
				va_list *args, size_t *size);
void		ft_lst_flag_add_back(t_flag_list **lst, t_flag_list *new);
void		ft_lstflag_clear(t_flag_list **lst, void (*del)(void *));
char	*replace_flag_by_str(char *str, t_flag_list *flag, char *arg_str, size_t *size);
char		*s_replace(char *str, t_flag_list *flag, va_list *args, size_t *size);
char		*d_replace(char *str, t_flag_list *flag, va_list *args, size_t *size);
char		*i_replace(char *str, t_flag_list *flag, va_list *args, size_t *size);
char		*c_replace(char *str, t_flag_list *flag, va_list *args, size_t *size);
char		*p_replace(char *str, t_flag_list *flag, va_list *args, size_t *size);
char		*u_replace(char *str, t_flag_list *flag, va_list *args, size_t *size);
char		*x_replace(char *str, t_flag_list *flag, va_list *args, size_t *size);
char		*xup_replace(char *str, t_flag_list *flag, va_list *args, size_t *size);
char		*pc_replace(char *str, t_flag_list *flag, va_list *args, size_t *size);
void		ft_putstr(char *str, size_t *size);
char		*ft_itoa_long(unsigned int n);
char		*ft_itoa_hexa(unsigned long n);
char		*ft_itoa_hexa_ulong(ulong n);
void		del(void *content);
void		ft_strtoupper(char *str);

#endif