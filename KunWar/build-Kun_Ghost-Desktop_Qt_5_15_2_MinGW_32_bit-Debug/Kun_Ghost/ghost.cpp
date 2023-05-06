
#include "ghost.h"
#include "config.h"

Ghost::Ghost()
{
    //我爱罗资源加载
    m_enemy.load(ENEMY_PATH);

    //我爱罗位置
    m_X = 0;
    m_Y = 0;

    //我爱罗状态
    m_Free = true;

    //我爱罗速度
    m_Speed = ENEMY_SPEED;

    //我爱罗矩形
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Ghost::updatePosition()
{
    //空闲状态，不计算坐标
    if(m_Free)
    {
        return;
    }

    m_Y += m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y >= GAME_HEIGHT)
    {
        m_Free = true;
    }
}


