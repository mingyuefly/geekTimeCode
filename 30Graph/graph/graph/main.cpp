//
//  main.cpp
//  graph
//
//  Created by Gguomingyue on 2019/2/21.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>


#include "Student.hpp"
#include "LinkedList.hpp"


using namespace std;

#define MAXVEX 10
#define INFINITY 0XFFFFFFFF
#define SUCCESS 1
#define UNSUCCESS 0





int main(int argc, const char * argv[]) {
    
    
    
    Student *stu1 = new Student("Jack", 98, 99, 100);
    Student *stu2 = new Student("Sam", 99, 90, 99);
    Student *stu3 = new Student("Sue", 97, 99, 87);
    
    //stu1->show();
    //stu2->show();
    //stu3->show();
    
    LinkedList * list = new LinkedList();

    list->add(stu1);
    list->add(stu2);
    list->add(stu3);

    for(int i=0; i<list->size(); i++){
        list->get(i)->show();
    }

    delete list;
    
    return 0;
}
