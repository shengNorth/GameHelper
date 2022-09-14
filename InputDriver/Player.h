#ifndef INPUT_DRIVER_H
#define INPUT_DRIVER_H

#include <string>
#include <QPoint>
#include <QColor>

enum MouseButtonType
{
	MouseButtonLeft = 0,
	MouseButtonMid = 1,
	MouseButtonRight = 2
};

enum MoveDirection
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
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


    //�������ҷ����
    GameKey_Up = 709,
    GameKey_Down = 711,
    GameKey_Left = 710,
    GameKey_Right = 712,
};

struct ColorBlock
{
    int Width;
    int Height;
    QColor Color;

    ColorBlock(int width, int height, QColor color):
        Width(width), Height(height), Color(color)
    {

    }
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

    /**
     * @brief MoveClick ���ƽ�ɫ�ƶ�,
     */
    void Move(MoveDirection direct);

    /**
     * @brief MoveTo    �����������
     * @param enemyPt   ��������
     */
    void MoveToEnemy(const QPoint& enemyPt);
private:
	CDD* m_Driver;
    std::wstring m_dllName;

private:
    //��ɫ��ͼ���е�����
    int x;
    int y;

    //��ɫ��ɫ��
    ColorBlock  m_block;
};

#endif // INPUT_DRIVER_H

