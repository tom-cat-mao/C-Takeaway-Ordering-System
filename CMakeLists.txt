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
    folder_c_c_d.c
    Search_Classify_in_Merchant.c
    password_change.c
    main.c
    Search_Classify_in_Merchant.c
    Manager.c
    delete_node.c
        Search_Recipe_in_Class.c
        find_free_deliver.c
        set_order_state.c
        find_account_in_the_list.c
)

# Add your header files here
set(HEADERS
    class.h
    mergeSortRecipe.h
    output_recipe_price_range.h
    classTree.h
    folder_create_change_delete.h
    wordcolour.h
    sale_recipe.h
    mergeSortOrder.h
    interface.h
    SearchFuzzy&SaleRecipe.h
    setStar_recipe.h
    dirent.h
)

# Add executable target
add_executable(MyProject ${SOURCES} ${HEADERS})