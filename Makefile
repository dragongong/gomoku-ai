
all:
	@echo "complie ok"

test:
	@echo "test ok"
	
clean:
	@find . -name "*.pyc" -exec rm {} \;
	@find . -name "*.DS_Store" -exec rm {} \;
