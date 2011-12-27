ALGS=../algorithms
ALGS_LIB=$(ALGS)/lib
ALGS_INC=$(ALGS)/include
TEST_BIN=bin

build:
	gcc -Wall test_string_utils.c $(ALGS_LIB)/*.c -I$(ALGS_INC) -g -lcheck -o $(TEST_BIN)/test_string_utils.o
	gcc -Wall test_array_utils.c $(ALGS_LIB)/*.c -I$(ALGS_INC) -g -lcheck -o $(TEST_BIN)/test_array_utils.o
	gcc -Wall test_math_utils.c $(ALGS_LIB)/*.c -I$(ALGS_INC) -g -lcheck -o $(TEST_BIN)/test_math_utils.o
	gcc -Wall main.c $(ALGS_LIB)/*.c -I$(ALGS_INC) -g -o $(TEST_BIN)/main.o

test:
	@for i in `echo $(TEST_BIN)/*`; do (./$$i) done
