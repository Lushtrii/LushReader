add_library(lushreader
    pdfreader.cpp
)

target_include_directories(lushreader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(LushReader
    main.cpp
)

target_compile_options(LushReader PRIVATE -Wall -Weffc++ -Wextra -Wconversion
    -Wsign-conversion -Werror)

target_link_libraries(LushReader lushreader)
