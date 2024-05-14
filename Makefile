all:
	gcc ./src/*.c -I include -o alone

run:
	./alone

clean:
	rm alone


