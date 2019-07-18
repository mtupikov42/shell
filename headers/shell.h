/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:52:36 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:12:45 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <sys/types.h>
# include <stdbool.h>

typedef struct	s_shell
{
	char		**env;
	pid_t		process;
	bool		is_running;
	int			last_status;

}				t_shell;

t_shell			g_shell;

#endif
