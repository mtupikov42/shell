/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:02:35 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/19 14:23:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_loop.h"
#include "utils/shell_utils.h"
#include "utils/errors.h"
#include "libft.h"
#include "execution/execution.h"
#include "shell.h"
#include "environment/variables_expansion.h"
#include "environment/environment.h"
#include <unistd.h>

static void		print_prompt_cursor(void)
{
	char	*cursor_color;

	if (g_shell.last_status == SUCCESS)
		cursor_color = GREEN;
	else
		cursor_color = RED;
	ft_printf(PROMPT_CURSOR, cursor_color);
}

static void		print_prompt(void)
{
	char	*tmp;
	char	*user;
	char	*home;
	char	*pwd;
	char	hostname[PWD_BUFF_SIZE];

	user = get_environment(USER_VAR);
	home = get_environment(HOME_VAR);
	pwd = get_environment(PWD_VAR);
	if (home && pwd && ft_strstr(pwd, home) != 0)
	{
		tmp = ft_strsub(pwd, ft_strlen(home) - 1,
			ft_strlen(pwd) - ft_strlen(home) + 1);
		free(pwd);
		pwd = tmp;
		pwd[0] = HOME_SYM;
	}
	gethostname(hostname, PWD_BUFF_SIZE);
	ft_printf(PROMPT_USER, user, hostname, pwd);
	print_prompt_cursor();
	safe_free(pwd);
	safe_free(user);
	safe_free(home);
}

static char		**read_input(void)
{
	char	*line;
	char	**commands;

	commands = NULL;
	if (get_next_line(STDIN_FILENO, &line))
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			return (NULL);
		}
		commands = ft_strsplit(line, ';');
		free(line);
	}
	return (commands);
}

int				main_loop(void)
{
	int		i;
	char	**commands;
	char	**args;

	while (g_shell.is_running)
	{
		print_prompt();
		commands = read_input();
		i = 0;
		while (commands && commands[i])
		{
			expand_variables(&commands[i]);
			args = ft_strsplit(commands[i], ' ');
			g_shell.last_status = execute_command((const char **)args);
			if (g_shell.last_status != SUCCESS)
				print_error(args[0], g_shell.last_status);
			ft_splitdel(&args);
			++i;
		}
		ft_splitdel(&commands);
	}
	return (SUCCESS);
}
