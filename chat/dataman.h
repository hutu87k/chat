#ifndef DATA_MAN_H
#define DATA_MAN_H

#include <exception>
#include <map>
#include <string>
#include <vector>

struct DataManager
{
    DataManager();
    ~DataManager();

    void Authentication(const std::string& username,
        const std::string& password);

    void Registration(const std::string& username,
        const std::string& password);

    void SendMessage(const std::string& sender,
        const std::string& reciepient,
        const std::string& message);

    void SendMessage(const std::string& sender,
        const std::string& message);

    std::vector<std::string>::reverse_iterator
        GetBeginMessage(const std::string& username);

    std::vector<std::string>::reverse_iterator
        GetEndMessage(const std::string& username);

    struct DataManagerException : public std::exception
    {
        DataManagerException(const char* message) : _msg(message) {}
        const char* what() const noexcept override { return _msg; }

    private:
        const char* _msg;
    };

private:
    std::map< std::string, std::string >              usersRecords_;
    std::map< std::string, std::vector<std::string> > usersInbox_;
};

#endif
