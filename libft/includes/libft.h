/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:14:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/03/18 17:21:18 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "ft_printf.h"
# include "get_next_line.h"

/*
**				PART ONE
*/

int				ft_ternint(int boolean, int a, int b);
char			ft_ternchar(int boolean, char a, char c);
unsigned long	ft_ternul(int boolean, unsigned long a, unsigned long b);

void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *str);

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			ft_bzero(void *s, size_t n);

size_t			ft_strlen(const char *s);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *str);

char			*ft_strchr(const char *s, int c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_isprint(int c);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
**				PARTIE TWO
*/

char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1, const char *set);
char			**ft_split(char *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
**				BONUS PART
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));

#endif
