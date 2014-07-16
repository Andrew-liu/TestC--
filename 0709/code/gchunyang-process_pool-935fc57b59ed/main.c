#include "sysutil.h"
#include "process_pool.h"


int init_listenfd();

int main(int argc, const char *argv[]) {

	int listenfd = init_listenfd();
	pool_t pool;
	process_pool_init(&pool, 5, listenfd);

	close(listenfd);

	return 0;
}

int init_listenfd() {
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd < 0) {
		ERR_EXIT("socket");
	}

	int on = 1;
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
		ERR_EXIT("setsockopt");

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8989);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	socklen_t len = sizeof servaddr;
	int ret = bind(listenfd, (struct sockaddr*) &servaddr, len);
	if (ret < 0) {
		ERR_EXIT("bind");
	}

	ret = listen(listenfd, SOMAXCONN);
	if (ret < 0) {
		ERR_EXIT("listen");
	}
	return listenfd;
}

