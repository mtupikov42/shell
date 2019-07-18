/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:54:35 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:12:33 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_UTILS_H
# define ENVIRONMENT_UTILS_H

# include <stdbool.h>

bool	variable_is_valid(const char *name);
char	*replace_environment_variables(char *line);

#endif
