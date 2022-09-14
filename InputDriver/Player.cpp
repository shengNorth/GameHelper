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
    m_dllName(dllName), m_block(50, 50, Qt::blue)
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

void Player::Move(MoveDirection direct)
{
    int key = -1;
    if (direct == MoveDirection::UP)
    {
        key = GameKey_Up;
    }
    else if (direct == MoveDirection::DOWN)
    {
        key = GameKey_Down;
    }
    else if(direct == MoveDirection::LEFT)
    {
        key = GameKey_Left;
    }
    else if(direct == MoveDirection::RIGHT)
    {
        key = GameKey_Right;
    }
    m_Driver->DD_key(key, 1);
    Sleep(10);
    m_Driver->DD_key(key, 2);
    Sleep(10);
    m_Driver->DD_key(key, 1);
    Sleep(500);
    m_Driver->DD_key(key, 2);
}

void Player::MoveToEnemy(const QPoint &enemyPt)
{
    if (this->x < enemyPt.x() - m_block.Width)
    {
        Move(MoveDirection::RIGHT);
    }
    else if (this->x > enemyPt.x() + m_block.Width)
    {
        Move(MoveDirection::LEFT);
    }

    if (this->y < enemyPt.y() - m_block.Height)
    {
        Move(MoveDirection::DOWN);
    }
    else if (this->y > enemyPt.y() + m_block.Height)
    {
        Move(MoveDirection::UP);
    }
}
