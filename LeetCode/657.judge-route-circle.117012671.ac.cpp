/*
 * [657] Judge Route Circle
 *
 * https://leetcode.com/problems/judge-route-circle/description/
 *
 * algorithms
 * Easy (68.70%)
 * Total Accepted:    49.5K
 * Total Submissions: 72K
 * Testcase Example:  '"UD"'
 *
 * 
 * Initially, there is a Robot at position (0, 0). Given a sequence of its
 * moves, judge if this robot makes a circle, which means it moves back to the
 * original place. 
 * 
 * 
 * 
 * The move sequence is represented by a string. And each move is represent by
 * a character. The valid robot moves are R (Right), L (Left), U (Up) and D
 * (down). The output should be true or false representing whether the robot
 * makes a circle.
 * 
 * 
 * Example 1:
 * 
 * Input: "UD"
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "LL"
 * Output: false
 * 
 * 
 */
class Solution {
public:
    bool judgeCircle(string moves) {
        int lrcount = 0;
        int udcount = 0;
        for (auto x : moves) {
            if (x == 'U')
                udcount++;
            else if ( x == 'D')
                udcount--;
            else if ( x == 'L')
                lrcount++;
            else 
                lrcount--;
        }
        if (lrcount == 0 && udcount == 0)
            return true;
        else 
            return false;
    }
};
