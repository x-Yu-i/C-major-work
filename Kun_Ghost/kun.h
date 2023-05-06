
#ifndef KUN_H
#define KUN_H
#include <QPixmap>



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
};

#endif // KUN_H
