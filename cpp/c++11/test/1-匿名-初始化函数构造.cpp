#include <iostream>
#include <vector>

// 匿名初始化构造  聚合初始化 给 逐个赋值简化    减少了出错的机会
#include <initializer_list> 

class BoVector {
   std::vector<int> m_vec;
   public:
   BoVector(const std::initializer_list<int>& v) {
      for (std::initializer_list<int>::iterator itr = v.begin(); itr!=v.end(); ++ itr)
         m_vec.push_back(*itr);
   }
};

BoVector v = {0, 2, 3, 4};
BoVector v1{0, 2, 3, 4};   // effectively the same

// Automatic normal Initialization
class Rectangle {
   public:
   Rectangle(int height, int width, int length){ }
};

void draw_rect(Rectangle r){};

int main() {
    // 匿名函数构造调用
   draw_rect({5, 6, 9});  // Rectangle{5,6,9} is automatically called
}

