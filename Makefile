EXE_TEST_RR = testrr
EXE_TEST_SQ = testStackQueue

OBJS_UTILS = RGBAPixel.o lodepng.o PNG.o
OBJS_TEST_RR = $(OBJS_UTILS) rr.o testrr.o
OBJS_TEST_SQ = testStackQueue.o
SRC_SQ = stack.h stack.cpp queue.h queue.cpp

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
#LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lpthread -lm
LDFLAGS = -std=c++1y -stdlib=libc++ -lpthread -lm

all : $(EXE_TEST_RR) $(EXE_TEST_SQ)

$(EXE_TEST_RR) : $(OBJS_TEST_RR)
	$(LD) $(OBJS_TEST_RR) $(LDFLAGS) -o $(EXE_TEST_RR)

$(EXE_TEST_SQ) : $(OBJS_TEST_SQ)
	$(LD) $(OBJS_TEST_SQ) $(LDFLAGS) -o $(EXE_TEST_SQ)

#object files
RGBAPixel.o : cs221util/RGBAPixel.cpp cs221util/RGBAPixel.h
	$(CXX) $(CXXFLAGS) cs221util/RGBAPixel.cpp -o $@

PNG.o : cs221util/PNG.cpp cs221util/PNG.h cs221util/RGBAPixel.h cs221util/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs221util/PNG.cpp -o $@

lodepng.o : cs221util/lodepng/lodepng.cpp cs221util/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs221util/lodepng/lodepng.cpp -o $@

rr.o : rr.cpp cs221util/RGBAPixel.h cs221util/PNG.h $(SRC_SQ)
	$(CXX) $(CXXFLAGS) $< -o $@

testrr.o : testrr.cpp cs221util/PNG.h cs221util/RGBAPixel.h
	$(CXX) $(CXXFLAGS) $< -o $@

testStackQueue.o : testStackQueue.cpp $(SRC_SQ)
	$(CXX) $(CXXFLAGS) $< -o $@

clean :
	-rm -f *.o $(EXE_TEST_RR) $(EXE_TEST_SQ)
