
#include "ghostbullet.h"
#include "map.h"
#include "config.h"
#include "QPixmap"
#include "ghost.h"

Ghostbullet::Ghostbullet()
{
    //加载子弹资源
    g_Bullet.load(GHOST_BULLET_PATH);

    //子弹坐标
    m_X = GAME_WIDTH*0.5 - g_Bullet.width()*0.5;
    m_Y = GAME_HEIGHT;

    //子弹状态
    m_Free = true;

    //子弹速度
    m_Speed = GHOST_BULLET_SPEED;

    //子弹边框
    m_Rect.setWidth(g_Bullet.width());
    m_Rect.setHeight(g_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Ghostbullet::updateposition()
{
    //判断子弹状态
    if(m_Free)
    {
        return;
    }
    //子弹不处于空闲，子弹要向下移动
    m_Y += m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //子弹位置超出屏幕，需要把子弹状态变成空闲状态进行回收
    if(m_Y >= GAME_HEIGHT)
    {
        m_Free = true;
    }
}

