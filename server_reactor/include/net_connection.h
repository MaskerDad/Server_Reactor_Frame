#pragma once

/*
 *
 * 抽象的链接类 
 *
 * */
class net_connection 
{
public:
    net_connection() {}

    //纯虚函数 
    virtual int send_message(const char *data, int msglen, int msgid) = 0;
};

//创建链接/销毁链接 要触发的回调函数的 函数类型
typedef  void (*conn_callback)(net_connection *conn, void *args);
