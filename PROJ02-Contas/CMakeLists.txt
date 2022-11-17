project ("Contas")

file(GLOB SOURCES
    ./*.h
    ./*.cpp
)

add_executable(${PROJECT_NAME}
	${SOURCES}
)