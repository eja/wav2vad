// Copyright (c) 2024 Ubaldo Porcheddu <ubaldo@eja.it>

#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "onnxruntime_cxx_api.h"
#include "onnx_model_loader.h"
#include "silero_vad.h"
#include "wav.h"


void print_timestamp(float start, float end, float rate, bool comma) {
  printf(" {");
  printf(" \"start\": %f,", (start / rate));
  printf(" \"end\": %f", (end / rate));
  printf("}");
  if (comma) {
    printf(",");
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <wav_file>\n", argv[0]);
    return 1;
  }

  std::string wav_file = argv[1];
  std::vector<timestamp_t> stamps;

  wav::WavReader wav_reader(wav_file);
  std::vector<float> input_wav(wav_reader.num_samples());

  for (int i = 0; i < wav_reader.num_samples(); i++) {
    input_wav[i] = static_cast<float>(*(wav_reader.data() + i));
  }

  VadIterator vad;
  vad.process(input_wav);

  printf("[\n");
  stamps = vad.get_speech_timestamps();
  for (int i = 0; i < stamps.size(); i++) {
    bool comma = true;
    if (i == stamps.size() - 1) {
      comma = false;
    }
    print_timestamp(stamps[i].start, stamps[i].end, wav_reader.sample_rate(),
                    comma);
  }
  printf("]\n");
}

