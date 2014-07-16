#ifndef ADD_H_
#define ADD_H_ 

//这里加上static，表示这里的a作用域是本文件，所以不会造成链接时的重复定义问题
static int a = 10;

int add(int a, int b);

#endif  /*ADD_H_*/
