/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:02:35 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:10:42 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_loop.h"
#include "utils/shell_utils.h"
#include "libft.h"
#include "execution/execution.h"
#include "shell.h"
#include <unistd.h>

static void		print_prompt(void)
{
	char *cursor_color;

	if (g_shell.last_status == SUCCESS)
		cursor_color = GREEN;
	else
		cursor_color = RED;
	ft_printf(PROMPT_USER, "1", "2", "3");
	ft_printf(PROMPT_CURSOR, cursor_color);
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
			args = ft_strsplit(commands[i], ' ');
			g_shell.last_status = execute_command((const char **)args);
			ft_splitdel(&args);
			++i;
		}
		ft_splitdel(&commands);
	}
	return (SUCCESS);
}
