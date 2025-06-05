clinux:
	clang++ src/main/main.cpp -o jocoa-py -std=c++17
	sudo rm -rf /usr/local/bin/jocoa-py-src
	sudo mkdir -p /usr/local/bin/jocoa-py-src
	sudo mv jocoa-py /usr/local/bin
	sudo cp src/main/*.py /usr/local/bin/jocoa-py-src