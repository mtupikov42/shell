#include "main_loop.h"

int main(int argc, char **argv, char **env)
{
	extern char	**environ;

	return (main_loop());
}