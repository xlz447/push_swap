#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

NOC			=	\033[0m
GREEN		=	\033[0;32m
BLUE		=	\033[0;34m
RED			=	\033[0;31m


all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@echo "$(GREEN)MINILIBX ✓ Created libmlx.a$(NOC)"

clean:
	@rm -f $(OBJ) *~
	@echo "$(BLUE)MINILIBX ✓ Removed .o files$(NOC)"
fclean:
	@rm -f libmlx.a $(NOM)
	@echo "$(BLUE)MINILIBX ✓ Removed libmlx.a$(NOC)"
re: clean all
