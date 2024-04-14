cmake_minimum_required(VERSION 3.12)
project(MyProject)

# Add your source files here
set(SOURCES
    createTree.c
    createList.c
    delete_data.c
    deleteTree.c
    insertTree.c
    discount_card_change.c
    name_a_pass.c
    printList.c
    searchTree.c
    sum_price.c
    time_set.c
)

# Add your header files here
set(HEADERS
    class.h
    mergeSortRecipe.h
    output_recipe_price_range.h
    classTree.h
)

# Add executable target
add_executable(MyProject ${SOURCES} ${HEADERS})