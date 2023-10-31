/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:59:58 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/21 17:29:00 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t elementCount, size_t elementSize);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *memoryBlock, int searchedChar,
					size_t size);
int				ft_memcmp(const void *pointer1, const void *pointer2,
					size_t size);
void			*ft_memcpy(void *destination, const void *source, size_t size);
void			*ft_memmove(void *destination, const void *source, size_t size);
void			*ft_memset(void *pointer, int value, size_t count);
char			*ft_strchr( const char *string, int searchedChar);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);
char			*ft_strtrim(char *s1, char *set);
unsigned int	ft_strlcpy(char *dest, const char *src,
					unsigned int size);
int				ft_strlen(char *str);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
char			*ft_strnstr(char *big, char *little, int len);
char			*ft_strrchr(char *string, int searchedChar);
char			*ft_substr(char *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			**ft_split(const char *str, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(int content);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(int));
void			ft_lstiter(t_list *lst, void (*f)(int));
void			ft_lstclear(t_list **lst);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strrejoin(int size, char **strs, char *sep, int start);
char			*ft_strcat(char *dest, char *src);
char			*ft_realloc(char *str, char c);
int				ft_power2(int n);

#endif