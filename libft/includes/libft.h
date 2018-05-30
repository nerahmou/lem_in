/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: edbernie <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:08:49 by edbernie     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 14:52:50 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <wchar.h>

# define BUFF_SIZE 8

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	int				fd;
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

typedef struct		s_print
{

	int				a;
	int				nb;
	int				flagplus;
	int				flagneg;
	int				flagzero;
	int				flagspace;
	int				flagdiece;
	int				taille;
	int				precision;
	int				h;
	int				l;
	int				j;
	int				z;
	char			*format;
	char			*tmp;
	char			*str;
	intmax_t		i;
	size_t			sz;
}					t_print;

int					get_next_line(const int fd, char **line);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
int					ft_putchar(char c);
char				*ft_itoa(intmax_t n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char*));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr
(const char *haystack, const char *needle, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncpy(char *dst, char *src, size_t len);
char				*ft_strcpy(char *dst, char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_flag_suite(t_print *lst);
void				ft_execption(t_print *lst);
int					ft_strwlen(wchar_t *str);
int					ft_putwstr(wchar_t *str);
int					ft_putnwstr(wchar_t *str, int a);
int					ft_putwlen(wchar_t c);
int					ft_strnwlen(wchar_t *str, int a);
void				ft_initialize(t_print *lst);
char				*ft_itoa_base(uintmax_t value, int base);
char				*ft_uitoa(uintmax_t n);
int					ft_putwchar(wchar_t c);
char				*ft_strndup(const char *s1, int n);
int					ft_flag(t_print *lst);
int					ft_length(t_print *lst);
int					ft_precision(t_print *lst);
void				ft_conversion(t_print *lst, va_list ap);
void				ft_int(t_print *lst, va_list ap);
void				ft_flagh_d(t_print *lst, va_list ap);
void				ft_flagh(t_print *lst, va_list ap);
void				ft_x(t_print *lst, va_list ap);
void				ft_affichage_to_x(t_print *lst);
void				ft_o(t_print *lst, va_list ap);
void				ft_modifieandwrite(t_print *lst);
void				ft_u(t_print *lst, va_list ap);
void				ft_string(t_print *lst, va_list ap);
void				ft_affichage_to_string(t_print *lst);
void				ft_pourcent(t_print *lst, va_list ap);
void				ft_precision_to_string(t_print *lst);
void				ft_c(t_print *lst, va_list ap);
void				ft_justtaille(t_print *lst);
void				ft_precision_unicode(t_print *lst, wchar_t *str);
void				ft_straddcar(t_print *lst, int car, int len);
void				ft_check_suite(t_print *lst);
void				ft_check(t_print *lst, va_list ap);
void				ft_aff_suite(t_print *lst);
void				ft_affichage(t_print *lst);
int					ft_printf(const char *format, ...);

int					ft_tablength(char **tab);
int					ft_strchr_occur(char *s, int c);
size_t				ft_char_pos(char *str, char c);
#endif
