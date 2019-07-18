/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:54:35 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:12:27 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

int		set_environment(char *key, char *value);
int		unset_environment(char *name);
char	*get_environment(char *name);
char	**copy_environment(char **argenv, char **globalenv);

#endif
