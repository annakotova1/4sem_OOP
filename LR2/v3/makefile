CC = g++
CFLAGS = -std=c++0x #-Wall -Werror 

H = Set/Set.h \
AbstractContainer/AbstractContainer.h \
SetException/SetException.h \
ModifySetIterator/ModifySetIterator.h \
ConstSetIterator/ConstSetIterator.h \
AbstractIterator/AbstractIterator.h 

HPP = Set/Set.hpp \
AbstractContainer/AbstractContainer.hpp \
SetException/SetException.hpp \
ModifySetIterator/ModifySetIterator.hpp \
ConstSetIterator/ConstSetIterator.hpp \
AbstractIterator/AbstractIterator.hpp 

out/%.o:*/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $^
	
out/%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

app.exe: out/main.o $(H) $(HPP)
	$(CC) -o $@ $^

all: app.exe clean

clean:
	rm -rf out/*.o
	#//rm -rf *.exe