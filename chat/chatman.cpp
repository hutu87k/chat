#include "chatman.h"
#include "dataman.h"

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

ChatManager::ChatManager(DataManager* dm) : _dataMan(dm) {}
ChatManager::~ChatManager() {}

void ChatManager::AuthPage()
{
    std::string action;
    std::cout << "* ���������� ��� *" << std::endl
        << std::endl;

    while (1) {
        std::cout << std::endl << std::endl
            << "> [1] �����������" << std::endl
            << "> [2] ����" << std::endl
            << "> [3] �����" << std::endl
            << std::endl
            << "[action] >> ";
        std::getline(std::cin, action);
        std::cout << std::endl;

        // sign up
        if (action == "1") {

            std::string username,
                password;

            std::cout << "[�����] >> ";
            std::getline(std::cin, username);

            std::cout << "[������] >> ";
            std::getline(std::cin, password);

            try {
                _dataMan->Registration(username, password);
                _login = username;
                MainPage();

            }
            catch (DataManager::DataManagerException& ex) {
                std::cout << ex.what();
            }
        }

        //sign in
        else if (action == "2") {
            std::string username,
                password;

            std::cout << "[�����] >> ";
            std::getline(std::cin, username);

            std::cout << "[������] >> ";
            std::getline(std::cin, password);

            try {
                _dataMan->Authentication(username, password);
                _login = username;
                MainPage();

            }
            catch (DataManager::DataManagerException& ex) {
                std::cout << ex.what();
            }
        }

        // exit
        else if (action == "3") {

            std::cout << "[]: ����!" << std::endl;
            break;
        }

        // wrong command
        else {
            std::cout << "[������]: �� ���������� �������!" << std::endl;
            continue;
        }
    }
}

void ChatManager::MainPage()
{
    std::string action;
    while (1) {
        std::cout << std::endl << std::endl
            << "> [1] �������� ���������" << std::endl
            << "> [2] ���������" << std::endl
            << "> [3] �����" << std::endl
            << std::endl
            << "(" << _login << ")[action] >> ";
        std::getline(std::cin, action);
        std::cout << std::endl;

        // inbox
        if (action == "1") {
            InboxPage();
            continue;
        }

        // send message
        else if (action == "2") {

            std::string reciepient,
                message;

            std::cout << "(" << _login << ")[���������] >> ";
            std::getline(std::cin, message);

            std::cout << "(" << _login << ")[���������: all/username] >> ";
            std::getline(std::cin, reciepient);

            try {
                if (reciepient == "all") {
                    _dataMan->SendMessage(_login, message);

                }
                else {
                    _dataMan->SendMessage(_login, reciepient, message);
                }
                std::cout << "(" << _login << ")[]: �����������" << std::endl;

            }
            catch (DataManager::DataManagerException& ex) {
                std::cout << ex.what();
            }
            continue;
        }

        // logout
        else if (action == "3") {
            break;
        }

        // wrong command
        else {
            std::cout << "(" << _login << ")[������]: �� ���������� �������!" << std::endl;
            continue;
        }
    }
}

void ChatManager::InboxPage()
{
    std::string action;
    auto messagesBegin = _dataMan->GetBeginMessage(_login),
        messagesEnd = _dataMan->GetEndMessage(_login),
        messageIter = messagesBegin;

    while (1) {
        std::cout << std::endl << std::endl
            << "> [1] ��������� ���������" << std::endl
            << "> [2] ������� ���������" << std::endl
            << "> [3] ��������� � ���� " << std::endl
            << std::endl
            << "(" << _login << ")[action] >> ";
        std::getline(std::cin, action);
        std::cout << std::endl;

        if (action == "1") {
            if (messageIter != messagesEnd) {
                std::cout << *messageIter << std::endl;
                ++messageIter;

            }
            else {
                std::cout << "(" << _login << ")[]: ��� ������ ���������" << std::endl;
            }
            continue;
        }

        else if (action == "2") {
            if (messageIter != messagesBegin) {
                --messageIter;
                std::cout << *messageIter << std::endl;

            }
            else {
                std::cout << "(" << _login << ")[]: ��� ������� ���������" << std::endl;
            }
            continue;
        }

        // main menu
        else if (action == "3") {
            break;
        }

        // wrong command
        else {
            std::cout << "(" << _login << ")[������]: �� ���������� �������!" << std::endl;
            continue;
        }
    }
}
