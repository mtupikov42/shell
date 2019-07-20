/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:48:10 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 20:20:35 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_UTILS_H
# define EXECUTION_UTILS_H

# include <stdbool.h>

bool	command_contain_only_whitespaces(char *cmd);
char	**trim_arguments(char **args);
int		try_execute_directly(const char **args);

#endif
