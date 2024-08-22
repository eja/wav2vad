# wav2vad

wav2vad is a command-line tool that performs voice activity detection (VAD) on WAV audio files. It utilizes the Silero VAD model and requires the ONNX runtime for inference. The tool processes the input audio file and outputs the detected voice activity occurences in JSON format.

## Requirements

- [ONNX Runtime](https://github.com/microsoft/onnxruntime): Required for running the Silero VAD model.

## Installation

1. **Install ONNX Runtime:**
   - Follow the installation instructions provided in the [ONNX Runtime repository](https://github.com/microsoft/onnxruntime).

2. **Build wav2vad:**
   - Clone this repository:
     ```
     git clone https://github.com/eja/wav2vad.git
     ```
   - Navigate to the cloned directory and build the executable:
     ```
     cd wav2vad
     make
     ```

## Usage

After building the `wav2vad` executable, you can use it to perform voice activity detection on WAV audio files.

Usage: ```./wav2vad <path_of_the_wav_file>```

- `<path_of_the_wav_file>`: Path to the input WAV audio file.


The output will be in JSON format and will contain the detected voice activity time along with confidence scores.

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- This project relies on ONNX Runtime for executing the VAD model.
- This project is based on the Silero VAD example available at [snakers4/silero-vad](https://github.com/snakers4/silero-vad/tree/master/examples/cpp).



