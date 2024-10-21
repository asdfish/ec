CXX ?= c++

CXX_FLAGS := -std=c++17 $\
							   -Wall -Wextra $\
								 -O2 -march=native -pipe $\
								 -Iinclude

DIRECTORIES := build build/display build/information build/information/argumentless
OBJECT_FILES := build/utils.o $\
								build/display/display_base.o build/display/list.o $\
								build/information/file_extension_rules.o build/information/file_permissions.o build/information/file_size.o build/information/file_type.o build/information/text.o $\
								build/information/argumentless/argumentless_base.o build/information/argumentless/file_extension.o build/information/argumentless/file_name.o build/information/argumentless/relative_path.o

INSTALL_DIRECTORY := /usr/local/bin

all: ec

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
build/main.o: config.hpp src/main.cpp
	${CXX} -c src/main.cpp ${CXX_FLAGS} -o build/main.o

ec: ${DIRECTORIES} ${OBJECT_FILES} build/main.o
	${CXX} ${OBJECT_FILES} build/main.o -o ec
	strip ec

install: ec ${INSTALL_DIRECTORY}
	-cp -f ec ${INSTALL_DIRECTORY}

uninstall:
	-rm -f ${INSTALL_DIRECTORY}/ec

.phony: all clean install uninstall
