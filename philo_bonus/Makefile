# NAMES ====================================================================================
NAME_ONE	=	philo_bonus
# COMPILADOR ====================================================================================
CC			=	gcc
# INCLUDES ====================================================================================
INCS_DIR_ONE = philosphers.h
INCLUDES_ONE = -I$(INCS_DIR_ONE)
# FLAGS ====================================================================================
FLAGS 		= -Wall -Wextra -Werror

# PATHS ============================
SRCS_DIR_ONE 	= 	./
SRCS_ONE 		=  	main.c \
					ft_aux.c \
					ft_error.c \
					ft_time.c \
					ft_parse.c \
					ft_msg.c \
					ft_pids.c \
					ft_forks.c
SRCS_ONE2		=	$(addprefix $(SRCS_DIR_ONE), $(SRCS_ONE))  

# COLOURS ====================================================================================

RED = \033[0;31m
REDBOLD = \033[1;31m
GREEN = \033[0;32m
GREENBOLD = \033[1;32m
BLUE = \033[1;34m
RESET = \033[0m
PURPLE = \033[0;35m
YELLOW = \033[0;33m

# OBJS =====================================================================================
OBJS_DIR_ONE 		= 	./
OBJ_ONE			=	$(SRCS_ONE2:.c=.o)
OBJS_ONE 		= 	$(addprefix $(OBJS_DIR_ONE), $(OBJ_ONE))

# ==========================================================================================

# FROM SUBJECT =============================================================================
all: $(NAME_ONE) 

$(NAME_ONE): 	$(OBJS_ONE)
				$(CC) $(FLAGS) $(INCLUDES_ONE) -o $(NAME_ONE) $(OBJS_ONE)
clean:
	@echo "$(RED)Objects files $(REDBOLD)$(OBJS_ONE) $(RED) removed. $(RESET)"
	@/bin/rm -rf $(OBJS_ONE) 
fclean: clean
	@echo "$(GREEN)Executable $(GREENBOLD)$(NAME_ONE) $(GREEN) removed. $(RESET)"
	@/bin/rm -rf $(NAME_ONE) 
re: fclean all

.PHONY: all clean fclean re

# testing ======================================================================================

# ==========================================================================================
