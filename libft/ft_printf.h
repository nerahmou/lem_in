/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 15:54:47 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 18:13:29 by edbernie    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct	s_print
{

	int			a;
	int			nb;
	int			flagplus;
	int			flagneg;
	int			flagzero;
	int			flagspace;
	int			flagdiece;
	int			taille;
	int			precision;
	int			h;
	int			l;
	int			j;
	int			z;
	char		*format;
	char		*tmp;
	char		*str;
	intmax_t	i;
	size_t		sz;
}				t_print;

int				ft_flag_suite(t_print *lst);
void			ft_execption(t_print *lst);
int				ft_strwlen(wchar_t *str);
int				ft_putwstr(wchar_t *str);
int				ft_putnwstr(wchar_t *str, int a);
int				ft_putwlen(wchar_t c);
int				ft_strnwlen(wchar_t *str, int a);
void			ft_initialize(t_print *lst);
char			*ft_itoa_base(uintmax_t value, int base);
void			ft_strdel(char **as);
void			ft_putstr(char const *s);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			*ft_itoa(intmax_t n);
char			*ft_uitoa(uintmax_t n);
int				ft_atoi(const char *str);
int				ft_putwchar(wchar_t c);
int				ft_putchar(char c);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, int n);
int				ft_flag(t_print *lst);
int				ft_length(t_print *lst);
int				ft_precision(t_print *lst);
void			ft_conversion(t_print *lst, va_list ap);
void			ft_int(t_print *lst, va_list ap);
void			ft_flagh_d(t_print *lst, va_list ap);
void			ft_flagh(t_print *lst, va_list ap);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_x(t_print *lst, va_list ap);
void			ft_affichage_to_x(t_print *lst);
void			ft_o(t_print *lst, va_list ap);
int				ft_toupper(int c);
void			ft_modifieandwrite(t_print *lst);
void			ft_u(t_print *lst, va_list ap);
void			ft_string(t_print *lst, va_list ap);
void			ft_affichage_to_string(t_print *lst);
char			*ft_strchr(const char *s, int c);
void			ft_pourcent(t_print *lst, va_list ap);
void			ft_precision_to_string(t_print *lst);
void			ft_c(t_print *lst, va_list ap);
void			ft_justtaille(t_print *lst);
void			ft_precision_unicode(t_print *lst, wchar_t *str);
void			ft_straddcar(t_print *lst, int car, int len);
void			ft_check_suite(t_print *lst);
void			ft_check(t_print *lst, va_list ap);
void			ft_aff_suite(t_print *lst);
void			ft_affichage(t_print *lst);
int				ft_printf(const char *format, ...);
#endif
