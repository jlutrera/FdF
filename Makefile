# Paths
L_DIR		=	./libft/
S_DIR		=	./srcs/
I_DIR		=	./include/
O_DIR		=	./obj/

#Files
LIB_A		=	libft.a
SRCS		=	$(wildcard $(S_DIR)*.c)

# Sources and objects
OBJS		=	$(patsubst $(S_DIR)%, $(O_DIR)%, $(SRCS:.c=.o))

# Constant strings
NAME		=	fdf

#Para Windows
MLXFLAGS	= 	-Lusr/lib -lmlx -lXext -lX11 -lm -lbsd
INCL		=	-Imlx_linux -I$(I_DIR)

#Para Mac
#MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
#INCL		=	-I$(I_DIR)

LIBFLAGS	=	-Llibft -lft

LEAKS		=	-g3 -fsanitize=address
W_FLAGS		=	-Wall -Wextra -Werror
LIB_N		=	$(L_DIR)$(LIB_A)

#  Colors
CYAN		=	\033[1;36m
YELLOW		=	\033[1;33m
GREEN		=	\033[0;32m
BLUE 		= 	\033[0;94m
RESET		=	\033[0m

# Rules
all			:	$(NAME)

$(O_DIR)	:
				@echo "Creating program $(YELLOW)$(NAME)$(RESET)"
				@mkdir -p $(O_DIR)

$(O_DIR)%.o	:	$(S_DIR)%.c
				@echo "$(BLUE)Compiling $@ ! $(RESET)\c"
				@$(CC) $(W_FLAGS) -c $< -o $@
				@echo "... $(GREEN)OK$(RESET)" 

$(NAME) 	:	$(LIB_N) $(O_DIR) $(OBJS)
				@echo "$(YELLOW)Linking object files ! $(RESET)\c"
				@$(CC) $(OBJS) $(LEAKS) $(LIBFLAGS) $(MLXFLAGS) $(INCL) -o $(NAME)
				@echo "$(GREEN)SUCCESS !$(RESET)"
				@echo "$(NAME) created successfully !"

$(LIB_N)	:		
				@echo "Creating library $(YELLOW) $(LIB_A) $(RESET)"
				@$(MAKE) --no-print-directory -C $(L_DIR)

clean		:	
				@$(MAKE) --no-print-directory clean -C $(L_DIR) 
				@rm -rf $(O_DIR)
				@echo "$(CYAN)Deleted all the object files$(RESET)"

fclean		:	clean
				@$(MAKE) --no-print-directory fclean -C $(L_DIR)
				@rm -rf $(NAME)
				@echo "$(CYAN)Deleted all the exec files$(RESET)"

re			:	fclean all

.PHONY		:	all clean fclean re