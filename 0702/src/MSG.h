/*************************************************************************
	> File Name: MSG.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 03 Jul 2014 09:59:28 AM HKT
 ************************************************************************/

#ifndef _MSG_H
#define _MSG_H


#define MSG_SIZE 8188
#define MSG_LEN  (8192 - MSG_SIZE)

typedef struct tag
{
	int s_len ;
	int s_buf[MSG_SIZE]; 
}MSG;
