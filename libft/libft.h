/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agpereir <agpereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:04:46 by agpereir          #+#    #+#             */
/*   Updated: 2024/02/24 07:51:38 by agpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
#include <stdarg.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

//------ GNL -----//
char		*get_keep(char *buffer);
char		*get_line_gnl(char *buffer);
char		*get_next_line(int fd);
//------ UTILS -----//
char		*ft_strjoin_gnl(char *s1, char *s2);
int			ft_strchr_gnl(char *str, char c);

//------ PRINTF -----//

int		ft_printf(const char *str, ...);
size_t	ft_strlen_pf(const char *str);

/*----------libftfunctions----------*/
void	ft_putchar(char c);
void	ft_putstr(char *s);

/*----------std----------*/
int		ft_print_chr(char c);
int		ft_print_str(char *str);
int		ft_print_nbr(int nbr);

/*----------unsig----------*/
int		ft_print_unsig(unsigned int nbr);

/*----------hex----------*/
int		ft_print_hex(unsigned int n, const char form);

/*----------pointer----------*/
int		ft_print_pointer(unsigned long ptr);

/*----------count----------*/
int		ft_hex_point_len(unsigned long nbr);

//------ INT -----//
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int arg);
int		ft_tolower(int arg);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);

//------ VOID -----//
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *str1, const void *str2, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//------ char -----//
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	print_char(unsigned int index, char *c);

//------ size -----//
size_t	ft_strlcpy(char *dest, char *src, unsigned int size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

// ---- Bonus Struct ---- //
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// ---- t_list ---- //
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// ---- void ---- //
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));

// ---- int ---- //
int		ft_lstsize(t_list *lst);

#endif
