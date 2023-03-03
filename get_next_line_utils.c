/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:49:58 by clbernar          #+#    #+#             */
/*   Updated: 2022/12/13 14:57:30 by clbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	t_list	*last;

	tmp = lst;
	last = lst;
	while (tmp != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	return (last);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief Teste si une liste contient ou non un retour a la ligne
 *
 * @param lst La liste a tester
 * @return 0 Si aucun retour a la ligne n'est trouve, 1 si c'est le cas
 */
int	contain_new_line(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->content[i] != '\0')
		{
			if (tmp->content[i] == '\n')
				return (1);
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

/**
 * @brief Malloc une line de la taille de la ligne lue
 * @param lst
 * @param str
 */
void	create_line(t_list *lst, char **str)
{
	int	line_len;
	int	i;

	line_len = 0;
	while (lst != NULL)
	{
		i = 0;
		while (lst->content[i] != '\0')
		{
			if (lst->content[i] == '\n')
			{
				line_len++;
				break ;
			}
			line_len++;
			i++;
		}
		lst = lst->next;
	}
	*str = malloc(line_len + 1);
	if (*str == NULL)
		return ;
}

void	free_lst(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	if (*lst == NULL)
		return ;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = next;
	}
}
