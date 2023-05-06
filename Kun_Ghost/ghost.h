
#ifndef GHOST_H
#define GHOST_H
#include <QPixmap>
#include "ghostbullet.h"
#include "config.h"


class Ghost
{
public:
    Ghost();

    //发射子弹
    void shoot();

    //更新坐标
    void updatePosition();
public:
    //敌机资源对象
    QPixmap m_enemy;

    //位置
    int m_X;
    int m_Y;

    //敌机的矩形边框（碰撞检测）
    QRect m_Rect;

    //状态
    bool m_Free;

    //速度
    int m_Speed;

    //弹匣
    Ghostbullet m_bullets[GHOST_BULLET_NUM];

    //发射间隔记录
    int m_recorder;

};

#endif // GHOST_H
