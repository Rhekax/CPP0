NAME = megaphone
SRCS = Megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)


Megaphone.o: Megaphone.cpp
	$(CXX) $(CXXFLAGS) -c Megaphone.cpp -o Megaphone.o

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	del /f $(OBJS)

fclean: clean
	del /f $(NAME).exe

re: fclean all
