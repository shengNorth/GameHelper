#include "Player.h"
#include "DD.h"

enum MouseButtonValue
{
	MouseLeftPress = 1,
	MouseLeftRelease = 2,
	MouseMidPress = 16,
	MouseMidRelease = 32,
	MouseRightPress = 4,
	MouseRightRelease = 8
};

Player::Player(std::wstring dllName):
	m_dllName(dllName)
{
	m_Driver = new CDD();
}

Player::~Player()
{
	if (m_Driver != nullptr)
		delete m_Driver;
}

int Player::Initialize()
{
    int result = m_Driver->GetFunAddr(m_dllName);
    if (result == 1)
    {
        //启动
        m_Driver->DD_btn(0);
    }
    else return result;
}

bool Player::MouseClick(MouseButtonType type)
{
	if (type == MouseButtonType::MouseButtonLeft)
	{
		m_Driver->DD_btn((int)MouseButtonValue::MouseLeftPress);
		Sleep(10);
		m_Driver->DD_btn((int)MouseButtonValue::MouseLeftRelease);
		return true;
	}
	else if (type == MouseButtonType::MouseButtonMid)
	{
		m_Driver->DD_btn((int)MouseButtonValue::MouseMidPress);
		Sleep(10);
		m_Driver->DD_btn((int)MouseButtonValue::MouseMidRelease);
		return true;
	}
	else if (type == MouseButtonType::MouseButtonRight)
	{
		m_Driver->DD_btn((int)MouseButtonValue::MouseRightPress);
		Sleep(10);
		m_Driver->DD_btn((int)MouseButtonValue::MouseRightRelease);
		return true;
	}
	return false;
}

void Player::MouseMove(int x, int y)
{
    m_Driver->DD_mov(x, y);
}

void Player::KeyClick(int keyValue)
{
    m_Driver->DD_key(keyValue, 1);
    Sleep(10);
    m_Driver->DD_key(keyValue, 2);
}
