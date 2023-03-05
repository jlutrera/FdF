# Paths
L_DIR		=	./libft/
O_DIR		=	./obj/
I_DIR		=	./include/

#Files
LIB_A		=	libft.a
SRCS_B		=	./srcs_bonus/create_iso_bonus.c \
				./srcs_bonus/draw_lines_bonus.c \
				./srcs_bonus/ft_close_bonus.c \
				./srcs_bonus/ft_iso_bonus.c \
				./srcs_bonus/ft_utils_bonus.c \
				./srcs_bonus/load_map_bonus.c \
				./srcs_bonus/main_bonus.c \
				./srcs_bonus/process_img_bonus.c \
				./srcs_bonus/ft_changez_bonus.c \
				./srcs_bonus/ft_translate_bonus.c \
				./srcs_bonus/ft_zoom_bonus.c \
				./srcs_bonus/my_hooks_bonus.c

SRCS_M		=	./srcs/create_iso.c \
				./srcs/draw_lines.c \
				./srcs/ft_iso.c \
				./srcs/ft_utils.c \
				./srcs/load_map.c \
				./srcs/main.c \
				./srcs/my_hooks.c \
				./srcs/process_img.c

# Sources and objects
RM 			=	rm -rf
OBJS_M		=	$(patsubst $(S_DIR)%, $(O_DIR)%, $(SRCS_M:.c=.o))
OBJS_B		=	$(patsubst $(S_DIR)%, $(O_DIR)%, $(SRCS_B:.c=.o))

ifdef BONUS
HEADER		=	$(I_DIR)fdf_bonus.h
OBJS		=	$(OBJS_B)
S_DIR		=	./srcs_bonus/
else
HEADER		=	$(I_DIR)fdf.h
OBJS		=	$(OBJS_M)
S_DIR		=	./srcs/
endif

# Constant strings
NAME		=	fdf

#Para Windows
MLXFLAGS	= 	-Lusr/lib -lmlx -lXext -lX11 -lm -lbsd
INCL		=	-Imlx_linux -I$(HEADER)

#Para Mac
#MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
#INCL		=	-I$(HEADER)

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

bonus		:
				@$(MAKE) BONUS=1 --no-print-directory

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
				@$(RM) $(O_DIR)
				@echo "$(CYAN)Deleted all the object files$(RESET)"

fclean		:	clean
				@$(MAKE) --no-print-directory fclean -C $(L_DIR)
				@$(RM) $(NAME)
				@echo "$(CYAN)Deleted all the exec files$(RESET)"

re			:	fclean all

.PHONY		:	all clean fclean re bonus