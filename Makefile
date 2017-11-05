CC = clang++
CFLAGS =  -I./inc

################################################################################
#	
################################################################################
NAME = ft_retro


################################################################################
#           INCLUDE
INC_NAME =	main.hpp \
            Window.hpp \
            ClassEnemy.hpp \
            ClassPlayer.hpp \
            ClassShot.hpp \
            ClassUnit.hpp \
            GameManeger.hpp
#                               <---------- add header file      

INC_DIR =	inc
INC = $(addprefix $(INC_DIR)/, $(INC_NAME))


################################################################################
#          OBJECT
OBJ_DIR =	.obj
OBJ = $(subst .cpp,.o,$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(SRC)))


################################################################################
#          SOURCE
SRC_DIR =	src
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
SRC_NAME =	main.cpp \
            Window.cpp \
            ClassEnemy.cpp \
            ClassPlayer.cpp \
            ClassShot.cpp \
            ClassUnit.cpp \
            GameManeger.cpp
#                               <---------- add .cpp file   


################################################################################
#	RULES
################################################################################

.PHONY: all clean fclean re t

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) -I./inc/ $(OBJ) -o $(NAME) -lncurses
	@echo "\033[33m'$(NAME)' compiling done.\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -I./inc/ -c $(CFLAGS) $? -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


##################################################################################
# dell 

lite_clean:
	rm -rf $(OBJ_DIR)

rew: lite_clean $(NAME);
	
r:	$(NAME)
	./$(NAME)

bug:
	$(CC) $(CFLAGS) $(SRC) -lncurses -g -o bug

debug: bug
	lldb -- ./bug
