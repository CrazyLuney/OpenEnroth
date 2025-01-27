#include "TestController.h"

#include <utility>

#include "Library/Application/PlatformApplication.h"

#include "Engine/Components/Trace/EngineTracePlayer.h"
#include "Engine/Components/Control/EngineController.h"
#include "Engine/Components/Deterministic/EngineDeterministicComponent.h"
#include "Engine/EngineGlobals.h"
#include "Engine/Engine.h"

#include "Application/GameKeyboardController.h"

TestController::TestController(EngineController *controller, const std::string &testDataPath):
    _controller(controller),
    _testDataPath(testDataPath) {}

void TestController::loadGameFromTestData(const std::string &name) {
    _controller->loadGame((_testDataPath / name).string());
}

void TestController::playTraceFromTestData(const std::string &saveName, const std::string &traceName, std::function<void()> postLoadCallback) {
    playTraceFromTestData(saveName, traceName, 0, std::move(postLoadCallback));
}

void TestController::playTraceFromTestData(const std::string &saveName, const std::string &traceName,
                                           EngineTracePlaybackFlags flags, std::function<void()> postLoadCallback) {
    // TODO(captainurist): we need to overhaul our usage of path::string, path::u8string, path::generic_string,
    // pick one, and spell it out explicitly in HACKING
    ::application->get<EngineTracePlayer>()->playTrace(
        _controller,
        (_testDataPath / saveName).string(),
        (_testDataPath / traceName).string(),
        flags,
        std::move(postLoadCallback)
    );
}

void TestController::prepareForNextTest() {
    _controller->goToMainMenu();
    ::application->get<EngineDeterministicComponent>()->resetDeterministicState();
    ::application->get<GameKeyboardController>()->reset();

    engine->config->resetForTest();
}
