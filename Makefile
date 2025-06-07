NAME = splendor
CXX = c++
FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = main.cpp

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
