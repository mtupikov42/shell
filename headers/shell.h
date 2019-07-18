#ifndef SHELL_H
# define SHELL_H

#include <sys/types.h>

typedef struct	s_shell
{
	char		**env;
	pid_t		process;
}				t_shell;

t_shell			g_shell;

#endif