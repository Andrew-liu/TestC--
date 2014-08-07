./bin/file_main.exe:  ./tmp/file_main.o ./tmp/scan_dir.o
	gcc -o ./bin/file_main.exe ./tmp/file_main.o ./tmp/scan_dir.o
./tmp/file_main.o: ./src/file_main.c
	gcc -c ./src/file_main.c -o ./tmp/file_main.o -I ./include
./tmp/scan_dir.o: ./src/scan_dir.c
	gcc -c ./src/scan_dir.c -o ./tmp/scan_dir.o -I ./include
