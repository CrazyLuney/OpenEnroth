#pragma once

#include <memory>
#include <queue>

#include "Platform/Proxy/ProxyEventLoop.h"

#include "TestStateHandle.h"

class PlatformWindow;
class PlatformEvent;

class TestEventLoop: public ProxyEventLoop {
 public:
    TestEventLoop(std::unique_ptr<PlatformEventLoop> base, TestStateHandle state);
    virtual ~TestEventLoop();

    virtual void Exec(PlatformEventHandler *eventHandler) override;
    virtual void ProcessMessages(PlatformEventHandler *eventHandler, int count = -1) override;

    void PostEvent(PlatformWindow *window, std::unique_ptr<PlatformEvent> event);

 private:
    void ProcessSyntheticMessages(PlatformEventHandler *eventHandler);

 private:
    struct PostedEvent {
        PlatformWindow *window;
        std::unique_ptr<PlatformEvent> event;
    };

 private:
    std::queue<PostedEvent> postedEvents_;
    std::unique_ptr<PlatformEventHandler> emptyHandler_;
    std::unique_ptr<PlatformEventLoop> base_;
    TestStateHandle state_;
};
