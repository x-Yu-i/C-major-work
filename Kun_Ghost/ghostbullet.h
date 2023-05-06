
#ifndef GHOSTBULLET_H
#define GHOSTBULLET_H
#include <QPixmap>



class Ghostbullet
{
public:
    Ghostbullet();

    //Ghost子弹坐标
    void updatePosition();

    //子弹资源对象
    QPixmap g_Bullet;

    //子弹坐标
    int m_X;
    int m_Y;

    //子弹速度
    int m_Speed;

    //子弹是否闲置
    int m_Free;

    //子弹的边框(碰撞检测)
    QRect m_Rect;
};

#endif // GHOSTBULLET_H
