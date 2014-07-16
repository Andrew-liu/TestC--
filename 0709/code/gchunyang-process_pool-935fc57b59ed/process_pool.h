#ifndef PROCESS_POOL_H_
#define PROCESS_POOL_H_


#include "sysutil.h"

typedef enum {
	BUSY, LEISURE
} STATUS;

typedef struct {
	pid_t child_;
	int sockfd_;
	STATUS status_;
} child_t;

#define MAXCHILD 10

typedef struct {
	child_t childs_[MAXCHILD];
	int size_;
	int listenfd_;
} pool_t;


void process_pool_init(pool_t *pool, int size, int listenfd);
void process_pool_do_select(pool_t *pool);
void process_pool_do_accept(pool_t *pool);
int process_pool_schedule_child(const pool_t *pool);
void process_pool_fork_child(pool_t *pool, int size);
void process_pool_do_select_clients(pool_t *pool);



#endif /* PROCESS_POOL_H_ */
