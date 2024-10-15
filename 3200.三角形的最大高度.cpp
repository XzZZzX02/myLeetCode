/*
 * @lc app=leetcode.cn id=3200 lang=cpp
 *
 * [3200] 三角形的最大高度
 */
#include "leetcode.h"
// @lc code=start
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int heightRed = 0;
        int heightBlue = 0;
        bool useRed = true;
        int red_2 = red;
        int blue_2 = blue;
        while (true) {
            int neededBalls = heightRed + 1;
            if (useRed) {
                if (red < neededBalls) {
                    break;
                }
                heightRed++;
                red -= neededBalls;
            } else {
                if (blue < neededBalls) {
                    break;
                }
                heightRed++;
                blue -= neededBalls;
            }
            useRed = !useRed;
        }
        useRed = false;
        while (true) {
            int neededBalls = heightBlue + 1;
            if (useRed) {
                if (red_2 < neededBalls) {
                    break;
                }
                heightBlue++;
                red_2 -= neededBalls;
            } else {
                if (blue_2 < neededBalls) {
                    break;
                }
                heightBlue++;
                blue_2 -= neededBalls;
            }
            useRed = !useRed;
        }
        return max(heightRed, heightBlue);
    }
};
// @lc code=end

