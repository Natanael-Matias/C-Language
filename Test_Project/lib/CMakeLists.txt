add_library(UTILSC Utils.c)
add_library(CBOOKC CBook.c)
add_library(BINOMIOC binomio.c)

target_include_directories(UTILSC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(CBOOKC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_include_directories(BINOMIOC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)