#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*ft_strdup_sp(const char *s1);
void	*ft_memmove_sp(void *dst, const void *src, size_t len);
char	*ft_strjoin_sp(const char *s1, const char *s2);
int		ft_strchr_sp(char *buffer, char chr);
int		get_next_line(int fd, char **line);

#endif
