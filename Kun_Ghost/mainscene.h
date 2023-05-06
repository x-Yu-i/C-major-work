
#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "kun.h"


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

    //设置定时器
    QTimer m_Timer;

    //地图对象
    Map m_map;

    //绘制只因哥
    Kun m_hero;

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
};

#endif // MAINSCENE_H
