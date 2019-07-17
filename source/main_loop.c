#include "main_loop.h"
#include "utils/shell_utils.h"
#include "libft.h"
#include <unistd.h>

static void		print_prompt(void)
{
	ft_printf(PROMPT_USER /* TODO */);
	ft_printf(PROMPT_CURSOR /* TODO */);
}

static char		**read_input(void)
{
	char	*line;
	char	**commands;

	if (get_next_line(STDIN_FILENO, &line))
	{
		if (ft_strlen(line) == 0) {
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

	FOREVER {
		print_prompt();
		commands = read_input();
		i = -1;
		while (commands && commands[i])
		{

		}
		ft_splitdel(&commands);
	}
	return (SUCCESS);
}