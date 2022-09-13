#ifndef INPUT_DRIVER_H
#define INPUT_DRIVER_H

#include <string>

enum MouseButtonType
{
	MouseButtonLeft = 0,
	MouseButtonMid = 1,
	MouseButtonRight = 2
};

enum GameKey
{
    GameKey_A = 401,
    GameKey_S = 402,
    GameKey_D = 403,
    GameKey_F = 404,
    GameKey_G = 405,
    GameKey_H = 406,
    GameKey_J = 407,
    GameKey_K = 408,
    GameKey_L = 409,
    GameKey_Z = 501,
    GameKey_X = 502,
    GameKey_C = 503,
    GameKey_V = 504,
    GameKey_B = 505,
    GameKey_N = 506,
    GameKey_M = 507,


    //上下左右方向键
    GameKey_Up = 709,
    GameKey_Down = 711,
    GameKey_Left = 710,
    GameKey_Right = 712,
};

class CDD;
class Player
{
public:
    Player(std::wstring dllName);
    ~Player();
	int Initialize();

public:
    bool MouseClick(MouseButtonType type);
	void MouseMove(int x, int y);
    void KeyClick(int keyValue);
private:
	CDD* m_Driver;
    std::wstring m_dllName;
};

#endif // INPUT_DRIVER_H

