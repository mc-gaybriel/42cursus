/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnickel <gnickel@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:27:14 by gnickel           #+#    #+#             */
/*   Updated: 2023/12/04 22:31:49 by gnickel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ctr;
	t_list	*current;

	ctr = 0;
	current = lst;
	while (current != NULL)
	{
		ctr++;
		current = current->next;
	}
	return (ctr);
}
