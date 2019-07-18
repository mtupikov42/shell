#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include "ft_printf.h"

# define BUFF_SIZE 1
# define EOL '\n'

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vector
{
	void			**array;
	size_t 			capacity;
	size_t 			size;
}					t_vector;

int					ft_strsplit_count(char **split);
int					ft_split_has_dupl(char **split);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t num);
long				ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strisdigit(char *s);
int					ft_count_words(const char *s, char c);
int					ft_memcmp(const void *restrict memptr1,
					const void *restrict memptr2, size_t num);
int					ft_splitdel(char ***split);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					get_next_line(const int fd, char **line);
double				ft_atof(char *num);
char				*ft_strdup(const char *str);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strcpy(char *dest, const char *from);
char				*ft_strcat(char *dest, const char *from);
char				*ft_strncat(char *dest, char *from, size_t num);
char				*ft_strncpy(char *dest, const char *from, size_t num);
char				*ft_strchr(const char *str, int symbol);
char				*ft_strrchr(const char *str, int symbol);
char				*ft_strnstr(const char *str1, const char *str2, size_t num);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strs_join_c(char *str1, char *str2, char c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strjoinch(char const *s1, char c);
char				*ft_strrealloc(char *old_buf, size_t size);
char				**ft_splitrealloc(char **old, int size);
char				**ft_remove_from_split(char **split, char *var);
void				ft_append_to_split(char **split, char *str);
void				*ft_memcpy(void *restrict destptr,
					const void *restrict srcptr, size_t num);
void				*ft_memccpy(void *restrict destptr,
					const void *restrict srcptr, int c, size_t n);
void				*ft_memset(void *restrict memptr, int val, size_t num);
void				*ft_memmove(void *restrict destptr,
					const void *restrict strptr, size_t num);
void				*ft_memchr(const void *restrict memptr,
					int val, size_t num);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *restrict memptr, size_t len);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
void				ft_swapint(int *a, int *b);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newl);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstrev(t_list **alst);
void				ft_doubleptrdel(void ***ptr);
void				print_split(char **split);
void				safe_free(void *ptr);
size_t				ft_strnlen(const char *str, size_t max);
size_t				ft_strlen(const char *str);
size_t				ft_lstcount(t_list *lst);
size_t				ft_strlcat(char *dest, const char *from, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				vector_push_back(t_vector *vector, void *data);
void				*vector_get_at(t_vector *vector, size_t index);

#endif
