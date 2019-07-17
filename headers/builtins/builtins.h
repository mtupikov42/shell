#ifndef BUILTINS_H
# define BUILTINS_H

static char				*g_builtins_names[] = {
	"echo",
	"cd",
	"setenv",
	"unsetenv",
	"env",
	"exit",
	"help"
};

int						bt_echo(char **args);
int						bt_cd(char **args);
int						bt_setenv(char **args);
int						bt_unsetenv(char **args);
int						bt_env(char **args);
int						bt_exit(char **args);
int						bt_help(char **args);

typedef int				(*t_builtin_func) (char **);

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