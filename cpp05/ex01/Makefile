NAME			=	a.out
SRCS			=	main.cpp\
					Bureaucrat.cpp\
					Form.cpp
OBJS_DIR		=	./objs
OBJS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS			=	$(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.d))

CXX				=	c++
#CXX				=	clang++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98
CXXFLAGS		+=	-MMD -MP
#CXXFLAGS		+=	-g -fsanitize=address
RM				=	rm -f

.PHONY			:	all clean fclean re

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(CXX) $(OBJS) $(CXXFLAGS) -o $@

$(OBJS_DIR)/%.o:	%.cpp
					@[ -d $(OBJS_DIR) ]
					$(CXX) $(CXXFLAGS) -c $< -o $@

clean			:
					$(RM) $(OBJS) $(DEPS)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

-include		$(DEPS)
