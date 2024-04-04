cmake_minimum_required(VERSION 3.10) # 设置CMake的最小版本要求
project(Myproject) # 设置项目名称

include_directories(.) # 添加头文件路径

add_executable(printList.c searchTree.c createList.c createTree.c deleteTree.c delete_data.c discount_card_change.c insertTree.c)