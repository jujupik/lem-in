#ifndef LEM_IN_H
#define LEM_IN_H

#include "lem_in_includes.h"

#include "lem_in_room.h"
#include "lem_in_map.h"

BOOL line_is_commentary(char *line);
BOOL line_is_command(char *line);
BOOL line_is_piece(char *line);
BOOL line_is_link(char *line);
BOOL is_name_valid(t_room_list *list, char *name);

#endif
