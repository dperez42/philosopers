# NAMES ====================================================================================
NAME_ONE	=	philo_one
NAME_TWO	=	philo_two

# COMPILADOR ====================================================================================
CC			=	gcc
# INCLUDES ====================================================================================
INCS_DIR_ONE = src_philo_one/philosphers.h
INCS_DIR_TWO = src_philo_two/philosphers.h
INCLUDES_ONE = -I$(INCS_DIR_ONE)
INCLUDES_TWO = -I$(INCS_DIR_TWO)

# FLAGS ====================================================================================
FLAGS 		= -Wall -Wextra -Werror

# PATHS ============================
SRCS_DIR_ONE 	= 	src_philo_one/
SRCS_DIR_TWO 	= 	src_philo_two/
SRCS_ONE 		=  	main.c \
					ft_aux.c \
					ft_error.c \
					ft_time.c \
					ft_parse.c \
					ft_msg.c
SRCS_TWO	=  	main.c \
					ft_aux.c \
					ft_error.c \
					ft_time.c \
					ft_parse.c \
					ft_msg.c
SRCS_ONE2		=	$(addprefix $(SRCS_DIR_ONE), $(SRCS_ONE)) 
SRCS_TWO2		=	$(addprefix $(SRCS_DIR_TWO), $(SRCS_TWO)) 

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
OBJS_DIR 		= 	./
OBJ_ONE			=	$(SRCS_ONE2:.c=.o)
OBJS_ONE 		= 	$(addprefix $(OBJS_DIR), $(OBJ_ONE))
OBJ_TWO			=	$(SRCS_TWO2:.c=.o)
OBJS_TWO		= 	$(addprefix $(OBJS_DIR), $(OBJ_TWO))

# ==========================================================================================

# FROM SUBJECT =============================================================================
all: $(NAME_ONE) $(NAME_TWO)

bonus: $(NAME_ONE)

$(NAME_ONE): 	$(OBJS_ONE)
				$(CC) $(FLAGS) $(INCLUDES_ONE) -o $(NAME_ONE) $(OBJS_ONE)
$(NAME_TWO): 	$(OBJS_TWO)
				$(CC) $(FLAGS) $(INCLUDES_TWO) -o $(NAME_TWO) $(OBJS_TWO)
clean:
	@echo "$(RED)Objects files $(REDBOLD)$(OBJS_ONE) $(RED) removed. $(RESET)"
	@echo "$(RED)Objects files $(REDBOLD)$(OBJS_TWO) $(RED) removed. $(RESET)"
	@/bin/rm -rf $(OBJS_ONE) $(OBJS_TWO)
fclean: clean
	@echo "$(GREEN)Executable $(GREENBOLD)$(NAME_ONE) $(GREEN) removed. $(RESET)"
	@echo "$(GREEN)Executable $(GREENBOLD)$(NAME_TWO) $(GREEN) removed. $(RESET)"
	@/bin/rm -rf $(NAME_ONE) $(NAME_TWO)

re: fclean all

# testing ======================================================================================

# ==========================================================================================
