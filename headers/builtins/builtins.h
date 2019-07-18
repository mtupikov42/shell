/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:31 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:12:19 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

static int				g_builtins_size = 7;
static char				*g_builtins_names[] = {
	"echo",
	"cd",
	"setenv",
	"unsetenv",
	"env",
	"exit",
	"help"
};

int						bt_echo(const char **args);
int						bt_cd(const char **args);
int						bt_setenv(const char **args);
int						bt_unsetenv(const char **args);
int						bt_env(const char **args);
int						bt_exit(const char **args);
int						bt_help(const char **args);

typedef int				(*t_builtin_func) (const char **);

static t_builtin_func	g_builtin_funcs[] = {
	&bt_echo,
	&bt_cd,
	&bt_setenv,
	&bt_unsetenv,
	&bt_env,
	&bt_exit,
	&bt_help
};

#endif
