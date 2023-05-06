
#ifndef KUN_H
#define KUN_H
#include <QPixmap>
#include "bullet.h"


class Kun
{
public:
    Kun();

    //发射子弹
    void shoot();

    //设置只因哥位置
    void setPosition(int x, int y);

public:
    //资源对象
    QPixmap m_Plane;

    //只因哥坐标
    int m_X;
    int m_Y;

    //只因哥的矩形边框
    QRect m_Rect;

    //弹匣
    Bullet m_bullets[BULLET_NUM];

    //发射间隔记录
    int m_recorder;

    //飞机状态
    bool m_Free;
};

#endif // KUN_H
