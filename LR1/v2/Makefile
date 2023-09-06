CC = g++
CFLAGS = -Wall -Werror -c

ALL_O = out/main.o 
ALL_I = inc/structs.hpp

out/%.o: src/%.cpp
	$(CC) $(CFLAGS) -o $@ $^

app.exe: $(ALL_O) $(ALL_I)
	$(CC) -o $@ $(ALL_O)