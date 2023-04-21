CFLAGS = -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES = -lm
CC ?= gcc

TASKS = v1 mod2 Nmem tile tile-rectangular
PLAIN_TARGETS = $(TASKS:%=ToyMFE-%)
VERIFY_RAND_TARGETS = $(PLAIN_TARGETS:%=%.verify_rand)

all: bin ToyMFE_verify.o $(PLAIN_TARGETS) $(VERIFY_RAND_TARGETS)

# Executables	
ToyMFE-%: ToyMFE-%.o
	$(CC) ToyMFE-wrapper.c -o bin/$@ bin/$< $(CFLAGS) $(LIBRARIES)

ToyMFE-%.verify_rand: ToyMFE_verify.o ToyMFE-%.o
	$(CC) ToyMFE-wrapper.c -o bin/$@ $(^:%=bin/%) $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

# Object files
ToyMFE-%.o : ToyMFE-%.c
	$(CC) $< -o bin/$@ $(CFLAGS) $(LIBRARIES) -c

ToyMFE_verify.o : ToyMFE_verify.c
	$(CC) ToyMFE_verify.c -o bin/ToyMFE_verify.o $(CFLAGS) $(LIBRARIES) -c

bin:
	mkdir -p bin

clean:
	rm -f bin/*	
	rmdir bin
