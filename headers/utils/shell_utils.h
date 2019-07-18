#ifndef SHELL_UTILS_H
# define SHELL_UTILS_H

# include <stdbool.h>

# define FOREVER		while (true)

# define RED			"31"
# define GREEN			"32"
# define YELLOW			"33"
# define MAGENTA		"35"
# define RESET			"0"
# define COLOR_RED		"\x1b["RED"m"
# define COLOR_GREEN	"\x1b["GREEN"m"
# define COLOR_YELLOW	"\x1b["YELLOW"m"
# define COLOR_RESET	"\x1b["RESET"m"
# define COLOR_MAGENTA	"\x1b["MAGENTA"m"
# define COLOR_TEMPLATE	"\x1b[%sm"

# define PROMPT_USER	"["COLOR_YELLOW"%s@%s"COLOR_RESET"] "COLOR_MAGENTA"%s\n"
# define PROMPT_CURSOR	COLOR_RESETCOLOR_TEMPLATE"$> "COLOR_RESET

# define ERROR			-1
# define SUCCESS		0
# define NO_SUCH_ENV	1488
# define EXIT_REQUEST	76

#endif