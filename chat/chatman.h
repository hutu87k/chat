#ifndef CHAT_MAN_H
#define CHAT_MAN_H

#include "dataman.h"

#include <string>
#include <memory>

struct ChatManager
{
    ChatManager(DataManager*);
    ~ChatManager();

    void AuthPage();
    void MainPage();
    void InboxPage();

private:
    std::unique_ptr<DataManager> _dataMan;
    std::string _login;
};

#endif
