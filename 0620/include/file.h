/*************************************************************************
	> File Name: file.h
	> Author: Suqing
	> Mail:116676671@qq.com 
	> Created Time: Thu 19 Jun 2014 11:23:37 PM PDT
 ************************************************************************/


#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
void scan_dir(const char *str);
void format(char *str);


