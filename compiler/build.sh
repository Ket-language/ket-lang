# delete old bin:
	rm -rf ../src/bin
# make new bin:
	gcc main.c chunk.c debug.c memory.c value.c -o ../src/bin
