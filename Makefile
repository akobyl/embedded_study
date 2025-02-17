
BUILD_DIR = build

all: $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..


test: $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR) test


clean:
	rm -rf $(BUILD_DIR)
