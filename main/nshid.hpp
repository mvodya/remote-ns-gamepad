/**
 * @file nshid.hpp
 * @brief Gamepad USB HID component
 *
 * The component initializes Nintendo Switch-compatible gamepad HID descriptors and provides
 * an interface for sending HID reports
 *
 * (с) 2025-2026, Mark Vodyanitskiy (mvodya@icloud.com)
 */

#pragma once

#include "esp_err.h"

namespace HID {

// HID device report
typedef struct __attribute__((packed, aligned(1))) {
  // === [Button Input: 14 buttons] ===
  uint16_t buttons;
  // === [D-Pad: Hat switch] ===
  uint8_t dPad;

  // === [Analog sticks: X/Y/Z/Rz axes] ===
  uint8_t leftXAxis;
  uint8_t leftYAxis;
  uint8_t rightXAxis;
  uint8_t rightYAxis;

  uint8_t filler;
} Report;

// Setup USB descriptors & initialize USB stack
esp_err_t init();

// Start task for HID handler
esp_err_t startTask();

// Set HID device report
// Thread-safe. Blocks until report is sended
esp_err_t setReport(const Report& report);

// Get gamepad state
// Thread-safe
bool isGamepadConnected();

// Register console commands
esp_err_t cmdsRegister();

} // namespace HID