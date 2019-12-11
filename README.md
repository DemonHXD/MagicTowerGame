### 游戏截图

![游戏开始界面](https://raw.githubusercontent.com/DemonHXD/MagicTowerGame/master/StartInterface.png)
![游戏主界面](https://github.com/DemonHXD/MagicTowerGame/blob/master/GameMainInterface.png?raw=true)
![游戏战斗界面](https://github.com/DemonHXD/MagicTowerGame/blob/master/CombatInterface.png?raw=true)

### 魔塔小游戏
之前完成了魔塔小游戏的一部分功能
+ 英雄及怪兽的属性(使用结构体完成)
+ 游戏初始化(就是从文件读取地图和英雄属性)
+ 打印地图(这里没有使用图像库，只是单纯的使用print函数进行打印)
+ 英雄的移动(这里英雄的移动和推箱子的移动逻辑代码类似)
+ 战斗(只有在战斗时候才会初始化怪兽，从文件读取相应怪兽的属性)
+ 打印战斗信息(这个是在左侧，可以显示英雄和怪兽的战斗属性)
+ 升级(这里英雄升级可以加一些属性)
#### 2019-12-9
进行了一些功能的修改
+ 完善了开始新的游戏和读取回忆的功能

```!
1.现在还有一个BUG就是打印战斗信息的时候，怪兽已经死亡了，但是还在接着打印。跟奇怪的BUG
2.暂时只做了一个地图，下一步打算多做几个地图
```

#### 2019-12-11
+ 把之前的C语言版本的代码全部重构，改成了C++版本的代码
+ 重构后的代码，逻辑更清晰。各个类分工明确，耦合降低
+ 新增了一个地图，一个工具类
+ 以后的代码迭代只更新C++版本的魔塔