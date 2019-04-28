//
//  Student.hpp
//  graph
//
//  Created by Gguomingyue on 2019/2/22.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Student{
private:
    string name;
    int chineseScore;
    int mathsScore;
    int englishScore;
public:
    Student();
    Student(string nameS, int chineseScoreS, int mathsScoreS, int englishScoreS);
    ~Student();
    void show();
};

#endif /* Student_hpp */
