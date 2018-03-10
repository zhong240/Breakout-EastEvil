//
//  main.cpp
//  BreakoutGame-TX
//
//  Created by Tianxiang Dai on 2/4/18.
//  Copyright © 2018 Tianxiang Dai. All rights reserved.
//

#include <iostream>
#include "../includes/MainProgram.h"

int main(int argc, const char * argv[]) {
    MainProgram::getInstance()->init();
    MainProgram::getInstance()->run();
    return 0;
}
