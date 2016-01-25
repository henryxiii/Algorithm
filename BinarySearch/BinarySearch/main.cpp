//
//  main.cpp
//  BinarySearch
//
//  Created by Konvie Shaw on 16/1/25.
//  Copyright © 2016年 HenryProperty. All rights reserved.
//


///////////
/*
 二分搜索
 从“有序”序列中查找某个给定的值。
 始终从中间元素开始比较，循环递归。
 如果是则返回；
 否则根据大小，继续向前半部分，或后半部分搜索。
 */


#include <iostream>
#include <vector>


using std::vector;
using std::cout;
using std::cin;
using std::endl;

vector<int> vec;

void binarySearch(int it)
{
    int times = 1;
    auto begin = vec.begin(), end = vec.end();
    auto mid = begin + (end - begin)/2;
    
    while (mid != end  &&  (*mid) != it) {
        times++;
        
        if (it < (*mid))
            end = mid;
        else
            begin = mid;
        
        mid = begin + (end - begin)/2;
    }
    
    if ((*mid) == it)
        cout << "Number " << it <<  " is find after seaching " << times << " times." << endl;
    else
        cout << "Number "<< it << " is NOT in." << endl;
}


int main(int argc, const char * argv[])
{
    cout << "vector 中的元素：" << endl;
    for (int i = 0; i < 24; i+=3)
        vec.push_back(i);
    for (auto iter = vec.cbegin(); iter < vec.cend(); iter++)
        cout << (*iter) << " ";
    
    cout << endl;
    cout << "请输入要搜索的数字：";

    std::string word;
    while (cin >> word)
    {
        bool valid = true;
        for (char c : word)
            if (!isdigit(c)) {
                valid = false;
                cout << "Input invalid!!!!" << endl;
                break;
            }
        
        
        if (valid) {
            int num;
            sscanf(word.c_str(),"%d", &num);
            binarySearch(num);
        }
    }
    

    return 0;
}
