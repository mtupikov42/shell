/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:15:20 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/19 10:51:41 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_EXPANSION_H
# define VARIABLES_EXPANSION_H

char	*replace_home_variable(char *line);
void	expand_variables(char **line);

#endif