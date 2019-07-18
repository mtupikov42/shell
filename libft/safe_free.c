#include "includes/libft.h"

void safe_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
	}
}