#pragma once

#include <string>
#include <vector>

#include "platform.h"

namespace bscan {

  class Battery {
    friend std::vector<Battery> getAllBatteries();

   public:
    explicit Battery(int8_t id = 0);
    ~Battery() = default;

    std::string& vendor();
    std::string& model();
    std::string& serialNumber();
    std::string& technology();
    uint32_t energyFull();

    double capacity();

    [[nodiscard]] std::string getVendor() const;
    [[nodiscard]] std::string getModel() const;
    [[nodiscard]] std::string getSerialNumber() const;
    [[nodiscard]] std::string getTechnology() const;
    [[nodiscard]] uint32_t getEnergyFull() const;

    [[nodiscard]] uint32_t energyNow() const;
    [[nodiscard]] bool charging() const;
    [[nodiscard]] bool discharging() const;

   private:
    int8_t _id = -1;
    std::string _vendor;
    std::string _model;
    std::string _serialNumber;
    std::string _technology;
    uint32_t _energyFull = 0;
  };

std::vector<Battery> getAllBatteries();

};
