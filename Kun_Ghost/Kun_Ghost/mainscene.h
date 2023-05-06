
#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "kun.h"
#include "ghost.h"
#include "bomb.h"


class MainScene : public QWidget

{
    Q_OBJECT

    //初始化场景
    void initScene();

    //启动游戏 用于启动定时器对象
    void playGame();

    //更新坐标
    void updatePosition();

    //绘图事件
    void paintEvent(QPaintEvent *);

    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    //我爱罗出场
    void enemyToScene();

    //碰撞检测
    void collisionDetection();

    //我爱罗数组
    Ghost m_enemys[ENEMY_NUM];

    //我爱罗出场间隔记录
    int m_recorder;

    //设置定时器
    QTimer m_Timer;

    //地图对象
    Map m_map;

    //绘制只因哥
    Kun m_hero;

    //爆炸数组
    Bomb m_bombs[BOMB_NUM];

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
};

#endif // MAINSCENE_H
