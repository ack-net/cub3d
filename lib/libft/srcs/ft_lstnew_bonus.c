/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:20:42 by antheven          #+#    #+#             */
/*   Updated: 2019/10/11 13:25:27 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	if (!(lst = ft_calloc(1, sizeof(lst))))
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}
