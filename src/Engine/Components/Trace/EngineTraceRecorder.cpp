#include "EngineTraceRecorder.h"

#include "Application/GameKeyboardController.h" // TODO(captainurist): Engine -> Application dependency

#include "Engine/Engine.h"
#include "Engine/Components/Control/EngineController.h"
#include "Engine/Components/Control/EngineControlComponent.h"
#include "Engine/Components/Deterministic/EngineDeterministicComponent.h"

#include "Library/Application/PlatformApplication.h"
#include "Library/Trace/EventTrace.h"

#include "EngineTraceComponent.h"
#include "EngineTraceConfigurator.h"

EngineTraceRecorder::EngineTraceRecorder() {}

EngineTraceRecorder::~EngineTraceRecorder() {
    assert(!application()); // We're uninstalled.
}

void EngineTraceRecorder::startRecording(EngineController *game, const std::string &savePath, const std::string &tracePath) {
    assert(!isRecording());

    _trace = std::make_unique<EventTrace>();
    _saveFilePath = savePath;
    _traceFilePath = tracePath;

    game->resizeWindow(640, 480);
    game->tick();

    _trace->header.config = EngineTraceConfigurator::makeConfigPatch(engine->config.get());

    _oldFpsLimit = engine->config->graphics.FPSLimit.value();
    engine->config->graphics.FPSLimit.setValue(1000); // Load game real quick!
    game->saveGame(savePath);
    _deterministicComponent->enterDeterministicMode();
    game->loadGame(savePath);
    _deterministicComponent->resetDeterministicState();
    _keyboardController->reset(); // Reset all pressed buttons.

    _traceComponent->start();
    engine->config->graphics.FPSLimit.setValue(EngineDeterministicComponent::TARGET_FPS); // But don't turn the party into a wall-running doomguy.

    logger->info("Tracing started.");
}

void EngineTraceRecorder::finishRecording(EngineController *game) {
    assert(isRecording());

    _deterministicComponent->leaveDeterministicMode();
    engine->config->graphics.FPSLimit.setValue(_oldFpsLimit);

    _trace->events = _traceComponent->finish();
    _trace->header.saveFileSize = std::filesystem::file_size(_saveFilePath); // This function can throw.
    EventTrace::saveToFile(_traceFilePath, *_trace);

    logger->info("Trace saved to {} and {}",
                 absolute(std::filesystem::path(_saveFilePath)).generic_string(),
                 absolute(std::filesystem::path(_traceFilePath)).generic_string());

    _trace.reset();
    _traceFilePath.clear();
    _saveFilePath.clear();
}

void EngineTraceRecorder::installNotify() {
    _traceComponent = application()->get<EngineTraceComponent>();
    _deterministicComponent = application()->get<EngineDeterministicComponent>();
    _keyboardController = application()->get<GameKeyboardController>();
}

void EngineTraceRecorder::removeNotify() {
    _traceComponent = nullptr;
    _deterministicComponent = nullptr;
    _keyboardController = nullptr;
}


