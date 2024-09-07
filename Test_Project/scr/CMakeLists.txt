# Adiciona o arquivo main.c ao executável final do programa
add_executable(output ${CMAKE_CURRENT_SOURCE_DIR}/main.c)

#Vincula a biblioteca
target_link_libraries(output UTILSC)
target_link_libraries(output CBOOKC)
target_link_libraries(output BINOMIOC)

#Define o diretório de saída para o executável
set_target_properties(output PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
