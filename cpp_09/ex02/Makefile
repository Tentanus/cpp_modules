# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/14 18:12:58 by mweverli      #+#    #+#                  #
#    Updated: 2023/09/04 17:29:55 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


#========================================#
#=========  GENERAL VARIABLES:  =========#
#========================================#

NAME			:=	PmergeMe

OBJ_DIR			:=	OBJ
SRC_DIR			:=	src
INC_DIR			:=	inc
LIB_DIR			:=	lib

SRC				:=	\
					JacobSthalSequence.cpp		\
					main.cpp					\


OBJ				:=	$(SRC:%.cpp=$(OBJ_DIR)/%.o)
SRC				:=	$(SRC:%=$(SRC_DIR)/%)
DEP				:=	$(OBJ:.o=.d)
DIR_LIST		:=	$(sort $(dir $(OBJ)))

-include $(DEP)

#============= COMPILATION ==============#

INCLUDE			:=	-I $(INC_DIR)

CC				:=	c++
CFL				:=	-Wall -Werror -Wextra -Wpedantic -std=c++20

ifdef DEBUG
CFL				+=	-g -fstandalone-debug
endif

ifndef NOMSG
CFL				+=	-D MSG=1
endif

ifdef FSAN
CFL				+=	 -fsanitize=address,undefined
endif

#=============  SHOW TIME  ==============#

ifdef VERB
CFL				+=	-D VERB=1
SHOW_ALL		:=	1
endif

ifdef SHOW_ALL
SHOW			:=	1
SHOW_OPP		:=	1
endif

ifdef SHOW
CFL				+=	-D SHOW=1
endif

ifdef SHOW_OPP
CFL				+= -D SHOW_OPP=1
endif

COMPILE			:=	$(CC) $(CFL)

INFO_FL			:=											\
$(if $(findstring -std=c++98,$(CFL)),c++98)					\
$(if $(findstring -std=c++11,$(CFL)),c++11)					\
$(if $(findstring -g,$(CFL)),-g)							\
$(if $(findstring address,$(CFL)),addr)						\
$(if $(findstring undefined,$(CFL)),undef)					\
$(if $(findstring MSG,$(CFL)),msg)							\
$(if $(findstring SHOW,$(CFL)),show)						\


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

echo:
	@echo $(SRC) "\n"
	@echo $(OBJ) "\n"

#========================================#
#============ MISCELLANEOUS =============#
#========================================#

.PHONY: all clean fclean re debug rebug echo

.DEFAULT_GOAL := all

#=============== COLOURS ================#

OS		:=	$(shell uname -r)

ifneq ($(OS), 6.3.6-arch1-1)
	BOLD	:= \033[1m
	RED		:= \033[31;1m
	GREEN	:= \033[32;1m
	CYAN	:= \033[36;1m
	RESET	:= \033[0m
endif
