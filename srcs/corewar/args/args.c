/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:09:26 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 15:23:36 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Adds an existing argeter to an existing argeters list
*/

void		args_add(t_vm *vm, t_args *args, t_arg *arg)
{
	if (!vm || !args || !arg)
		ft_error(vm, &vm_free, "args_add args\n");
	if (!args->first)
	{
		args->first = arg;
		args->cur = arg;
		args->last = arg;
	}
	else
	{
		args->last->next = arg;
		args->last = arg;
	}
	args->by_id[args->size++] = arg;
}
