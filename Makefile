# NAMES ====================================================================================
NAME_ONE	=	philo_one
NAME_TWO	=	philo_two
NAME_THREE	=	philo_three
# COMPILADOR ====================================================================================
CC			=	gcc
# INCLUDES ====================================================================================
INCS_DIR_ONE = src_philo_one/philosphers.h
INCS_DIR_TWO = src_philo_two/philosphers2.h
INCS_DIR_THREE = src_philo_three/philosphers3.h
INCLUDES_ONE = -I$(INCS_DIR_ONE)
INCLUDES_TWO = -I$(INCS_DIR_TWO)
INCLUDES_THREE = -I$(INCS_DIR_THREE)
# FLAGS ====================================================================================
FLAGS 		= -Wall -Wextra -Werror

# PATHS ============================
SRCS_DIR_ONE 	= 	src_philo_one/
SRCS_DIR_TWO 	= 	src_philo_two/
SRCS_DIR_THREE 	= 	src_philo_three/
SRCS_ONE 		=  	main.c \
					ft_aux.c \
					ft_error.c \
					ft_time.c \
					ft_parse.c \
					ft_msg.c \
					ft_forks.c
SRCS_TWO		=  	main2.c \
					ft_aux2.c \
					ft_error2.c \
					ft_time2.c \
					ft_parse2.c \
					ft_msg2.c
SRCS_THREE		=  	main3.c \
					ft_aux3.c \
					ft_error3.c \
					ft_time3.c \
					ft_parse3.c \
					ft_msg3.c \
					ft_pids.c
SRCS_ONE2		=	$(addprefix $(SRCS_DIR_ONE), $(SRCS_ONE)) 
SRCS_TWO2		=	$(addprefix $(SRCS_DIR_TWO), $(SRCS_TWO)) 
SRCS_THREE2		=	$(addprefix $(SRCS_DIR_THREE), $(SRCS_THREE)) 

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
OBJS_DIR_TWO		= 	./
OBJS_DIR_THREE		= 	./
OBJ_ONE			=	$(SRCS_ONE2:.c=.o)
OBJS_ONE 		= 	$(addprefix $(OBJS_DIR_ONE), $(OBJ_ONE))
OBJ_TWO			=	$(SRCS_TWO2:.c=.o)
OBJS_TWO		= 	$(addprefix $(OBJS_DIR_TWO), $(OBJ_TWO))
OBJ_THREE			=	$(SRCS_THREE2:.c=.o)
OBJS_THREE		= 	$(addprefix $(OBJS_DIR_THREE), $(OBJ_THREE))

# ==========================================================================================

# FROM SUBJECT =============================================================================
all: $(NAME_ONE) $(NAME_TWO) $(NAME_THREE)

$(NAME_ONE): 	$(OBJS_ONE)
				$(CC) $(FLAGS) $(INCLUDES_ONE) -o $(NAME_ONE) $(OBJS_ONE)
$(NAME_TWO): 	$(OBJS_TWO)
				$(CC) $(FLAGS) $(INCLUDES_TWO) -o $(NAME_TWO) $(OBJS_TWO)
$(NAME_THREE): 	$(OBJS_THREE)
				$(CC) $(FLAGS) $(INCLUDES_THREE) -o $(NAME_THREE) $(OBJS_THREE)
clean:
	@echo "$(RED)Objects files $(REDBOLD)$(OBJS_ONE) $(RED) removed. $(RESET)"
	@echo "$(RED)Objects files $(REDBOLD)$(OBJS_TWO) $(RED) removed. $(RESET)"
	@echo "$(RED)Objects files $(REDBOLD)$(OBJS_THREE) $(RED) removed. $(RESET)"
	@/bin/rm -rf $(OBJS_ONE) $(OBJS_TWO) $(OBJS_THREE)
fclean: clean
	@echo "$(GREEN)Executable $(GREENBOLD)$(NAME_ONE) $(GREEN) removed. $(RESET)"
	@echo "$(GREEN)Executable $(GREENBOLD)$(NAME_TWO) $(GREEN) removed. $(RESET)"
	@echo "$(GREEN)Executable $(GREENBOLD)$(NAME_THREE) $(GREEN) removed. $(RESET)"
	@/bin/rm -rf $(NAME_ONE) $(NAME_TWO) $(NAME_THREE)

re: fclean all

.PHONY: all clean fclean re

# testing ======================================================================================

# ==========================================================================================
