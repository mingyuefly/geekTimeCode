//
//  Student.cpp
//  graph
//
//  Created by Gguomingyue on 2019/2/22.
//  Copyright © 2019 Gmingyue. All rights reserved.
//


#include "Student.hpp"
using namespace std;

Student::Student(){
    cout << "default Student()" << endl;
}

Student::Student(string nameS, int chineseScoreS, int mathsScoreS, int englishScoreS){
    name = nameS;
    chineseScore = chineseScoreS;
    mathsScore = mathsScoreS;
    englishScore = englishScoreS;
}

Student::~Student(){
    cout << "~Student()" << endl;
}

void Student::show(){
    cout << "name:" << name << endl;
    cout << "chineseScore" << chineseScore << endl;
    cout << "mathsScore" << mathsScore << endl;
    cout << "englishScore" << englishScore << endl;
}
