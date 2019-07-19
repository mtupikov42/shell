/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:02:40 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/19 14:39:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_loop.h"
#include "shell.h"
#include "environment/environment.h"
#include "utils/shell_utils.h"
#include "signals/signals.h"

int		main(int argc, char **argv, char **env)
{
	extern char	**environ;

	(void)argc;
	(void)argv;
	g_shell.env = copy_environment(env, environ);
	g_shell.is_running = true;
	g_shell.last_status = SUCCESS;
	setup_signals();
	return (main_loop());
}
