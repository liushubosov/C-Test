#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define abs(b) b<0?-b:b;

struct Point
{
	int x;
	int y;
	Point() {
		x = 0;
		y = 0;
	}

	Point(int a, int b) {
		x = a;
		y = b;
	}

};

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		if (points.size() == 0)
			return 0;
		
		int nMax = 0;
		for (int i = 0; i < points.size(); i++)
		{
			map<float, int>  results;
			Point base = points[i];
			int nBase = 0;
			int nLineMax = 0;
			for (int j = i + 1; j < points.size(); j++)
			{
				if (points[j].y == base.y && points[j].x == base.x)
				{
					nBase++;
					continue;
				}
				float a = points[j].y - base.y;
				float b = points[j].x - base.x;
				float k = 0;
				if (b != 0)
					k = a / b;
				map<float, int>::iterator iter1;
				iter1 = results.find(k);
				// no key
				if (iter1 == results.end())
				{
					pair<float, int> value(k, 1);
					results.insert(value);
					if (nLineMax < 1)
						nLineMax = 1;
				}
				else
				{
					iter1->second++;
					if (iter1->second > nLineMax)
						nLineMax = iter1->second;
				}
			}
			nLineMax = nLineMax + 1 + nBase;
			if (nLineMax > nMax)
				nMax = nLineMax;
		}
		//nMax = nMax + 1 + nBase;
		return nMax;
	}
};

int main()
{
	cout << "hello" << endl;
	Solution solut;
	vector<Point> points;
	Point p1, p2, p3, p4, p5;
	p1.x = -4;
	p1.y = -4;
	p2.x = -8;
	p2.y = -582;
	p3.x = -3;
	p3.y = 3;
	p4.x = -9;
	p4.y = -651;
	p5.x = 9;
	p5.y = 591;
	points.push_back(p1);
	//points.push_back(p2);
	//points.push_back(p3);
	//points.push_back(p4);
	//points.push_back(p5);
	int nMax = solut.maxPoints(points);
	cout << "max value = " << nMax << endl;

	//double fV = 0.0;
	//fV = 1.0 / 3.0;
	//cout << fV << endl;

	//遍历 map， 找出最大值


	system("pause");
    return 0;
}

