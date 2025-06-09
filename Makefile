NAME = splendor
CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -O2
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = src/main.cpp src/Card.cpp

OBJ_DIR = obj
OBJS = $(patsubst src/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

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

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(COMP_BEFORE)$@$(COMP_AFTER)"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "$(COMP_DONE)"

$(OBJ_DIR)/%.o: src/%.cpp
	@echo "$(COMP_BEFORE)$(notdir $<)$(COMP_AFTER)"
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(COMP_DONE)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)$(BOLD)Files cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

memory: $(NAME)
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re memory