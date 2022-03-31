
CXX = g++

CFLAGS = -I.
CFLAGS += -Ithird_party/eigen
CFLAGS += -I/opt/intel/oneapi/mkl/2022.0.0/include

CFLAGS += -fPIC -O0

LFLAGS = -lm -ldl -m64 -lpthread
LFLAGS += -L/opt/intel/oneapi/mkl/2022.0.0/lib/ -lmkl_rt
LFLAGS +=-Wl,-rpath,/opt/intel/oneapi/mkl/2022.0.0/lib
LFLAGS +=-Wl,-rpath,/opt/intel/oneapi/compiler/2022.0.0/mac/compiler/lib/

PXML_OBJS = $(subst .cc,.o,$(wildcard pxml/*.cc))
PXML_OBJS += $(subst .cc,.o,$(wildcard pxml/*/*.cc))
PXML_OBJS += $(subst .cc,.o,$(wildcard pxml/*/*/*.cc))
PXML_OBJS += $(subst .cc,.o,$(wildcard pxml/*/*/*/*.cc))

TDEP_OBJS = $(PXML_OBJS)

TEST_OBJS = $(subst .cc,.o,$(wildcard test/*.cc))
TEST_OBJS += $(subst .cc,.o,$(wildcard test/*/*.cc))
TEST_OBJS += $(subst .cc,.o,$(wildcard test/*/*/*.cc))
TEST_OBJS += $(subst .cc,.o,$(wildcard test/*/*/*/*.cc))

TESTS = $(subst .cc,,$(wildcard test/*.cc))
TESTS += $(subst .cc,,$(wildcard test/*/*.cc))
TESTS += $(subst .cc,,$(wildcard test/*/*/*.cc))
TESTS += $(subst .cc,,$(wildcard test/*/*/*/*.cc))

# TESTS = $(subst .o,,$(wildcard $(TEST_OBJS)))

.DEFAULT_GOAL = pxml

%.o: %.cc $(VERHH)
	@echo [32m"CC "[m $(OFLAGS) [33m$<[m
	@$(CXX) $(CFLAGS) $(OFLAGS) -o $@ -c $<

test/%: $(TDEP_OBJS) test/%.o
	@echo [31mBIN[m "   " [33m$@[m
	$(CXX) $^ $(LFLAGS) -o $@

tests: $(TESTS) $(TDEP_OBJS)
	@echo $(TESTS)
	@echo $(TEST_OBJS)

pxml_static: $(PXML_OBJS)
	@echo "pxml_static"

pxml_shared: $(PXML_OBJS)
	@echo "pxml_shared"

pxml: pxml_static pxml_shared tests


clean:
	rm $(TEST_OBJS) $(PXML_OBJS) $(TESTS)