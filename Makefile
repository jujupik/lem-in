NAME=		lem-in

##
##		RESSOURCES
##

##List every folder where he will find header
INC_DIR = 	$(shell find includes -type d)
INC_DIR +=	$(shell find jlib/includes -type d)

##List every folder where he will find source file
SRC_DIR = 	$(shell find srcs -type d)

LIB_DIR =	jlib/

##Folder where he will store the .o
OBJ_DIR	=	obj

##Add to the vpath the folder find in SRC_DIR
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

##List every .c found inside SRC_DIR
SRC = 		acces_path.c \
			acces_room.c \
			basics.c \
			calc_distance.c \
			handle_paths.c \
			lem_in.c \
			main.c \
			main_utils.c \
			parse_map.c \
			parse_map_utils.c \
			parse_path.c \
			prepare_path.c \
			print_map.c \
			print_room.c \
			room_state.c \
			solver.c \
			t_ant.c \
			t_link.c \
			t_map.c \
			t_path.c \
			t_room.c \
			t_room_flow.c \
			tmp_free_funct.c

##List every lib to link
LIB = jlib

##Transform and place every .o from SRC
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

##
##		COMPILER FLAGS
##

##Basics flags
CFLAGS=		-g -fsanitize=address

##Create the flags to includes every .h needed by this program
IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir))

##Create the flags to link every libraries needed by this program (-L and -l)
LFLAGS =	$(foreach dir, $(LIB_DIR), -L $(dir)) $(foreach lib, $(LIB), -l $(lib))

##Define the compiler to use
CC=			gcc


all:
				make $(NAME)

install:
				$(foreach dir, $(LIB_DIR), make -C $(dir))

show:
				@echo "SRC :\n$(SRC)"
				@echo "OBJ :\n$(OBJ)"
				@echo "CFLAGS :\n$(CFLAGS)"
				@echo "IFLAGS :\n$(IFLAGS)"
				@echo "LFLAGS :\n$(LFLAGS)"

$(NAME):		$(OBJ) $(INC_DIR) Makefile
				@echo "Compiling $(NAME) ...\c"
				@$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
				@echo " DONE"

$(OBJ_DIR)/%.o : %.c
				@mkdir -p $(OBJ_DIR)
				@echo "Compiling $< ...\c"
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo " DONE"

clean:
				@rm -rf $(OBJ_DIR)
				@echo "clean"

fclean:			clean
				@rm -f $(NAME)
				@echo "fclean"

re:				fclean all

.PHONY: all clean fclean re
