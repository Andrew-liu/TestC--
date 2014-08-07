./bin/LinkList.exe: ./tmp/LinkList_main.o  ./tmp/create_LinkList.o 	./tmp/init_LinkList.o 	./tmp/show_LinkList.o 	./tmp/create_asc_insert.o 	./tmp/create_desc_insert.o 	./tmp/create_tail_insert.o ./tmp/divide_LinkList.o ./tmp/merge_LinkList.o
	gcc -o ./bin/LinkList.exe ./tmp/LinkList_main.o ./tmp/create_LinkList.o 	./tmp/init_LinkList.o 	./tmp/show_LinkList.o 	./tmp/create_asc_insert.o 	./tmp/create_desc_insert.o 	./tmp/create_tail_insert.o ./tmp/divide_LinkList.o ./tmp/merge_LinkList.o
./tmp/LinkList_main.o: ./src/LinkList_main.c
	gcc -c ./src/LinkList_main.c -o ./tmp/LinkList_main.o -I ./include/
./tmp/init_LinkList.o: ./src/init_LinkList.c
	gcc -c ./src/init_LinkList.c -o ./tmp/init_LinkList.o -I ./include/
./tmp/create_LinkList.o: ./src/create_LinkList.c
	gcc -c ./src/create_LinkList.c -o ./tmp/create_LinkList.o -I ./include/
./tmp/create_tail_insert.o: ./src/create_tail_insert.c
	gcc -c ./src/create_tail_insert.c -o ./tmp/create_tail_insert.o -I ./include/
./tmp/create_asc_insert.o: ./src/create_asc_insert.c
	gcc -c ./src/create_asc_insert.c -o ./tmp/create_asc_insert.o -I ./include/
./tmp/create_desc_insert.o: ./src/create_desc_insert.c
	gcc -c ./src/create_desc_insert.c -o ./tmp/create_desc_insert.o -I ./include/
./tmp/show_LinkList.o: ./src/show_LinkList.c
	gcc -c ./src/show_LinkList.c -o ./tmp/show_LinkList.o -I ./include/
./tmp/divide_LinkList.o: ./src/divide_LinkList.c
	gcc -c ./src/divide_LinkList.c -o ./tmp/divide_LinkList.o -I ./include/
./tmp/merge_LinkList.o: ./src/merge_LinkList.c
	gcc -c ./src/merge_LinkList.c -o ./tmp/merge_LinkList.o -I ./include/

