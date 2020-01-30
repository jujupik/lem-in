#include "lem_in.h"


void print_solution(int *value, int nb_value)
{
	ft_printf("Combinaison : ");
	if (nb_value == 0)
		ft_printf("No path");
	for (int z = 0; z < nb_value; z++)
	{
		if (z != 0)
			ft_printf(" - ");
		ft_printf("%d", value[z]);
	}
	ft_printf("\n");
}

static int *create_value_list(int nb_value)
{
	int *value;
	int j;

	value = ft_int_str_new(nb_value);
	j = 0;
	while (j < nb_value)
	{
		value[j] = j;
		j++;
	}
	return (value);
}

void generate_solution_value(t_intstr_list *list, int len, int nb_value)
{
	static int *value = NULL;
	int i;

	if (value == NULL)
		value = create_value_list(nb_value);
	if (len == nb_value)
		t_intstr_list_add(list, create_int_array(value, nb_value));
	else
	{
		i = len;
		while (i < nb_value)
		{
			ft_swap_int(&(value[len]), &(value[i]));
			generate_solution_value(list, len + 1, nb_value);
			ft_swap_int(&(value[len]), &(value[i]));
			i++;
		}
	}
}
