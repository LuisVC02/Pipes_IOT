
CC ?= gcc

APP_NAME_PIPE_SIMPLE = pipe_simple
OBJ_FILES_PIPE_SIMPLE  = pipe_simple.o

APP_NAME_PIPE_PROCESS  = pipe_process
OBJ_FILES_PIPE_PROCESS = pipe_process.o

LIBS = .


all: $(APP_NAME_PIPE_SIMPLE) $(APP_NAME_PIPE_PROCESS)

$(APP_NAME_PIPE_SIMPLE): $(OBJ_FILES_PIPE_SIMPLE)
	$(CC) -o $@ $^


$(APP_NAME_PIPE_PROCESS): $(OBJ_FILES_PIPE_PROCESS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $^ -g


clean:
	rm *.o $(APP_NAME_PIPE_SIMPLE) $(APP_NAME_PIPE_PROCESS)

fresh:
	make clean
	make all
