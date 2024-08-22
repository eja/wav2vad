CC = g++
LDLIBS = -lonnxruntime
CFLAGS = -I./onnxruntime-linux-x64-static_lib-1.19.0-glibc2_17/include/
LDFLAGS = -L./onnxruntime-linux-x64-static_lib-1.19.0-glibc2_17/lib

all: wav2vad

wav2vad: wav2vad.cpp
	$(CC) $^ -o $@ $(LDLIBS)

static:
	#https://github.com/csukuangfj/onnxruntime-libs
	$(CC) wav2vad.cpp $(CFLAGS) $(LDFLAGS) $(LDLIBS) -static -o wav2vad
	strip wav2vad

clean:
	rm -f wav2vad

install: wav2vad
	cp wav2vad /usr/local/bin/

uninstall:
	rm /usr/local/bin/wav2vad
