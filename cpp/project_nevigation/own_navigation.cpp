/* UTF-8 */
/**
 * @file own_navigation.cpp
 * @brief 包含导航类的内部函数实现
 */
#include "own_navigation.hpp"
#include <iostream>
#include <queue>

using namespace navigation;
using std::cout;
using std::endl;
using std::vector;

bool OwnNavigation::configureMap(const vector<vector<int>>& map) {
    if (map.empty()) {
        cout << "错误:地图为空" << endl;
        return false;
    }
    _map.map = map;
    _map.width = static_cast<int>(map.size());
    _map.height = static_cast<int>(map[0].size());
    cout << "地图配置成功： ";
    cout << "宽=" << _map.width << ',' << "高=" << _map.height << endl;
    return true;
}
void OwnNavigation::displayMap() const {
    for (int i = 0; i < _map.height; i++) {
        for (int j = 0; j < _map.width; j++) {
            cout << _map.map[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "环境地图生成成功!" << endl;
}
bool OwnNavigation::isValidPose(const Pose2D& pose) const {
    if (pose.x >= 0 && pose.x < _map.width && pose.y >= 0 &&
        pose.y < _map.height && _map.map[pose.x][pose.y] != 0)
        return true;
    return false;
}
bool OwnNavigation::victimMark(int x, int y) {
    Pose2D pose(x, y);
    if (!isValidPose(pose)) {
        cout << "被困者位置输入错误" << endl;
        return false;
    }
    _map.map[x][y] = 3;
    cout << "被困者位置标记成功 " << '(' << x << ", " << y << ')' << endl;
    displayMap();
    cout << "被困者位置设置成功!" << endl;
    return true;
}
bool OwnNavigation::planPathBFS(const Pose2D& start, const Pose2D& goal) {
    Pose2D direction[] = {
        {0, -1, Heading::UP},
        {0, 1, Heading::DOWN},
        {-1, 0, Heading::LEFT},
        {1, 0, Heading::RIGHT}
    };
    std::queue<Pose2D> q;
    q.push(start);
    vector<vector<bool>> visit(_map.height, vector<bool>(_map.width, false));
    vector<vector<Pose2D>> from(_map.height, vector<Pose2D>(_map.width));
    visit[start.y][start.x] = 1;
    bool found = 0;
    while (!q.empty()) {
        Pose2D now = q.front();
        q.pop();
        if (now.x == goal.x && now.y == goal.y) {
            found = 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            Pose2D neighbor(
                now.x + direction[i].x, now.y + direction[i].y,
                direction[i].heading
            );
            if (!isValidPose(neighbor)) continue;
            if (!visit[neighbor.x][neighbor.y]) {
                visit[neighbor.x][neighbor.y] = 1;
                from[neighbor.x][neighbor.y] = now;
                q.push(neighbor);
            }
        }
    }
    if (found) {
        Pose2D now = goal;
        do {
            nav_path.push_back(now);
            now = from[now.x][now.y];
        } while (!(now.x == start.x && now.y == start.y));
        cout << "规划成功!" << endl;
    } else
        cout << "规划失败" << endl;
    return found;
}
bool OwnNavigation::planPathDFS(const Pose2D& start, const Pose2D& goal) {
    (void)start;
    (void)goal;
    cout << "警告:DFS算法未实现,请使用BFS算法" << endl;
    return false;
}
bool OwnNavigation::move2Victim() const {
    if (nav_path.empty()) {
        cout << "错误:未规划路径!" << endl;
        return false;
    }
    cout << "执行导航命令" << endl;
    for (int i = nav_path.size() - 1; i >= 0; i--) {
        cout << "当前位置 " << '(' << nav_path[i].x << ',' << nav_path[i].y
             << ')' << ' ';
    }
    cout << endl;
    cout << "导航成功!" << endl;
    return true;
}