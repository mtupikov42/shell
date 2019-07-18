#ifndef ENVIRONMENT_UTILS_H
# define ENVIRONMENT_UTILS_H

# include <stdbool.h>

bool	variable_is_valid(const char *name);
char	*replace_environment_variables(char *line);

#endif