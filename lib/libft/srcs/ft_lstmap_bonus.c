/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:47:09 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:16:11 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(void *))
{
	t_list	*mapped;

	mapped = 0;
	while (lst)
	{
		ft_lstadd_back(&mapped, (*f)(lst));
		lst = lst->next;
	}
	return (mapped);
}
