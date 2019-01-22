INCPATH= -I.\
		#-isystem$(prj_dir)/src/boost

CXXFLAGS = -Wall -Wextra $(INCPATH) -pedantic -std=gnu++17

LDFLAGS = -lpthread -lrt

OBJS := main.o
EXE := pyr

all: $(EXE)

# link
$(EXE): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(EXE) 

# pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)

# compile and generate dependency info
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $*.cpp -o $*.o
	$(CXX) -MM $(CXXFLAGS) $(INCPATH) $*.cpp > $*.d

# remove compilation products
clean:
	rm -f $(EXE) *.o *.d 
	rm -rf latex html

install:
	echo "TODO"
