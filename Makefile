NAME = splendor
CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = main.cpp
NAME = splendor
CXX = c++
FLAGS = -Wall -Wextra -Werror
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRCS =	main.cpp

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(COMP_BEFORE)$@$(COMP_AFTER)"
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "$(COMP_DONE)"

$(OBJ_DIR)/%.o: %.cpp
	@echo "$(COMP_BEFORE)$(notdir $<)$(COMP_AFTER)"
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) -c $< -o $@
	@echo "$(COMP_DONE)"

$(OBJ_DIR)/main.o: main.cpp

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)$(BOLD)Files cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

memory : $(NAME)
	valgrind --leak-check=full ./$(NAME)

COMP_BEFORE = $(TEAL)$(BOLD)Compiling: $(CYAN)$(BOLD)
COMP_AFTER  = $(RESET)$(PINK)... $(RESET)
COMP_DONE   = $(GREEN)(Done!)$(RESET)

BLUE	= \033[38;5;33m
PINK	= \033[1;35m
GREEN	= \033[38;2;0;255;0m
CYAN	= \033[38;2;0;255;255m
TEAL  	= \033[38;5;30m
BOLD	= \033[1m
RESET	= \033[0m

.PHONY: all clean fclean re memory