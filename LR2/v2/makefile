CC = g++ 
CFLAGS = -Wall -Werror

%.o:%.c 
	$(CC) $(CFLAGS) -o $@ -c $^

app.exe: *.o *.h
	$(CC) -o $@ $^

clean: 
	rm -rf *.o main app.exe