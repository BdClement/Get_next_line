/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:50:15 by clbernar          #+#    #+#             */
/*   Updated: 2022/12/13 15:47:20 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# if (BUFFER_SIZE < 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		contain_new_line(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	stock_in_list(t_list **lst, char *buf, int nb_read);
void	read_and_stock(int fd, t_list **lst);
void	create_line(t_list *lst, char **str);
void	get_line(t_list *lst, char	**str);
size_t	ft_strlen(const char *s);
void	clean_lst(t_list **lst);
void	free_lst(t_list **lst);

#endif
