#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define abs(b) b<0?-b:b;

struct Point
{
    int x;
    int y;
    Point(){
        x = 0;
        y = 0;
    }

    Point(int a, int b){
        x = a;
        y = b;
    }

};

class Solution
{
public:
    int doSomething(vector<Point> &points)
    {
        Point base = points[0];
        vector<float> results;
        for(int i=1;i < points.size();i++)
        {
            float k = (points[i].y - base.y) / (points[i].x - base.x);
            results.push_back(abs(k));
        }

        return 0;
    }
};

int main()
{
    cout << "hello" << endl;
    return 0;
}