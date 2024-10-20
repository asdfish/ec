CXX := clang++

CXX_FLAGS := -std=c++20 $\
							   -Wall -Wextra -Wpedantic $\
								 -O2 -march=native -pipe $\
								 -Iinclude
LD_FLAGS :=

DIRECTORIES := build build/information build/information/argumentless
OBJECT_FILES := build/main.o $\
								build/information/file_extension_rules.o build/information/file_permissions.o build/information/file_type.o build/information/text.o $\
								build/information/argumentless/argumentless_base.o build/information/argumentless/file_extension.o build/information/argumentless/file_name.o build/information/argumentless/relative_path.o $\
								build/utils.o

all: dc

${DIRECTORIES}:
	$(foreach DIRECTORY,$\
		${DIRECTORIES},$\
		$(shell mkdir ${DIRECTORY})$\
	)

clean:
	$(foreach DIRECTORY,$\
		${DIRECTORIES},$\
		$(if $(wildcard ${DIRECTORY}),$\
			$(shell rm -rf ${DIRECTORY})$\
		)$\
	)

${OBJECT_FILES}: build/%.o: src/%.cpp
	${CXX} -c $< ${CXX_FLAGS} -o $@

dc: ${DIRECTORIES} ${OBJECT_FILES}
	${CXX} ${OBJECT_FILES} ${LD_FLAGS} -o dc
	strip dc

.phony: all clean
