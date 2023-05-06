
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

void Ghost::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;

    //判断如果记录数字 未达到发射间隔，直接return
    if(m_recorder < GHOST_BULLET_INTERVAL)
    {
        return;
    }

    //到达发射时间处理
    //重置发射时间间隔记录
    m_recorder = 0;

    //发射子弹
    for(int i = 0 ; i < GHOST_BULLET_NUM;i++)
    {
        //如果是空闲的子弹进行发射
        if(m_bullets[i].m_Free)
        {
            //将改子弹空闲状态改为假
            m_bullets[i].m_Free = false;
            //设置发射的子弹坐标
            m_bullets[i].m_X = m_X + m_Rect.width()*0.5 - 10;
            m_bullets[i].m_Y = m_Y - 25 ;
            break;
        }
    }
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


