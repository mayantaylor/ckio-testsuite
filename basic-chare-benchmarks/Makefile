MODULE = reader

CI_FILE = $(MODULE).ci
CPP_FILE = $(MODULE).cpp
HEADERS = $(MODULE).decl.h $(MODULE).def.h
EXEC = $(MODULE)

$(EXEC): $(CPP_FILE) $(HEADERS)
	charmc -o $@ $<

proj: $(CPP_FILE) $(HEADERS)
	charmc -o $@ $< -tracemode projections

$(HEADERS): $(CI_FILE)
	charmc $^

clean:
	rm -f charmrun $(HEADERS) $(EXEC) slurm-tools/reader-*.slurm 
