MODULE = mini

CI_FILE = $(MODULE).ci
CPP_FILE = $(MODULE).cpp
HEADERS = $(MODULE).decl.h $(MODULE).def.h
EXEC = $(MODULE)

$(EXEC): $(CPP_FILE) $(HEADERS)
	charmc -o $@ $< -module CkIO #-tracemode projections # -tracemode summary

$(HEADERS): $(CI_FILE)
	charmc $^

clean:
	rm -f charmrun $(HEADERS) $(EXEC) slurm-tools/reader-*.slurm
