CXX ?= c++
CXXFLAGS ?= -O2 -march=native -pipe
COMMONFLAGS := -std=c++17 $\
							 -Wall -Wextra $\
							 -Iinclude

# Comment/uncomment to enable/disable processing header files
PROCESS_HEADER_FILES := yes
PROCESSED_HEADER_FILES := $(if ${PROCESS_HEADER_FILES},$\
														$(subst .hpp,$\
															$(if $(findstring clang++,${CXX}),$\
																.hpp.pch,$\
																.hpp.gch),$\
															$(shell find -name '*.hpp')))

OBJECT_FILES := $(patsubst ./src/%.cpp,$\
									build/%.o,$\
									$(shell find -name '*.cpp'))

INSTALL_DIRECTORY := /usr/local/bin/

EC_REQUIREMENTS := ${PROCESSED_HEADER_FILES} ${OBJECT_FILES}

define COMPILE
${CXX} -c $(1) ${CXXFLAGS} ${COMMONFLAGS} -o $(2)

endef
define REMOVE
$(if $(wildcard $(1)),$\
	rm $(1))

endef
define REMOVE_LIST
	$(foreach ITEM,$\
		$(1),$\
		$(call REMOVE,${ITEM}))

endef

all: ec

%.gch: %
	$(call COMPILE,$<,$@)
%.pch: %
	$(call COMPILE,$<,$@)

build/main.o: config.hpp

build/%.o: src/%.cpp
	$(call COMPILE,$<,$@)

ec: ${EC_REQUIREMENTS}
	${CXX} ${OBJECT_FILES} ${CXXFLAGS} ${COMMONFLAGS} -o ec

clean:
	$(call REMOVE_LIST,${EC_REQUIREMENTS})

install: all ${INSTALL_DIRECTORY} uninstall
	cp ec ${INSTALL_DIRECTORY}

uninstall:
ifneq (,$(wildcard ${INSTALL_DIRECTORY}/ec))
	rm ${INSTALL_DIRECTORY}/ec
endif

.PHONY: all clean install uninstall
