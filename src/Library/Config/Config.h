#pragma once

#include "ConfigFwd.h"
#include "ConfigSection.h"
#include "ConfigEntry.h"

class Config {
 public:
    Config() = default;
    Config(const Config &other) = delete; // non-copyable
    Config(Config &&other) = delete; // non-movable

    void load(const std::string &path);
    void save(const std::string &path) const;
    void reset();

    void registerSection(ConfigSection *section);

    ConfigSection *section(const std::string &name) const;

    std::vector<ConfigSection *> sections() const;

 private:
    std::map<std::string, ConfigSection *> _sectionByName;
};
