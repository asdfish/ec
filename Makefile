CXX ?= c++
CXX_FLAGS := -std=c++17 $\
							   -Wall -Wextra $\
								 -O2 -march=native -pipe $\
								 -Iinclude

PROCESSED_HEADER_FILES := $(subst .hpp,$\
														$(if $(findstring clang++,${CXX}),$\
															.hpp.pch,$\
															.hpp.gch),$\
														$(shell find -name '*.hpp'))

OBJECT_FILES := $(patsubst ./src/%.cpp,$\
									build/%.o,$\
									$(shell find -name '*.cpp'))

INSTALL_DIRECTORY := /usr/local/bin/

define REMOVE_LIST
	$(foreach ITEM,$\
		$(1),$\
		$(if $(wildcard ${ITEM}),$\
			$(shell rm ${ITEM})))

endef

all: ec

%.gch: %
	${CXX} -c $< ${CXX_FLAGS}
%.pch: %
	${CXX} -c $< ${CXX_FLAGS}

build/main.o: config.hpp

build/%.o: src/%.cpp
	${CXX} -c $< ${CXX_FLAGS} -o $@

ec: ${PROCESSED_HEADER_FILES} ${OBJECT_FILES}
	${CXX} ${OBJECT_FILES} -o ec

clean:
	$(call REMOVE_LIST,$\
		${OBJECT_FILES})
	$(call REMOVE_LIST,$\
		${PROCESSED_HEADER_FILES})
ifneq (,$(wildcard ec))
	rm ec
endif

install: all ${INSTALL_DIRECTORY} uninstall
	cp ec ${INSTALL_DIRECTORY}

uninstall:
ifneq (,$(wildcard ${INSTALL_DIRECTORY}/ec))
	rm ${INSTALL_DIRECTORY}/ec
endif

.PHONY: all clean install uninstall
