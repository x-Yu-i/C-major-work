
#ifndef CONFIG_H
#define CONFIG_H

/********** 游戏配置数据 **********/
#define GAME_WIDTH 512 //宽度
#define GAME_HEIGHT 768 //高度
#define GAME_TITLE "只因大战我爱罗 v1.0" //标题
#define GAME_RES_PATH "./kun.rcc" //rcc文件路径
#define GAME_ICON ":/res/app.ico"//图标加载路径
#define GAME_RATE 10 //刷新间隔，帧率 单位毫秒

/********** 地图配置数据 **********/
#define MAP_PATH ":/res/img_bg_level_2.jpg" //地图图片路径
#define MAP_SCROLL_SPEED 2 //地图滚动速度

/********** 只因配置数据 **********/
#define HERO_PATH ":/res/kun.png"

/********** 子弹配置数据 **********/
#define BULLET_PATH ":/res/bullet_12.png" //子弹图片路径
#define BULLET_SPEED 5 //子弹移动速度
#define BULLET_NUM 30 //弹匣中子弹总数
#define BULLET_INTERVAL 20 //发射子弹时间间隔



#endif // CONFIG_H
