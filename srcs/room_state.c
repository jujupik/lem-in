#include "lem_in.h"

char *state_str(t_room_state state)
{
	if (state == normal)
		return ("normal");
	if (state == start)
		return ("start");
	if (state == end)
		return ("end");
	return ("error");
}
