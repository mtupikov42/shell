/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:52:10 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:16:40 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_UTILS_H
# define SHELL_UTILS_H

# include <stdbool.h>

# define RED					"31"
# define GREEN					"32"
# define YELLOW					"33"
# define MAGENTA				"35"
# define RESET					"0"
# define COLOR_RED				"\x1b["RED"m"
# define COLOR_GREEN			"\x1b["GREEN"m"
# define COLOR_YELLOW			"\x1b["YELLOW"m"
# define COLOR_RESET			"\x1b["RESET"m"
# define COLOR_MAGENTA			"\x1b["MAGENTA"m"
# define COLOR_TEMPLATE			"\x1b[%sm"

# define PROMPT_PLACE			"["COLOR_YELLOW"%s@%s"COLOR_RESET"] "
# define PROMPT_USER			PROMPT_PLACE COLOR_MAGENTA"%s\n"
# define PROMPT_CURSOR			COLOR_RESET COLOR_TEMPLATE"$"COLOR_RESET"> "

# define ERROR					-1
# define SUCCESS				0
# define NO_SUCH_ENV			1000
# define NO_SUCH_BINARY			1001
# define SETENV_SYNTAX_ERROR	1002
# define UNSETENV_ARGS_ERROR	1003

#endif
