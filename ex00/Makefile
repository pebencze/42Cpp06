NAME = convert
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

SRCS = main.cpp ScalarConverter.cpp
OBJ_DIR = objs
DEP_DIR = deps
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS := $(addprefix $(DEP_DIR)/, $(SRCS:.cpp=.d))

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@mv $(OBJ_DIR)/*.d $(DEP_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:


