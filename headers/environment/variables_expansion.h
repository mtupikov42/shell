/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:15:20 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/20 20:26:06 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_EXPANSION_H
# define VARIABLES_EXPANSION_H

char	*replace_home_variable(const char *line);
void	expand_variables(char **line);

#endif
