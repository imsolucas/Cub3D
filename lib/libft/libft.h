/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:38:20 by djin              #+#    #+#             */
/*   Updated: 2024/04/11 16:04:18 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*head;
	struct s_node	*tail;
}	t_node;

int			ft_atoi(const char *str);

int			ft_isalpha(int a);

void		ft_bzero(void *s, size_t n);

void		*ft_calloc(size_t num, size_t size);

int			ft_isalnum(int a);

int			ft_isascii(int asc);

int			ft_isdigit(int c);

int			ft_isprint(int arg);

char		*ft_itoa(int n);

void		*ft_memchr(void *ptr, int ch, size_t count);

int			ft_memcmp(const void *line, const void *rhs, size_t count);

void		*ft_memcpy(void *dest, const void *src, size_t count);

void		*ft_memmove(void *dest, const void *src, size_t count);

void		*ft_memset(void *dest, int ch, size_t count);

void		ft_putchar_fd(char c, int fd);

void		ft_putnbr_fd(int n, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putstr_fd(char *s, int fd);

char		**ft_split(char const *s, char c);

char		*ft_strchr(const char *str, int c);

int			ft_strcmp(const char *s1, const char *s2);

char		*ft_strdup(const char *s);

void		ft_striteri(char *s, void (*f)(unsigned int, char*));

char		*ft_strjoin(char const *s1, char const *s2);

size_t		ft_strlcat(char *dest, const char *src, size_t size);

int			ft_strlcpy(char *dest, const char *src, unsigned int size);

int		ft_strlen(const char *str);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int			ft_strncmp(const char *str1, const char *str2, unsigned int n);

char		*ft_strnstr(const char	*str, const char *to_find, size_t len);

char		*ft_strrchr(const char *str, int c);

char		*ft_strtrim(char const *s1, char const *set);

char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_tolower(int u);

int			ft_toupper(int c);

void		ft_lstadd_front(t_node **lst, t_node *new);

void		ft_lstadd_back(t_node **lst, t_node *new);

void		ft_lstclear(t_node **lst, void (*del)(void *));

void		ft_lstdelone(t_node *lst, void (*del)(void*));

void		ft_lstiter(t_node *lst, void (*f)(void *));

t_node		*ft_lstlast(t_node *lst);

t_node		*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *));

t_node		*ft_lstnew(void *content);

int			ft_lstsize(t_node *lst);
#endif