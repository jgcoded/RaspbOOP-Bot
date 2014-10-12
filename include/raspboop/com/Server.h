#ifndef RASPBOOP_COM_SERVER_H
#define RASPBOOP_COM_SERVER_H

#include <functional>
#include <atomic>
#include <mutex>
#include "raspboop/Raspboop.h"

namespace rbp
{

class Server
{

public:

    Server();

    void Initialize();

    void AddCallback(std::function<void(Command&&)> callback);

    void Start();

    void Stop();

    ~Server();

private:

    void ServerThread();

    int mSockfd;
    vector<std::function<void(Command&&)>> mCallbacks;
    std::atomic<bool> mServerRunning;
    std::atomic<bool> mStopServer;
    std::mutex mServerMutex;

};


} /* rbp */

#endif	/* RASPBOOP_COM_SERVER_H */
