/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:52:10 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/19 15:54:51 by anonymous        ###   ########.fr       */
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

# define PROMPT_PLACE			COLOR_YELLOW"%s@%s"COLOR_RESET" "
# define PROMPT_USER			PROMPT_PLACE COLOR_MAGENTA"%s\n"
# define PROMPT_CURSOR			COLOR_RESET COLOR_TEMPLATE"$"COLOR_RESET"> "

# define ERROR					-1
# define SUCCESS				0
# define NO_SUCH_ENV			1000
# define NO_SUCH_BINARY			1001
# define SETENV_SYNTAX_ERROR	1002
# define UNSETENV_ARGS_ERROR	1003
# define TOO_MANY_ARGS			1004
# define PERMISIION_DENIED		1005
# define NO_OLD_PWD_VAR			1006
# define NO_SUCH_DIR			1007
# define NO_PATH_VAR			1008
# define NO_PWD_VAR				1009

# define PWD_BUFF_SIZE			1024

# define PWD_VAR				"PWD"
# define OLD_PWD_VAR			"OLDPWD"
# define USER_VAR				"USER"
# define PATH_VAR				"PATH"
# define HOME_VAR				"HOME"
# define HOME_SYM				'~'
# define CD_PREV_PATH			"-"

#endif
