BUILD_DIR = build
EXECUTABLE = minimal_list_test

all: $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..


.phony: test
test: $(BUILD_DIR)
	cd $(BUILD_DIR) && ctest

clean:
	rm -rf $(BUILD_DIR)
