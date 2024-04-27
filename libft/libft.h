/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:02:07 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/27 15:39:27 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* DEFINITIONS */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

/* INCLUDES */

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/wait.h>

/* STRUCTURES */

	/* LIBFT STRUCT */

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

	/* GET_NEXT_LINE STRUCT */

typedef struct s_gnl {
	char			*content;
	struct s_gnl	*next;
}	t_gnl;

/* FUNCTIONS */

	/* LIBFT SOURCES */

int		ft_isalnum(char c);
int		count_numbers(int n);
int		ft_isalpha(char c);
int		ft_isascii(int c);
int		ft_isdigit(char c);
int		ft_isprint(char c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_lstsize(t_list *lst);
int		ft_toupper(int c);
void	ft_bzero(void *m, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *m, int c, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_calloc(size_t num, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char *s, char *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_itoa(int n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);

	/* PRINTF WITHOUT BONUS */

int		ft_printf(const char *form, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_print_digit_lower(long n, int base);
int		ft_print_digit_upper(long n, int base);
int		ft_putnbr(int n);
int		ft_putadd(void *add);
int		ft_put_unsigned(unsigned int n);

	/* GET_NEXT_LINE WITH BONUS */

t_gnl	*gnl_lstlast(t_gnl *stash);
char	*get_next_line(int fd);
int		search_for_newline(t_gnl *list);
void	put_line(t_gnl *list, char **line);
void	clean_list(t_gnl **list);
void	create_list(t_gnl **list, int fd);
void	malloc_of_line(char **line, t_gnl *list);
void	free_list(t_gnl *list);

	/* CUSTOM */

long	ft_strtol(const char *str);
int		ft_ishex(char c);
void	ft_free_array(char **str);
void	ft_free_list(t_list *head);
int		ft_strcmp(char *s1, char *s2);

#endif
