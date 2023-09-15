#include "Convert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2 || std::string(av[1]).length() < 1)
	{
		std::cerr << "Usage: " << av[0] << " <input>" << std::endl;
		return (1);
	}
    std::string input(av[1]);
    Convert run(input);
	run.print();
	return (0);
}