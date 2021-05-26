/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:17:07 by antheven          #+#    #+#             */
/*   Updated: 2019/10/14 11:14:18 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"

int		ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	if (!lst)
		return (0);
	while (lst && ++len)
		lst = lst->next;
	return (len);
}
