# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/14 18:12:58 by mweverli      #+#    #+#                  #
#    Updated: 2023/07/14 15:51:22 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME		:=	Violence

OBJ_DIR		:=	OBJ
SRC_DIR		:=	src
INC_DIR		:=	inc
LIB_DIR		:=	lib

SRC			:=	\
				main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp

OBJ			:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)
SRC			:=	$(SRC:%=$(SRC_DIR)/%)
DEP			:=	$(OBJ:.o=.d)
DIR_LIST	:=	$(sort $(dir $(OBJ)))

-include $(DEP)

#============= COMPILATION ==============#

INCLUDE		:=	-I $(INC_DIR)

CC			:=	c++
CFL			:=	-Wall -Werror -Wextra -Wpedantic -std=c++11

ifdef DEBUG
CFL			+=	-g
endif

ifdef FSAN
CFL			+=	 -fsanitize=address,undefined
endif

COMPILE		:=	$(CC) $(CFL)

INFO_FL		:=												\
$(if $(findstring -std=c++98,$(CFL)),c++98)					\
$(if $(findstring -g,$(CFL)),-g)							\
$(if $(findstring address,$(CFL)),addr)						\
$(if $(findstring undefined,$(CFL)),undef)					\


#========================================#
#============== RECIPIES  ===============#
#========================================#

all:$(DIR_LIST) $(NAME)

$(DIR_LIST):
	@mkdir -p $@

$(NAME): $(OBJ)
	@echo ""
	@$(COMPILE) $(INCLUDE) $(OBJ) -o $(NAME)
	@echo "$(COMPILE) $(INCLUDE) $(CYAN)$(notdir $(OBJ))$(RESET) -o $(NAME)"

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@$(COMPILE) $(INCLUDE) -MMD -o $@ -c $< 
	@echo "$(CYAN)COMPILE $(INFO_FL) $(notdir $(<:%.c=%))$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)CLEANING $(NAME)$(RESET)"

fclean: clean 
	@rm -f $(NAME)

re: fclean all

#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean re debug rebug

.DEFAULT_GOAL := all

#=============== COLOURS ================#

BOLD	:= \033[1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
CYAN	:= \033[36;1m
RESET	:= \033[0m

