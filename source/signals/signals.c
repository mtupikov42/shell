/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:27:26 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/20 16:50:35 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals/signals.h"
#include "main_loop.h"
#include "shell.h"
#include <signal.h>
#include <stddef.h>

static void	ignore_signal(int s)
{
	s = 0;
}

void		setup_signals(void)
{
	const struct sigaction ignore_act = {
		.sa_handler = &ignore_signal,
		.sa_flags = 0,
		.sa_mask = 0
	};

	sigaction(SIGINT, &ignore_act, NULL);
}
