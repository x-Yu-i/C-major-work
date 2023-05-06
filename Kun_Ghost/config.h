
#ifndef CONFIG_H
#define CONFIG_H

/********** 游戏配置数据 **********/
#define GAME_WIDTH 512 //宽度
#define GAME_HEIGHT 768 //高度
#define GAME_TITLE "只因大战我爱罗 v1.0" //标题
#define GAME_RES_PATH "./kun.rcc" //rcc文件路径
#define GAME_ICON ":/res/app.ico"//图标加载路径
#define GAME_RATE 10 //刷新间隔，帧率 单位毫秒
#define GAME_OVER ""//游戏结束图片

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

/********** 我爱罗配置数据 **********/
#define ENEMY_PATH ":/res/Ghost.png" //敌机资源图片
#define ENEMY_SPEED 3 //敌机移动速度
#define ENEMY_NUM 20 //敌机总数量
#define ENEMY_INTERVAL 30 //敌机出场时间间隔

/********** 爆炸配置数据 **********/
#define BOMB_PATH ":/res/bomb-%1.png" //爆炸资源图片
#define BOMB_NUM 20 //爆炸数量
#define BOMB_MAX 7 //爆炸图片最大索引
#define BOMB_INTERVAL 20 //爆炸切图时间间隔

/********** 我爱罗子弹配置数据 **********/
#define GHOST_BULLET_PATH ":/res/bullet_3.png" //子弹图片路径
#define GHOST_BULLET_SPEED 5 //子弹移动速度
#define GHOST_BULLET_NUM 50 //弹匣中子弹总数
#define GHOST_BULLET_INTERVAL 80 //发射子弹时间间隔

#endif // CONFIG_H
