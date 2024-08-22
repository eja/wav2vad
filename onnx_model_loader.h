#ifndef ONNX_MODEL_LOADER_H
#define ONNX_MODEL_LOADER_H

#include <vector>
#include <stdexcept>
#include <onnxruntime_cxx_api.h>
#include "onnx_model_data.h"

class ONNXModelLoader {
public:
    // Initializes the ONNX model from a byte array
    static std::shared_ptr<Ort::Session> init_onnx_model(const std::vector<uint8_t>& model_data) {
				// Initialize ONNX environment
        static Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "test");

        // Initialize session options
        Ort::SessionOptions session_options;

        // Create the session from the memory array
        Ort::MemoryInfo memory_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeDefault);
        std::shared_ptr<Ort::Session> session;

        // Try to create the session
        try {
            session = std::make_shared<Ort::Session>(env, model_data.data(), model_data.size(), session_options);
        } catch (const Ort::Exception& e) {
            throw std::runtime_error(e.what());
        }

        return session;
    }

private:
    // Disallow creating instances of this class
    ONNXModelLoader() = delete;
    ~ONNXModelLoader() = delete;
};

#endif // ONNX_MODEL_LOADER_H

