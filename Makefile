CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g		#debug
#CXXFLAGS = -Wall -Wextra -std=c++17 -O2   #release 

TARGET = chess

$(TARGET):
	$(CXX) $(CXXFLAGS) *.cpp -o $(TARGET)

valgrind:
	valgrind --leak-check=full --track-origins=yes ./chess

clean:
	rm -f $(OBJS) $(TARGET)

git:
	git add .
	git commit -m "$(MSG)"
	git push