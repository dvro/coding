ALGS=../algorithms
ALGS_LIB=$(ALGS)/lib
ALGS_INC=$(ALGS)/include
TEST_BIN=bin

build:
	gcc test_string_utils.c $(ALGS_LIB)/*.c -I$(ALGS_INC) -g -lcheck -o $(TEST_BIN)/test_string_utils.o
	

test:
	@for i in `echo $(TEST_BIN)/*`; do (cd $(TEST_BIN); ./$$i) done
