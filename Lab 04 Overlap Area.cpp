#include <iostream>
#include <algorithm>
using namespace std;
struct Rectangle {
    int x, y; // 左下角坐標
    int w, h; // 長寬
};

bool isOverlapping(const Rectangle &rec1, const Rectangle &rec2);




bool isOverlapping(const Rectangle &rec1, const Rectangle &rec2) {
    return !(rec1.x+rec1.w <= rec2.x || rec1.x >= rec2.x+rec2.w || 
             rec1.y+rec1.h <= rec2.y || rec1.y >= rec2.y+rec2.h);
}

int overlappingArea(const Rectangle &rect1, const Rectangle &rect2) {
    int overlapX1 = max(rect1.x, rect2.x);
    int overlapY1 = max(rect1.y, rect2.y);
    int overlapX2 = min(rect1.x+rect1.w, rect2.x+rect2.w);
    int overlapY2 = min(rect1.y+rect1.h, rect2.y+rect2.h);

    if (overlapX1 < overlapX2 && overlapY1 < overlapY2) {
        return (overlapX2 - overlapX1) * (overlapY2 - overlapY1);
    } else {
        return 0; // 沒有重疊
    }
}


Rectangle boundingRectangle(const Rectangle &rec1, const Rectangle &rec2) {
    Rectangle bounding;
    bounding.x = min(rec1.x, rec2.x);
    bounding.y = min(rec1.y, rec2.y);
    bounding.w = max(rec1.x+rec1.w, rec2.x+rec2.w)-bounding.x;
    bounding.h = max(rec1.y+rec1.h, rec2.y+rec2.h)-bounding.y;
    return bounding;
}

int main() {
    int choice,n;
    struct Rectangle rec1;
    struct Rectangle rec2;
    cout<<"Enter the number of test cases: ";
    cin>>n;
    
    
    for (int i=0;i<n;i++) {
  cout<<"Enter Rectangle 1 (x y w h): ";
  cin>>rec1.x>>rec1.y>>rec1.w>>rec1.h;
  cout<<"Enter Rectangle 2 (x y w h): ";
  cin>>rec2.x>>rec2.y>>rec2.w>>rec2.h;
  cout<<"Select operation (1: Overlap, 2: Intersection Area, 3: Total Area, 4: Bounding Box): ";
  cin>>choice;    

        switch (choice) {
            case 1: 
                if (isOverlapping(rec1,rec2)) {
                  cout<<"Rectangles overlap"<<endl;
                }
                else{
                	cout<<"No overlap"<<endl;
			}
                break;
            
            case 2: {
                cout<<"Intersection area = "<<overlappingArea(rec1,rec2)<<endl;
                break;
            }
            case 3: {
                
                cout<<"Total area = "<<rec1.w*rec1.h+rec2.w*rec2.h-overlappingArea(rec1,rec2)<<endl;
                break;
            }
            case 4: {
                
                struct Rectangle bounding = boundingRectangle(rec1, rec2);
                cout<<"Bounding Box (x y w h): "<<bounding.x<<" "<<bounding.y<<" "<<bounding.w<<" "<<bounding.h<<endl;
                break;
            }
            
        }
    }
    return 0;
}

   
