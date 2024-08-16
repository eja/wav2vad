CC = g++
LDLIBS = -lonnxruntime

#CFLAGS = -I../onnxruntime-linux-x64-static_lib-1.17.1-gcc-10/include/
#LDFLAGS = -L../onnxruntime-linux-x64-static_lib-1.17.1-gcc-10/lib/

all: wav2vad

wav2vad: wav2vad.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

clean:
	rm -f wav2vad
