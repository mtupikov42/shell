#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

int		set_environment(char *key, char *value);
int		unset_environment(char *name);
char	*get_environment(char *name);
char	**copy_environment(char **argenv, char **globalenv);

#endif