
#include "mainscene.h"
#include "config.h"
#include "QIcon"
#include "QPainter"
#include <QMouseEvent>
#include <ctime>

void MainScene::initScene()
{
    //初始化窗口大小
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置窗口标题
    setWindowTitle(GAME_TITLE);

    //设置图标资源
    setWindowIcon(QIcon(GAME_ICON)); //加头文件 #include <QIcon>

    //定时器设置
    m_Timer.setInterval(GAME_RATE);

    m_recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL)); //头文件 #include <ctime>

}

void MainScene::playGame()
{
    //启动定时器
    m_Timer.start();

    //监听定时器
    connect(&m_Timer,&QTimer::timeout,[=](){
        //我爱罗出场
        enemyToScene();

        //更新游戏中元素的坐标
        updatePosition();

        //重新绘制图片
        update();

        //碰撞检测
        collisionDetection();
    });
}

void MainScene::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();

    //只因哥发射子弹
    m_hero.shoot();

    //计算只因哥子弹坐标
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!m_hero.m_bullets[i].m_Free)
        {
            m_hero.m_bullets[i].updatePosition();
        }
    }

    //我爱罗坐标计算
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        //非空闲我爱罗 更新坐标
        if(m_enemys[i].m_Free == false)
        {
            m_enemys[i].updatePosition();
            //我爱罗发射子弹
            m_enemys[i].shoot();
            for(int j = 0 ;j < GHOST_BULLET_NUM;j++)
            {
                //如果子弹状态为非空闲，计算发射位置
                if(!m_enemys[i].m_bullets[j].m_Free)
                {
                    m_enemys[i].m_bullets[j].updatePosition();
                }
            }
        }
    }

    //计算爆炸播放的图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
            m_bombs[i].updateInfo();
        }
    }

}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY , m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY , m_map.m_map2);

    //绘制只因哥
    if(m_hero.m_Free == false)
    {
        painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);
    }
    //飞机被击毁游戏结束绘制游戏结束
    else
    {
        painter.drawPixmap(GAME_WIDTH/2-100,GAME_HEIGHT/2-20,gameover);
    }

    //绘制子弹
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        //如果子弹状态为非空闲，计算发射位置
        if(!m_hero.m_bullets[i].m_Free)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
        }
    }

    //绘制我爱罗
    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free == false)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
            //绘制我爱罗的子弹
            for(int j = 0 ;j < GHOST_BULLET_NUM; j++)
            {
                //如果子弹状态为非空闲，计算发射位置
                if(!m_enemys[i].m_bullets[j].m_Free)
                {
                    painter.drawPixmap(m_enemys[i].m_bullets[j].m_X,m_enemys[i].m_bullets[j].m_Y,m_enemys[i].m_bullets[j].g_Bullet);
                }
            }
        }
    }

    //绘制爆炸图片
    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
            painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_hero.m_Rect.width()*0.5; //鼠标位置 - 飞机矩形的一半
    int y = event->y() - m_hero.m_Rect.height()*0.5;

    //边界检测
    if(x <= 0 )
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - m_hero.m_Rect.width())
    {
        x = GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - m_hero.m_Rect.height())
    {
        y = GAME_HEIGHT - m_hero.m_Rect.height();
    }

    //设置飞机当前位置
    m_hero.setPosition(x,y);

}

void MainScene::enemyToScene()
{
    m_recorder++;
    if(m_recorder < ENEMY_INTERVAL)
    {
        return;
    }

    m_recorder = 0;

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //敌机空闲状态改为false
            m_enemys[i].m_Free = false;
            //设置坐标
            m_enemys[i].m_X = rand() % (GAME_WIDTH - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //空闲飞机 跳转下一次循环
            continue;
        }

        //遍历所有 非空闲的子弹
        for(int j = 0 ; j < BULLET_NUM;j++)
        {
            if(m_hero.m_bullets[j].m_Free)
            {
                //空闲子弹 跳转下一次循环
                continue;
            }
            //如果子弹矩形框和敌机矩形框相交，发生碰撞，同时变为空闲状态即可
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free = true;
                m_hero.m_bullets[j].m_Free = true;
                //播放爆炸效果
                for(int k = 0; k < BOMB_NUM; k++)
                {
                    if(m_bombs[k].m_Free)
                    {
                        //空闲的爆炸，可播放爆炸
                        m_bombs[k].m_Free = false;
                        //更新爆炸坐标
                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }
    }
}

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //初始化场景
    initScene();

    //启动游戏
    playGame();
}

MainScene::~MainScene()
{
}


