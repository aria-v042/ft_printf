/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodrig2 <frodrig2@students.42porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 07:42:13 by frodrig2          #+#    #+#             */
/*   Updated: 2026/05/22 08:22:46 by frodrig2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstnext;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		lstnext = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lstnext;
	}
}
