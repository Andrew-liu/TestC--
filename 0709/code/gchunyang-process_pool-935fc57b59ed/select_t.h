#ifndef SELECT_T_H_
#define SELECT_T_H_


#include "sysutil.h"

typedef struct {
	int maxfd_;
	fd_set allset_;
	fd_set readyset_;
	int nready_;
	int maxi_;
	int clientfd_[FD_SETSIZE];
	int listenfd_;
} select_t;

void select_init(select_t *pool, int listenfd);
int select_add_to_client(select_t *pool, int fd);
int select_remove_from_client(select_t *pool, int index);
int select_do_wait(select_t *pool);
int select_is_in_set(const select_t *pool, int fd);
int select_get_max_i(const select_t *pool);
int select_get_max_fd(const select_t *pool);

/*
void select_do_listenfd(select_t *pool);
void select_do_clientfd(select_t *pool);
*/


#endif /* SELECT_T_H_ */
