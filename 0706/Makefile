./bin/ftp_client: ./bin/ftp_client ./src/FTP_CLIENT.c ./src/tcp_connect.c  ./src/get_command.c ./src/del_mid_space.c ./src/consle_str.c
	gcc -o ./bin/ftp_client ./src/FTP_CLIENT.c ./src/tcp_connect.c ./src/get_command.c ./src/del_mid_space.c ./src/consle_str.c  -I ./include
./bin/ftp_server: ./bin/ftp_server ./src/FTP_SERVER.c ./src/tcp_accept.c ./src/tcp_init.c ./src/get_command.c ./src/del_mid_space.c ./src/consle_str.c
	gcc -o ./bin/ftp_server ./src/FTP_SERVER.c ./src/tcp_accept.c ./src/tcp_init.c ./src/get_command.c ./src/del_mid_space.c  ./src/consle_str.c -I ./include
