/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:27:26 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/20 20:38:23 by mtupikov         ###   ########.fr       */
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
	static struct sigaction	ignore_act = {{&ignore_signal}, 0, 0};

	sigaction(SIGINT, &ignore_act, NULL);
}
