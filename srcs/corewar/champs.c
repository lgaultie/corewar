/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:46:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/04 23:54:50 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Add an existing champion to an existing champion list
**			** This is a circular list **
*/

void		champs_add(t_vm *vm, t_champs *champs, t_champ *champ)
{
	if (!vm || !champs || !champ)
		ft_error(vm, &free_all, "ERROR: champs_add args\n");
	if (!champs->first)
	{
		champs->first = champ;
		champs->current = champ;
		champs->last = champ;
	}
	else
	{
		champs->last->next = champ;
		champs->last = champ;
	}
	champs->last->next = champs->first;
	++champs->size;
}

void		champs_free(t_champs **champs_ptr)
{
	t_champs	*champs;

	if (!champs_ptr || !*champs_ptr)
		return ;
	champs = *champs_ptr;
	champs->last->next = NULL;
	while (champs->first)
	{
		champs->current = champs->first->next;
		champ_free(&champs->first);
		champs->first = champs->current;
		--champs->size;
	}
	ft_memdel((void **)champs_ptr);
}
