#pragma once
#include"lib.h"
#include"client.h"
//quan ly toan bo hoat dong cua game
//connect socket, create thread, mutex, game
class Server
{
private:
	vector<Client> clients;
	SOCKET serversock;
	sockaddr_in serverad, clientad;
public:
	Server();
	~Server();

	void Accept();

};