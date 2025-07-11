.PHONY: build upload clean update monitor tests list_ports envs help

# Default target: Build the project
build:         ## Build the project
	platformio run

upload:        ## Upload to device
	platformio run --target upload

clean:         ## Clean the project
	platformio run --target clean

update:        ## Update PlatformIO packages and platforms
	platformio update

monitor:       ## Open serial monitor
	platformio device monitor

tests:         ## Run PlatformIO tests
	platformio test

list_ports:    ## List available serial ports
	platformio device list

envs:          ## List available PlatformIO environments
	platformio project config list

help:          ## Show this help message
	@echo "Available targets:"
	@grep -E '^[a-zA-Z_-]+:.*?## ' $(MAKEFILE_LIST) | \
	awk 'BEGIN {FS = ":.*?## "}; {printf "  %-12s %s\n", $$1, $$2}'
