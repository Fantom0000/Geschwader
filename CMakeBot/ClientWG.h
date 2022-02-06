#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include "json.hpp"

#define WIN32_LEAN_AND_MEAN

constexpr const char* DEFAULT_IP = "92.223.34.102";
constexpr const char* DEFAULT_PORT = "443";
constexpr uint32_t DEFAULT_BUFLEN = 8192;

using nlohmann::json;

struct Query {
    uint32_t code;
    std::string json_data;

    Query() = default;
    Query(uint32_t code, json data = "") : code(code), json_data(data.dump()) {}
};

enum Action
{
    LOGIN = 1,
    LOGOUT = 2,
    MAP = 3,
    GAME_STATE = 4,
    GAME_ACTIONS = 5,
    TURN = 6,
    CHAT = 100,
    MOVE = 101,
    SHOOT = 102
};

enum Result
{
    OKEY = 0,
    BAD_COMMAND = 1,
    ACCESS_DENIED = 2,
    INAPPROPRIATE_GAME_STATE = 3,
    TIMEOUT = 4,
    INTERNAL_SERVER_ERROR = 500
};

class ClientWG
{
public:
    void start_work();
    Query send_data(const Query& data);
    void end_work();
private:
    WSADATA wsaData;
    SOCKET connectSocket;
};

