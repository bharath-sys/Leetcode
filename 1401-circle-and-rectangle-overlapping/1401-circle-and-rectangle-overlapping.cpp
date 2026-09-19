class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = x2-x1;
        int y = y2-y1;
        pair<int,int> c = {xCenter,yCenter};
        for(int i=0;i<=x;i++){
            pair<int,int> c1 = {x1+i,y1};
            pair<int,int> c2 = {x2-i,y2};
            int d1 = sqrt(pow(c1.first-c.first,2)+pow(c.second-c1.second,2));
            int d2 = sqrt(pow(c2.first-c.first,2)+pow(c.second-c2.second,2));
            if(d1<=radius || d2<=radius)return true;
        }
        for(int j=0;j<=y;j++){
            pair<int,int> c1 = {x1,y1+j};
            pair<int,int> c2 = {x2,y2-j};
            int d1 = sqrt(pow(c1.first-c.first,2)+pow(c.second-c1.second,2));
            int d2 = sqrt(pow(c2.first-c.first,2)+pow(c.second-c2.second,2));
            if(d1<=radius || d2<=radius)return true;
        }
        bool centerInside = ((xCenter>=x1 && yCenter>=y1) && (xCenter<=x2 && yCenter<=y2));
        return centerInside || false;
    }
};