# ============================================================================ #
#                                                                              #
#    ██╗  ██╗██████╗   █████╗ ██╗   ██╗                                        #
#    ██║  ██║╚════██╗ ██╔══██╗██║   ██║                                        #
#    ███████║ █████╔╝ ███████║██║   ██║       by: bgronon                      #
#    ╚════██║██╔═══╝  ██╔══██║╚██╗ ██╔╝       at: 2015/02/28 10:17:06          #
#         ██║███████╗ ██║  ██║ ╚████╔╝                                         #
#         ╚═╝╚══════╝ ╚═╝  ╚═╝  ╚═══╝                                          #
#                                                                              #
# ============================================================================ #

NAME				= game_2048

CC					= clang
FLAG				= -Wall -Werror -Wextra -pedantic
INCS				= -I inc -I ./inc -I libft/inc
LIBS				= -L libft -lft -L /usr/lib -lncurses

SRC					= $(DIR_SRC)/main.c \
					  $(DIR_SRC)/error.c \
					  $(DIR_SRC)/ft_mov.c \
					  $(DIR_SRC)/ft_game.c \
					  $(DIR_SRC)/ft_draw.c \
					  $(DIR_SRC)/ft_mock.c \
					  $(DIR_SRC)/ft_utils.c \
					  $(DIR_SRC)/ft_finish.c \
					  $(DIR_SRC)/ft_loop.c \
					  $(DIR_SRC)/ft_menu.c \

# ---------------------------------------------------------------------------- #

DIR_LIST			= src
DIR_SRC				= src
DIR_INC				= inc
DIR_OBJ				= .obj

OBJ					= $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

# ---------------------------------------------------------------------------- #

all: libft $(NAME)

libft:
	@$(MAKE) -C libft

$(addprefix $(DIR_OBJ)/, %.o): %.c $(DIR_INC)
	@printf "compiling \e[33m%-41s\e[0m" "$@..."
	@$(CC) $(FLAG) $(INCS) -o $@ -c $<
	@printf "\e[32m[✔]\e[0m\n"

$(NAME): $(DIR_OBJ) $(OBJ)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@$(CC) $(FLAG) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

$(DIR_OBJ) :
	@/bin/mkdir $(DIR_OBJ); \
		for DIR in $(DIR_LIST); \
		do \
		/bin/mkdir $(DIR_OBJ)/$$DIR; \
		done

clean:
	@$(MAKE) -C libft $@
	@/bin/rm -rf $(DIR_OBJ);
	@printf "\e[32m[✔]\e[0m Project cleaned.\n"

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -rf $(NAME);
	@printf "\e[32m[✔]\e[0m Project fcleaned.\n"

re: fclean all

debug : FLAG += -g3 -fno-inline -DD_ERRORS_ON
debug : re
	@printf '\033[1;31m%s\033[0m\n' "Debug enabled."

.PHONY: clean fclean re debug libft
