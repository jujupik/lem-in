#include "lem_in.h"

t_path			create_path()
{
	t_path	result;

	result.road = malloc_list(500);
	result.count = 0;
	return (result);
}

t_path			*malloc_path()
{
	t_path	*result;

	result = (t_path *)malloc(sizeof(t_path));
	if (result == NULL)
		error_exit(111, "Can't malloc a t_path");
	*result = create_path();
	return (result);
}

void			destroy_path(t_path to_destroy)
{
	free_list(to_destroy.road, NULL);
}

void			free_path(t_path *to_free)
{
	destroy_path(*to_free);
	free(to_free);
}

void			add_room_to_path(t_path *path, t_room *room)
{
	list_push_back(path->road, room);
}

void			print_path(t_path *tmp)
{
	size_t	i;
	t_room	*tmp2;

	i = 0;
	ft_printf("Path size : %u  ---  Nb ants : %u\n",
												tmp->road->size, tmp->count);
	if (tmp == NULL || tmp->road == NULL || tmp->road->size == 0)
		ft_printf("No path");
	else
	{
		while (i < tmp->road->size)
		{
			tmp2 = list_at(tmp->road, i);
			if (i != 0)
				ft_printf("-");
			ft_printf("%s", (tmp2 == NULL ? "[null]" : tmp2->name));
			i++;
		}
	}
	ft_printf("\n");
}
