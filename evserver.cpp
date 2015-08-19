// 服务器端
#include <iostream>
#include <event.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>

using namespace std;

struct event_base* main_base;

static const char MESSAGE[] ="Hello, World!\n";

void accept_handle(const int sfd, const short event, void *arg)
{
	cout<<"accept handle"<<endl;

	struct sockaddr_in addr;

	socklen_t addrlen = sizeof(addr);

	int fd = accept(sfd, (struct sockaddr *) &addr, &addrlen); //处理连接

	struct bufferevent* buf_ev;
	buf_ev = bufferevent_new(fd, NULL, NULL, NULL, NULL);

	buf_ev->wm_read.high = 4096;

	cout<<"event write"<<endl;
	bufferevent_write(buf_ev, MESSAGE, strlen(MESSAGE));
}

int main()
{
	cout<<"hello man!"<<endl;

	// 1. 初始化EVENT
	main_base = event_init();
	if(main_base)
		cout<<"init event ok!"<<endl;

	// 2. 初始化SOCKET
	int sListen;

	// Create listening socket
	sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// Bind
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(struct sockaddr_in));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	int portnumber = 8080;
	server_addr.sin_port = htons(portnumber);

	/* 捆绑sockfd描述符  */
	if(bind(sListen,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1)
	{
		cout<<"error!"<<endl;
		return -1;
	}

	// Listen
	::listen(sListen, 3);
	cout<<"Server is listening!\n"<<endl;

	/*将描述符设置为非阻塞*/
	int flags = ::fcntl(sListen, F_GETFL);

	flags |= O_NONBLOCK;

	fcntl(sListen, F_SETFL, flags);

	// 3. 创建EVENT 事件
	struct event ev;
	event_set(&ev, sListen, EV_READ | EV_PERSIST, accept_handle, (void *)&ev);

	// 4. 事件添加与删除
	event_add(&ev, NULL);

	// 5. 进入事件循环
	event_base_loop(main_base, 0);

	cout<<"over!"<<endl;
}