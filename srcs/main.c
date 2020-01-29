#include "lem_in.h"

int main()
{
	t_map map;

	map = create_map();
	parse_map(&map);
	print_map(&map);
	return (0);
}
