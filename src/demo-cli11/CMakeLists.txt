set(EXE_NAME "demo-cli11")

find_package(CLI11 CONFIG REQUIRED)

file(GLOB SRC_FILES *.cc)

add_executable(${EXE_NAME} ${SRC_FILES})
target_link_libraries(${EXE_NAME} CLI11::CLI11)

