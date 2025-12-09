/* UTF-8 */
/**
 * @file own_navigation.hpp
 * @brief 包含导航类的定义
 */
#ifndef OWN_NAVIGATION_HPP
#define OWN_NAVIGATION_HPP
#include <vector>
#include <iostream>
#include <string>

namespace navigation {
enum class Heading { STOP, UP, DOWN, LEFT, RIGHT };
/**
 * @brief 存储位置信息
 * @details 包括x坐标,y坐标和方向,默认为{0,0,Heading::STOP}
 */
struct Pose2D {
    int x{};
    int y{};
    Heading heading = Heading::STOP;  // 暂停或上下左右方向
    Pose2D() = default;
    Pose2D(int x_, int y_, Heading h = Heading::STOP)
        : x(x_), y(y_), heading(h) {}
};
/**
 * @brief 存储地图
 * @details 包括宽度,高度,地图分辨率(每个网格单元格代表的实际物理尺寸)
 *          和地图信息,以及一个能返回地图面积的函数
 */
struct GridMap {
    int width{};
    int height{};
    double resolution_m{1.0};
    std::vector<std::vector<int>> map;
    int size() const { return width * height; }
};
/**
 * @brief 存储导航目标
 * @details 包括目标位置和地图
 */
struct NavigationGoal {
    Pose2D target_pose{};
    GridMap map{};
};

using Path = std::vector<Pose2D>;

class NavigationPlanner {
public:
    NavigationPlanner() = default;
    virtual ~NavigationPlanner() = default;
    /**
     * @brief 配置导航地图数据
     * @param map 地图网格,其中0表示障碍物,1表示可通行,3表示受困者
     * @return true 配置成功
     * @return false 配置失败
     */
    virtual bool configureMap(const std::vector<std::vector<int>>& map) = 0;
    /**
     * @brief 展示当前地图信息
     */
    virtual void displayMap() const = 0;
    /**
     * @brief 深度优先搜索规划路径
     * @param start 出发位置
     * @param goal 目标位置
     * @return true 能到达目标位置
     * @return false 不能到达目标位置
     */
    virtual bool planPathDFS(const Pose2D& start, const Pose2D& goal) = 0;
    /**
     * @brief 广度优先搜索规划路径
     * @param start 出发位置
     * @param goal 目标位置
     * @return true 能到达目标位置
     * @return false 不能到达目标位置
     */
    virtual bool planPathBFS(const Pose2D& start, const Pose2D& goal) = 0;
    /**
     * @brief 检验位置是否合法
     * @param pose 当前位置
     * @return true 当前位置合法
     * @return false 当前位置不合法
     */
    virtual bool isValidPose(const Pose2D& pose) const = 0;
    /**
     * @brief 前往受困者位置
     * @return true 能成功抵达受困者位置
     * @return false 不能成功抵达受困者位置
     */
    virtual bool move2Victim() const = 0;
    /**
     * @brief 获取规划好的导航路径
     * @return const navigation::Path& 返回路径的常量引用
     */
    const navigation::Path& getNavPath() const { return nav_path; }
    /**
     * @brief 获取当前地图数据
     * @return const navigation::GridMap& 返回地图的常量引用
     */
    const navigation::GridMap& getMap() const { return _map; }

protected:
    GridMap _map;
    Path nav_path;
};
}  // namespace navigation

namespace navigation {

class OwnNavigation : public NavigationPlanner {
public:
    OwnNavigation() {}

    bool configureMap(const std::vector<std::vector<int>>& map) override;
    void displayMap() const override;
    bool planPathDFS(const Pose2D& start, const Pose2D& goal) override;
    bool planPathBFS(const Pose2D& start, const Pose2D& goal) override;
    bool isValidPose(const Pose2D& pose) const override;
    bool move2Victim() const override;

    bool victimMark(int x, int y);
};
}  // namespace navigation
#endif
