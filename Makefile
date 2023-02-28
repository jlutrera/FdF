# Paths
L_DIR		=	./libft/
S_DIR		=	./srcs/
I_DIR		=	./include/fdf.h
I_DIR_BONUS	=	./include/fdf_bonus.h
O_DIR		=	./obj/

#Files
LIB_A		=	libft.a
SRCS		=	./srcs/create_iso.c \
				./srcs/draw_lines.c \
				./srcs/ft_close.c \
				./srcs/ft_freematrix.c \
				./srcs/ft_iso.c \
				./srcs/ft_utils.c \
				./srcs/load_map.c \
				./srcs/main.c \
				./srcs/my_hooks.c \
				./srcs/process_img.c
SRCS_BONUS	=	./srcs/create_iso.c \
				./srcs/draw_lines.c \
				./srcs/ft_close.c \
				./srcs/ft_freematrix.c \
				./srcs/ft_iso.c \
				./srcs/ft_utils.c \
				./srcs/load_map.c \
				./srcs/main.c \
				./srcs/process_img.c \
				./srcs/ft_changez_bonus.c \
				./srcs/ft_translate_bonus.c \
				./srcs/ft_zoom_bonus.c \
				./srcs/my_hooks_bonus.c \
				./srcs/put_menu_bonus.c

# Sources and objects
OBJS		=	$(patsubst $(S_DIR)%, $(O_DIR)%, $(SRCS:.c=.o))
OBJS_BONUS	=	$(patsubst $(S_DIR)%, $(O_DIR)%, $(SRCS_BONUS:.c=.o))

# Constant strings
NAME		=	fdf

#Para Windows
MLXFLAGS	= 	-Lusr/lib -lmlx -lXext -lX11 -lm -lbsd
INCL		=	-Imlx_linux -I$(I_DIR)
INCL_BONUS	=	-Imlx_linux -I$(I_DIR_BONUS)

#Para Mac
#MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
#INCL		=	-I$(I_DIR)
#INCL_BONUS	=	-I$(I_DIR_BONUS)

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

bonus		:	$(NAME) ex_comp

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
	
ex_comp		:	$(OBJS_BONUS)
				@echo "$(YELLOW)Linking bonus object files ! $(RESET)\c"
				@$(CC) $(OBJS_BONUS) $(LEAKS) $(LIBFLAGS) $(MLXFLAGS) $(INCL_BONUS) -o $(NAME)
				@echo "$(GREEN)SUCCESS !$(RESET)"
				@echo "$(NAME) created successfully !"
clean		:	
				@$(MAKE) --no-print-directory clean -C $(L_DIR) 
				@rm -rf $(O_DIR)
				@echo "$(CYAN)Deleted all the object files$(RESET)"

fclean		:	clean
				@$(MAKE) --no-print-directory fclean -C $(L_DIR)
				@rm -rf $(NAME)
				@echo "$(CYAN)Deleted all the exec files$(RESET)"

re			:	fclean all

.PHONY		:	all clean fclean re bonus extra